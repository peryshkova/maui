/*
Package:  moab
Module:   MXML.c
Version:  3.3.1

Copyright:

  Copyright (C) 1999-2010 Cluster Resources, Inc

  All Rights Reserved

-----------------------------------------------------------------------------
Moab Workload Manager - End User License

This product was created by Cluster Resources, Inc. and is protected by
copyright and patent law.

Copyright (C) 1999-2010 Cluster Resources, Inc., all rights reserved.
Moab Workload Manager, Moab Cluster Scheduler and Moab Scheduler
are trademarks of Cluster Resources, Inc.

This SOFTWARE is bound by an 'End User Subscription License' (LICENSE) from
Cluster Resources Inc.  The conditions of the 'End User Subscription
License' (LICENSE) include, but are not limited to, the conditions described
below.

THE SOFTWARE IS PROVIDED AS IS, AND CLUSTER RESOURCES, INC. (CRI) AND ALL
CONTRIBUTING PARTIES DISCLAIM ALL WARRANTIES RELATING TO THE SOFTWARE,
WHETHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  NEITHER
CRI NOR ANYONE INVOLVED IN THE CREATION, PRODUCTION, OR DELIVERY OF THE
SOFTWARE SHALL BE LIABLE FOR ANY INDIRECT, CONSEQUENTIAL, OR INCIDENTAL
DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE SOFTWARE EVEN IF CRI
HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES OR CLAIMS.  IN NO EVENT
SHALL CRI'S LIABILITY FOR ANY DAMAGES EXCEED THE CONSIDERATION PAID FOR THE
LICENSE TO USE THE SOFTWARE, REGARDLESS OF THE FORM OF CLAIM.  THE PERSON OR
ENTITY USING THE SOFTWARE BEARS ALL RISK AS TO THE QUALITY AND PERFORMANCE
OF THE SOFTWARE.

By installing or using this SOFTWARE you are accepting a non-exclusive 'End
User Subscription License' (LICENSE) from Cluster Resources Inc. and are
bound to abide by the following conditions:

1.  Inclusion of Notice and Disclaimer

  All copies of the SOFTWARE, whether or not for redistribution and whether
or not in source code or in binary form must include a conspicuous and
appropriate publication of the above copyright notice and disclaimer.

2. Usage

  Binary forms of this SOFTWARE may be used by any 'End User' organization
pursuant to the conditions of this and other associated LICENSES for the
duration of the subscription license granted.  An 'End User' organization is
defined as an organization that is using this SOFTWARE on their own systems
and is not commercially redistributing, modifying, supporting, or providing
other services specific to this SOFTWARE to other organizations for profit.

3.  Modifications

  'End User' may solicit the services of Cluster Resources Inc. of Cluster
Resources Inc. to modify or provide services for this SOFTWARE. Available
services include but are not limited to technical support, training,
consultation or optimization services. Any unauthorized partner that desires
to become an 'Authorized Distribution and Services Partner' of Cluster
Resources, Inc. may contact us at support.com.  'End User'
organizations that desire services from Cluster Resources Inc., or an
'Authorized Distribution and Services Partner' may contact us using the same
email listed above.

4.  Distribution

  No redistribution of this product is permitted without express prior
written permission.

5. Communications about and Endorsement of SOFTWARE and Products/Software
Derived from the SOFTWARE

  The name 'Moab Scheduling System', 'Moab Cluster Scheduler', 'Moab Scheduler',
'Moab Workload Manager' or any of its variants must not otherwise be used to
endorse or to promote products derived from the SOFTWARE without prior written
permission from CRI.

  Products derived from or incorporating the SOFTWARE in whole or in part
shall not contain as part of the product's name any form of the terms 'Cluster
Resources, Inc.', 'CRI', 'Moab', 'Moab Scheduling System', 'Moab Cluster
Scheduler', 'Moab Scheduler', 'Moab Workload Manager', or 'Supercluster
Development Group' unless prior written permission has been received from
Cluster Resources, Inc.

  All advertising materials for products that use or incorporate features of
the SOFTWARE must display the following acknowledgement: 'This product
includes software developed by Cluster Resources, Inc. for use in the Moab
Scheduling System.'

6.  Acceptance of this LICENSE

  It is not required that you accept this LICENSE; however, if you do not
accept the terms of this LICENSE, you are prohibited by law from installing,
using, modifying or distributing the SOFTWARE or any of its derivative works.
Therefore, by installing, using, modifying or distributing the SOFTWARE (or
any of its derivative works), you have agreed to this LICENSE and have
accepted all its terms and conditions.

  If any portion of this LICENSE is held invalid or unenforceable under any
particular circumstance, the balance of the LICENSE will continue to apply.

------------------------------------------------------------------------------
*/

/*                                          *
 * Contains:                                *
 *                                          *
 *                                          */


#include "mcom.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* prototypes */

int MXMLGetChild(mxml_t *,char *,int *,mxml_t **);
int MXMLAddE(mxml_t *,mxml_t *);
int MXMLGetAttrF(mxml_t *,char *,int *,void *,enum MDataFormatEnum,int);
int MXMLGetAttr(mxml_t *,char *,int *,char *,int);
int MXMLToString(mxml_t *,char *,int,char **,mbool_t);
int MXMLAppendAttr(mxml_t *,char *,char *,char);

/* END prototypes */


extern int MSecCompress(unsigned char *,unsigned int,unsigned char *,char *);
extern int MSecDecompress(unsigned char *,unsigned int,unsigned char *,unsigned int,unsigned char **,char *);


int MXMLExtractE(

  mxml_t  *E,  /* I */
  mxml_t  *C,  /* I */
  mxml_t **CP) /* O (optional) */

  {
  int cindex;

  if ((E == NULL) || (C == NULL))
    {
    return(FAILURE);
    }

  for (cindex = 0;cindex < E->CCount;cindex++)
    {
    if (C != E->C[cindex])
      {
      if (MXMLExtractE(E->C[cindex],C,CP) == SUCCESS)
        {
        return(SUCCESS);
        }

      continue;
      }

    if (CP != NULL)
      *CP = E->C[cindex];

    E->C[cindex] = NULL;

    return(SUCCESS);
    }  /* END for (cindex) */

  return(FAILURE);
  }  /* MXMLExtractE() */




int MXMLMergeE(

  mxml_t  *Dst,   /* I */
  mxml_t  *Src,   /* I */
  char     Delim) /* I */

  {
  int cindex;
  int aindex;

  /* parent and child must have identical element structure */

  if ((Dst == NULL) || (Src == NULL))
    {
    return(FAILURE);
    }

  for (cindex = 0;cindex < Dst->CCount;cindex++)
    {
    /* recursively call all children */

    if (MXMLMergeE(Dst->C[cindex],Src->C[cindex],Delim) == FAILURE)
      {
      return(FAILURE);
      }

    /* merge all attributes */

    for (aindex = 0;aindex < Src->ACount;aindex++)
      {
      MXMLAppendAttr(
        Dst,
        Src->AName[aindex],
        (char *)Src->AVal[aindex],
        Delim);
      }
    }  /* END for (cindex) */

  return(SUCCESS);
  }  /* MXMLMergeE() */





int MXMLSetChild(

  mxml_t  *E,     /* I */
  char    *CName, /* I */
  mxml_t **CE)    /* O */

  {
  if (CE != NULL)
    *CE = NULL;

  if ((E == NULL) || (CName == NULL))
    {
    return(FAILURE);
    }

  if (MXMLGetChild(E,CName,NULL,CE) == SUCCESS)
    {
    /* located existing child */

    return(SUCCESS);
    }

  /* create new child */
  
  if ((*CE = (mxml_t *)calloc(1,sizeof(mxml_t))) == NULL)
    {
    return(FAILURE);
    }

  MXMLAddE(E,*CE);
    
  if (CName != NULL)
    (*CE)->Name = strdup(CName);

  return(SUCCESS);
  }  /* END MXMLSetChild() */





int MXMLCreateE(

  mxml_t **E,    /* O */
  char    *Name) /* I (optional) */

  {
  /* NOTE:  should 'Name' be mandatory? */

  if (E == NULL)
    {
    return(FAILURE);
    }

  if ((*E = (mxml_t *)calloc(1,sizeof(mxml_t))) == NULL)
    {
    return(FAILURE);
    }

  if ((Name != NULL) && (Name[0] != '\0'))
    (*E)->Name = strdup(Name);

  return(SUCCESS);
  }  /* END MXMLCreateE() */




int MXMLDestroyE(

  mxml_t **EP)  /* I (modified) */

  {
  int index;

  mxml_t *E;

  if (EP == NULL)
    {
    return(FAILURE);
    }

  E = *EP;

  if (E == NULL)
    {
    return(SUCCESS);
    }

  if (E->C != NULL)
    {
    /* destroy children */

    for (index = 0;index < E->CCount;index++)
      {
      if (E->C[index] == NULL)
        continue;

      MXMLDestroyE(&E->C[index]);
      }  /* END for (index) */

    free(E->C);
    }  /* END if (E->C != NULL) */

  /* free attributes */

  if (E->AName != NULL)
    {
    for (index = 0;index < E->ACount;index++)
      {
      if (E->AName[index] == NULL)
        break;

      free(E->AName[index]);

      if ((E->AVal != NULL) && (E->AVal[index] != NULL))
        free(E->AVal[index]);
      }  /* END for (index) */

    if (E->AVal != NULL)
      {
      free(E->AVal);
      }

    if (E->AName != NULL)
      {
      free(E->AName);
      }
    }    /* END if (E->AName != NULL) */

  /* free name */

  if (E->Name != NULL)
    free(E->Name);

  if (E->Val != NULL)
    free(E->Val);

  free(E);

  *EP = NULL;

  return(SUCCESS);
  }  /* END MXMLDestroyE() */





int MXMLSetAttr(

  mxml_t *E,       /* I (modified) */
  char   *A,       /* I */
  void   *V,       /* I */
  enum MDataFormatEnum Format)  /* I */

  {
  int  aindex;
  int  iindex;

  int  rc;

  char tmpLine[MMAX_LINE];

  char *ptr;

  /* NOTE:  overwrite existing attr if found */

  if ((E == NULL) || (A == NULL))
    {
    return(FAILURE);
    }

  if (V != NULL)
    {
    switch (Format)
      {
      case mdfString:
      default:

        ptr = (char *)V;

        break;

      case mdfInt:

        sprintf(tmpLine,"%d",
          *(int *)V);

        ptr = tmpLine;

        break;

      case mdfLong:

        sprintf(tmpLine,"%ld",
          *(long *)V);

        ptr = tmpLine;

        break;

      case mdfDouble:

        sprintf(tmpLine,"%f",
          *(double *)V);

        ptr = tmpLine;

        break;
      }  /* END switch(Format) */
    }
  else
    {
    tmpLine[0] = '\0';

    ptr = tmpLine;
    }

  /* initialize attribute table */

  if (E->AName == NULL)
    {
    E->AName = (char **)calloc(1,sizeof(char *) * MMAX_XMLATTR);
    E->AVal  = (char **)calloc(1,sizeof(char *) * MMAX_XMLATTR);

    if ((E->AName == NULL) || (E->AVal == NULL))
      {
      return(FAILURE);
      }

    E->ASize = MMAX_XMLATTR;
    E->ACount = 0;
    }

  /* insert in alphabetical order */

  /* overwrite existing attribute if found */

  iindex = 0;
  rc     = 0;

  for (aindex = 0;aindex < E->ACount;aindex++)
    {
    rc = strcmp(E->AName[aindex],A);

    if (rc > 0)
      break;

    if (rc == 0)
      {
      iindex = aindex;

      break;
      }

    iindex = aindex + 1;
    }  /* END for (aindex) */

  if (aindex >= E->ACount)
    {
    iindex = aindex;

    if (aindex >= E->ASize)
      {
      /* allocate memory */

      E->AName = (char **)realloc(E->AName,sizeof(char *) * MAX(16,E->ASize << 1));
      E->AVal  = (char **)realloc(E->AVal,sizeof(char *) * MAX(16,E->ASize << 1));

      if ((E->AVal == NULL) || (E->AName == NULL))
        {
        E->ASize = 0;

        return(FAILURE);
        }

      E->ASize <<= 1;
      }
    }    /* END if (aindex >= E->ACount) */

  if ((ptr == NULL) && (aindex >= E->ACount))
    {
    /* no action required for empty attribute */

    return(SUCCESS);
    }

  /* prepare insertion point */

  if (rc != 0)
    {
    for (aindex = E->ACount - 1;aindex >= iindex;aindex--)
      {
      E->AVal[aindex + 1]  = E->AVal[aindex];
      E->AName[aindex + 1] = E->AName[aindex];
      }  /* END for (aindex) */

    E->AVal[aindex + 1]  = NULL;
    E->AName[aindex + 1] = NULL;
    }  /* END if (rc != 0) */

  if ((iindex < E->ACount) && (E->AVal[iindex] != NULL))
    free(E->AVal[iindex]);

  E->AVal[iindex] = strdup((ptr != NULL) ? ptr : "");

  if ((rc != 0) || (E->AName[iindex] == NULL))
    {
    E->AName[iindex] = strdup(A);

    E->ACount++;
    }

  return(SUCCESS);
  }  /* END MXMLSetAttr() */




int MXMLAppendAttr(

  mxml_t *E,      /* I root element */
  char   *AName,  /* I */
  char   *AVal,   /* I */
  char    Delim)  /* I */

  {
  int   ATok;
  int   len;

  char  VBuf[MMAX_LINE];

  if ((E == NULL) || (AName == NULL) || (AVal == NULL))
    {
    return(FAILURE);
    }

  ATok = -1;

  if (MXMLGetAttr(E,AName,&ATok,VBuf,sizeof(VBuf)) == SUCCESS)
    {
    char DString[2];

    len = strlen(E->AVal[ATok]) + strlen(AVal) + 2;

    E->AVal[ATok] = (char *)realloc(
      E->AVal[ATok],
      len);

    if (E->AVal[ATok] == NULL)
      {
      return(FAILURE);
      }
  
    DString[0] = Delim;
    DString[1] = '\0';

    /* just allocated adequate space, should not be able to overflow */

    strcat(E->AVal[ATok],DString);
        
    strcat(E->AVal[ATok],AVal);
    }
  else if (MXMLSetAttr(E,AName,AVal,mdfString) == FAILURE)
    {
    return(FAILURE); 
    }
 
  return(SUCCESS);
  }  /* END MXMLAppendAttr() */





int MXMLSetVal(

  mxml_t *E,      /* I (modified) */
  void   *V,      /* I */
  enum MDataFormatEnum Format) /* I */

  {
  char  tmpLine[MMAX_LINE];
  char *ptr;

  if ((E == NULL) || (V == NULL))
    {
    return(FAILURE);
    }

  if (E->Val != NULL)
    {
    free(E->Val);

    E->Val = NULL;
    }

  switch(Format)
    {
    case mdfString:
    default:

      ptr = (char *)V;

      break;

    case mdfInt:

      sprintf(tmpLine,"%d",
        *(int *)V);

      ptr = tmpLine;

      break;

    case mdfLong:

      sprintf(tmpLine,"%ld",
        *(long *)V);

      ptr = tmpLine;

      break;

    case mdfDouble:

      sprintf(tmpLine,"%f",
        *(double *)V);

      ptr = tmpLine;

      break;
    }  /* END switch(Format) */

  E->Val = strdup(ptr);

  /* strip '<' symbols  NOTE:  ignore '<' symbol in attrs */

  /* NOTE:  must replace temp hack 14 w/ &lt; */

  for (ptr = strchr(E->Val,'<');ptr != NULL;ptr = strchr(ptr,'<'))
    *ptr = (char)14;

  return(SUCCESS);
  }  /* END MXMLSetVal() */




int MXMLAddE(

  mxml_t *E, /* I (modified) */
  mxml_t *C) /* I (required) */

  {
  if ((E == NULL) || (C == NULL))
    {
    return(FAILURE);
    }

  if (E->CCount >= E->CSize)
    {
    if (E->C == NULL)
      {
      E->C = (mxml_t **)calloc(1,sizeof(mxml_t *) * MDEF_XMLICCOUNT);

      E->CSize = MDEF_XMLICCOUNT;
      }
    else
      {
      E->C = (mxml_t **)realloc(E->C,sizeof(mxml_t *) * MAX(16,E->CSize << 1));

      E->CSize <<= 1;
      }

    if (E->C == NULL)
      {
      /* cannot alloc memory */

      return(FAILURE);
      }  /* END if (E->C == NULL) */
    }    /* END if (E->CCount >= E->CSize) */

  E->C[E->CCount] = C;

  E->CCount++;

  return(SUCCESS);
  }  /* END MXMLAddE() */




int MXMLToXString(

  mxml_t   *E,             /* I */
  char    **Buf,           /* O (populated/modified) */
  int      *BufSize,       /* I/O */
  int       MaxBufSize,    /* I */
  char    **Tail,          /* O */
  mbool_t   NoCompress)    /* I */

  {
  int NewSize;

  /* NOTE:  MXMLToString() only fails due to lack of space */

  if ((E == NULL) || (Buf == NULL))
    {
    return(FAILURE);
    }

  /* allocate initial memory if required */

  if (*Buf == NULL)
    {
    NewSize = MMAX_BUFFER;
    if ((*Buf = (char *)calloc(NewSize, 1)) == NULL)
      {
      /* cannot allocate buffer */

      return(FAILURE);
      }

    if (BufSize != NULL)
      *BufSize = MMAX_BUFFER;
    }
  else
    {
    if (BufSize != NULL)
      {
      NewSize = *BufSize;
      }
    else
      {
      return(FAILURE);
      }
    }

  while (MXMLToString(
      E,
      *Buf,
      NewSize,
      Tail,
      NoCompress) == FAILURE)
    {
    if (NewSize >= MaxBufSize)
      {
      return(FAILURE);
      }

    NewSize = MIN(NewSize << 1,MaxBufSize);

    if ((*Buf = (char *)realloc(*Buf,NewSize)) == NULL)
      {
      /* cannot allocate buffer */

      return(FAILURE);
      }

    if (BufSize != NULL)
      *BufSize = NewSize;
    }    /* END while (MXMLToString() == FAILURE) */

  return(SUCCESS);
  }  /* END MXMLToXString() */




int MXMLToString(

  mxml_t   *E,           /* I */
  char     *Buf,         /* O */
  int       BufSize,     /* I */
  char    **Tail,        /* O */
  mbool_t   NoCompress)  /* I (compress Data element) */

  {
  char NewLine[MMAX_BUFFER];

  int index;

  int BSpace;

  char *BPtr;

  char *tail;

  int   len;

  if (Buf != NULL)
    {
    Buf[0] = '\0';
    }

  if ((E == NULL) || (Buf == NULL))
    {
    return(FAILURE);
    }

  if (BufSize < MMAX_NAME)
    {
    return(FAILURE);
    }

  BPtr   = Buf;
  BSpace = BufSize;

  /* display header */

  BPtr[0] = '<';

  BPtr++;
  BSpace--;

  if (E->Name != NULL)
    {
    len = strlen(E->Name);

    if (len >= BSpace)
      {
      /* insufficient space */

      BPtr[0] = '\0';

      return(FAILURE);
      }

    strcpy(BPtr,E->Name);

    BSpace -= len;
    BPtr   += len;
    }
  else
    {
    strcpy(BPtr,"NA");

    len = strlen("NA");

    BPtr   += len;
    BSpace -= len;
    }

  /* display attributes */

  for (index = 0;index < E->ACount;index++)
    {
    /* FORMAT:  <NAME>="<VAL>" */

    BPtr[0] = ' ';
 
    BPtr++;
    BSpace--;

    len = strlen(E->AName[index]);

    if (len >= BSpace)
      {
      /* insufficient space */

      BPtr[0] = '\0';

      return(FAILURE);
      }

    strcpy(BPtr,E->AName[index]);

    BSpace -= len;
    BPtr   += len;

    BPtr[0] = '=';

    BPtr++;
    BSpace--;

    BPtr[0] = '"';

    BPtr++;
    BSpace--;

    if ((strchr(E->AVal[index],'<') != NULL) ||
        (strchr(E->AVal[index],'>') != NULL))
      {
      /* must replace '<' with '&lt;' and '>' with '&gt;' */

      int   index1;
      int   index2 = 0;

      len = strlen(E->AVal[index]);

      for (index1 = 0;index1 < len;index1++)
        {
        if (E->AVal[index][index1] == '<')
          {
          NewLine[index2++] = '&';
          NewLine[index2++] = 'l';
          NewLine[index2++] = 't';
          NewLine[index2++] = ';';
          }
        else if (E->AVal[index][index1] == '>')
          {
          NewLine[index2++] = '&';
          NewLine[index2++] = 'g';
          NewLine[index2++] = 't';
          NewLine[index2++] = ';';
          }
        else
          {
          NewLine[index2++] = E->AVal[index][index1];
          }
        }   /* END for (index1) */

      NewLine[index2] = '\0';

      len = strlen(NewLine);

      if (len >= BSpace)
        {
        /* insufficient space */

        BPtr[0] = '\0';

        return(FAILURE);
        }

      strcpy(BPtr,NewLine);
      } /* END if (strchr(E->AVal,'<')...) */
    else
      {
      len = strlen(E->AVal[index]);

      if (len >= BSpace)
        {
        /* insufficient space */

        BPtr[0] = '\0';

        return(FAILURE);
        }

      strcpy(BPtr,E->AVal[index]);
      }    /* END else */

    BSpace -= len;
    BPtr   += len;

    BPtr[0] = '"';

    BPtr++;
    BSpace--;
    }  /* END for (index) */

  BPtr[0] = '>';

  BPtr++;
  BSpace--;

  if (E->Val != NULL)
    {
    len = strlen(E->Val);

    if (len >= BSpace)
      {
      /* insufficient space */

      BPtr[0] = '\0';

      return(FAILURE);
      }

    strcpy(BPtr,E->Val);

    BSpace -= len;
    BPtr   += len;
    }

  /* display children */

  for (index = 0;index < E->CCount;index++)
    {
    if (E->C[index] == NULL)
      continue;

    if (MXMLToString(E->C[index],BPtr,BSpace,&tail,NoCompress) == FAILURE)
      {
      return(FAILURE);
      }

    len = strlen(BPtr);

    BSpace -= len;
    BPtr   += len;
    }  /* END for (index) */

  /* display footer */

  if (E->Name != NULL)
    {
    len = strlen(E->Name);
    }
  else
    {
    len = strlen("NA");
    }

  if (BSpace < len + 4)
    {
    BPtr[0] = '\0';

    return(FAILURE);
    }

  BPtr[0] = '<';

  BPtr++;
  BSpace--;

  BPtr[0] = '/';

  BPtr++;
  BSpace--;

  if (E->Name != NULL)
    {
    strcpy(BPtr,E->Name);
    }
  else
    {
    strcpy(BPtr,"NA");
    }
 
  BSpace -= len;
  BPtr   += len;

  BPtr[0] = '>';

  BPtr++;
  BSpace--;

  /* terminate string */

  BPtr[0] = '\0';

  if (Tail != NULL)
    *Tail = BPtr;

  if ((NoCompress == FALSE) && (strlen(Buf) > (MMAX_BUFFER >> 1)))
    {
    if ((E->Name != NULL) && !strcmp(E->Name,"Data"))
      {
      /* attempt to compress in place */

      if (MSecCompress((unsigned char *)Buf,strlen(Buf),NULL,MCONST_CKEY) == FAILURE)
        {
        return(FAILURE);
        }
      }
    }

  return(SUCCESS);
  }  /* END MXMLToString() */




int MXMLGetAttrF(

  mxml_t *E,     /* I */
  char   *AName, /* I/O */
  int    *ATok,  /* I (optional) */
  void   *AVal,  /* O (optional) */
  enum MDataFormatEnum DFormat, /* I */
  int     VSize) /* I */

  {
  char tmpLine[MMAX_LINE];
  int  rc;

  if (AVal == NULL)
    {
    return(FAILURE);
    }

  switch (DFormat)
    {
    case mdfString:

      rc = MXMLGetAttr(
        E,
        AName,
        ATok,
        (char *)AVal,
        VSize);

      return(rc);

      /* NOTREACHED*/

      break;

    case mdfInt:
    case mdfLong:
    case mdfDouble:

      if (MXMLGetAttr(
            E,
            AName,
            ATok,
            tmpLine,
            sizeof(tmpLine)) == FAILURE)
        {
        /* clear response */

        switch(DFormat)
          {
          case mdfInt:    *(int *)AVal    = 0; break;
          case mdfLong:   *(long *)AVal   = 0; break;
          case mdfDouble: *(double *)AVal = 0.0; break;
          default: break;
          }  /* END switch(DFormat) */

        return(FAILURE);
        }

      break;

    default:

      return(FAILURE);

      /*NOTREACHED*/

      break;
    }  /* END switch(DFormat) */

  switch (DFormat)
    {
    case mdfInt:

      *(int *)AVal = (int)strtol(tmpLine,NULL,10);

      break;

    case mdfLong:

      *(long *)AVal = strtol(tmpLine,NULL,10);

      break;

    case mdfDouble:

      *(double *)AVal = strtod(tmpLine,NULL);

      break;

    default:

      *(char **)AVal = NULL;

      return(FAILURE);

      /*NOTREACHED*/

      break;
    }  /* END switch (DFormat) */

  return(SUCCESS);
  }  /* END MXMLGetAttrF() */






int MXMLGetAttr(

  mxml_t *E,     /* I */
  char   *AName, /* I/O */
  int    *ATok,  /* I (optional) */
  char   *AVal,  /* O (optional) */
  int     VSize) /* I */

  {
  /* NOTE:  set AName to empty string to get Name */

  int aindex;
  int astart;

  int EVSize;

  if (AVal != NULL)
    AVal[0] = '\0';

  if (E == NULL)
    {
    return(FAILURE);
    }

  EVSize = (VSize > 0) ? VSize : MMAX_LINE;

  if (ATok != NULL)
    astart = *ATok;
  else
    astart = -1;

  for (aindex = astart + 1;aindex < E->ACount;aindex++)
    {
    if ((AName == NULL) || 
        (AName[0] == '\0') || 
        !strcmp(AName,E->AName[aindex]))
      {
      if ((AName != NULL) && (AName[0] == '\0'))
        {
        strncpy(AName,E->AName[aindex],MMAX_NAME);
        AName[MMAX_NAME - 1] = '\0';
        }

      if (AVal != NULL)
        {
        strncpy(AVal,E->AVal[aindex],EVSize);
        AVal[EVSize - 1] = '\0';
        }

      if (ATok != NULL)
        *ATok = aindex;

      return(SUCCESS);
      }
    }    /* END for (aindex) */

  return(FAILURE);
  }  /* END MXMLGetAttr() */




int MXMLGetChild(

  mxml_t  *E,     /* I */
  char    *CName, /* I (optional) */
  int     *CTok,  /* I (optional) */
  mxml_t **C)     /* O */

  {
  int cindex;
  int cstart;

  if (C != NULL)
    *C = NULL;

  if ((E == NULL) || (C == NULL))
    {
    return(FAILURE);
    }

  if (CTok != NULL)
    cstart = *CTok;
  else
    cstart = -1;

  for (cindex = cstart + 1;cindex < E->CCount;cindex++)
    {
    if (E->C[cindex] == NULL)
      continue;

    if ((CName == NULL) || !strcmp(CName,E->C[cindex]->Name))
      {
      *C = E->C[cindex];

      if (CTok != NULL)
        *CTok = cindex;

      return(SUCCESS);
      }
    }    /* END for (cindex) */

  return(FAILURE);
  }  /* END MXMLGetChild() */




int MXMLGetChildCI(

  mxml_t  *E,     /* I */
  char    *CName, /* I (optional) */
  int     *CTok,  /* I (optional) */
  mxml_t **CP)    /* O (optional) */

  {
  int cindex;
  int cstart;

  int SLen;

  if (CP != NULL)
    *CP = NULL;

#ifndef __MOPT
  if (E == NULL) 
    {
    return(FAILURE);
    }
#endif /* __MOPT */

  if (CTok != NULL)
    cstart = *CTok;
  else
    cstart = -1;

  if (CName != NULL)
    SLen = strlen(CName) + 1;
  else
    SLen = 0;

  for (cindex = cstart + 1;cindex < E->CCount;cindex++)
    {
    if (E->C[cindex] == NULL)
      continue;

    if ((CName == NULL) || !strncasecmp(CName,E->C[cindex]->Name,SLen))
      {
      if (CP != NULL)
        *CP = E->C[cindex];

      if (CTok != NULL)
        *CTok = cindex;

      return(SUCCESS);
      }
    }    /* END for (cindex) */

  return(FAILURE);
  }  /* END MXMLGetChildCI() */





#define MMAX_XBUFFER 131072

int MXMLFromString(

  mxml_t **EP,        /* O (populate or create - will be freed on failure) */
  char    *XMLString, /* I */
  char   **Tail,      /* O (optional) */
  char    *EMsg)      /* O (optional) */

  {
  mxml_t  *E;
  char    *ptr;

  char    *tail;

  int      index;

  mbool_t  ElementIsClosed = FALSE;

  mbool_t  DoAppend = FALSE;

  char tmpNLine[MMAX_LINE + 1];
  char tmpVLine[MMAX_XBUFFER + 1];

  if (EP != NULL)
    *EP = NULL;

  if (EMsg != NULL)
    EMsg[0] = '\0';

  if ((XMLString == NULL) || (EP == NULL))
    {
    if (EMsg != NULL)
      strcpy(EMsg,"invalid arguments");

    return(FAILURE);
    }

  if ((ptr = strchr(XMLString,'<')) == NULL)
    {
    if (EMsg != NULL)
      strcpy(EMsg,"no XML in string");

    return(FAILURE);
    }

  if (ptr[1] == '/')
    {
    /* located tail marker */

    if (EMsg != NULL)
      strcpy(EMsg,"premature termination marker");

    return(FAILURE);
    }

  /* NOTE:  should support append/overlay parameter (NYI) */

  /* ignore 'meta' elements */

  while ((ptr[1] == '?') || (ptr[1] == '!'))
    {
    ptr++;

    /* ignore 'meta' elements */

    if (*ptr == '?')
      {
      ptr++;

      if ((ptr = strstr(ptr,"?>")) == NULL)
        {
        /* cannot locate end of meta element */

        return(FAILURE);
        }

      if ((ptr = strchr(ptr,'<')) == NULL)
        {
        /* cannot locate next element */

        if (EMsg != NULL)
          strcpy(EMsg,"cannot locate post-meta XML");

        return(FAILURE);
        }
      }    /* END if (*ptr == '?') */

    /* ignore 'comment' element */

    if (!strncmp(ptr,"!--",3))
      {
      ptr += 3;

      if ((ptr = strstr(ptr,"-->")) == NULL)
        {
        /* cannot locate end of comment element */

        if (EMsg != NULL)
          strcpy(EMsg,"cannot locate comment termination marker");

        return(FAILURE);
        }

      if ((ptr = strchr(ptr,'<')) == NULL)
        {
        /* cannot locate next element */

        if (EMsg != NULL)
          strcpy(EMsg,"cannot locate post-comment XML");

        return(FAILURE);
        }
      }    /* END if (!strncmp(ptr,"!--",3)) */
    else if (ptr[1] == '!')
      {
      char* ptr2;

      ptr++;
      ptr++;

      while (*ptr != '\0')
        {
        if (strchr("<[>",*ptr) != NULL)
          {
          break;
          }

        ptr++;
        }

      if ((ptr2 = strchr("<[>",*ptr)) == NULL)
        {
        /* cannot locate end element */

        if (EMsg != NULL)
          strcpy(EMsg,"cannot locate post-comment XML");

        return(FAILURE);
        }

      switch (*ptr2)
        {
        case '[':
 
          ptr = strstr(ptr,"]>");

          break;

        default:

          /* NYI */

          return(FAILURE);

          /* NOTREACHED */

          break;
        }

      if ((ptr = strchr(ptr,'<')) == NULL)
        {
        /* cannot locate next element */

        if (EMsg != NULL)
          strcpy(EMsg,"cannot locate post-comment XML");

        return(FAILURE);
        }
      }    /* END if (*ptr == '!') */
    }      /* END while ((ptr[1] == '?') || (ptr[1] == '!')) */

  /* remove whitespace */

  while (isspace(*ptr))
    ptr++;

  /* extract root element */

  if (*ptr != '<')
    {
    /* cannot located start of element */

    if (EMsg != NULL)
      strcpy(EMsg,"cannot locate start of root element");

    return(FAILURE);
    }

  ptr++;  /* ignore '<' */

  index = 0;

  while ((*ptr != ' ') && (*ptr != '>'))
    {
    if ((ptr[0] == '/') && (ptr[1] == '>'))
      {
      ElementIsClosed = TRUE;

      break;
      }

    tmpNLine[index++] = *(ptr++);

    if ((index >= MMAX_LINE) || (ptr[0] == '\0'))
      {
      if (EMsg != NULL)
        sprintf(EMsg,"element name is too long - %.10s",
          tmpNLine);

      return(FAILURE);
      }
    }

  tmpNLine[index] = '\0';

  if ((*EP == NULL) && (MXMLCreateE(EP,tmpNLine) == FAILURE))
    {
    if (EMsg != NULL)
      sprintf(EMsg,"cannot create XML element '%s'",
        tmpNLine);

    return(FAILURE);
    }

  E = *EP;

  if ((E->ACount > 0) || (E->CCount > 0))
    {
    DoAppend = TRUE;
    }

  if (ElementIsClosed == TRUE)
    {
    ptr += 2; /* skip '/>' */

    if (Tail != NULL)
      *Tail = ptr;

    return(SUCCESS);
    }

  while (*ptr == ' ')
    ptr++;

  while (*ptr != '>')
    {
    /* extract attributes */

    /* FORMAT:  <ATTR>="<VAL>" */

    index = 0;

    while ((*ptr != '=') && (*ptr != '\0'))
      {
      tmpNLine[index++] = *(ptr++);

      if (index >= MMAX_LINE)
         break;
      }

    tmpNLine[index] = '\0';

    if (*ptr != '\0')
      ptr++;  /* skip '=' */

    if (*ptr != '\0')
      ptr++;  /* skip '"' */

    if (*ptr == '\0')
      {
      if (EMsg != NULL)
        sprintf(EMsg,"string is corrupt - early termination");

      MXMLDestroyE(EP);

      return(FAILURE);
      }

    index = 0;

    while ((*ptr != '"') ||
          ((ptr > XMLString) && (*(ptr - 1) == '\\')))
      {
      if (((*ptr == '&') && (*(ptr+1) == 'l') && (*(ptr+2) == 't') && (*(ptr+3) == ';')))
        {
        tmpVLine[index++] = '<';

        ptr += 4;
        }
      else if (((*ptr == '&') && (*(ptr+1) == 'g') && (*(ptr+2) == 't') && (*(ptr+3) == ';')))
        {
        tmpVLine[index++] = '>';

        ptr += 4;
        }
      else
        {
        tmpVLine[index++] = *(ptr++);
        }

      if ((index >= MMAX_XBUFFER) || (*ptr == '\0'))
        {
        MXMLDestroyE(EP);

        /* locate tail */

        if (Tail != NULL)
          *Tail = ptr + strlen(ptr);

        if (EMsg != NULL)
          sprintf(EMsg,"attribute name is too long - %.10s",
            tmpVLine);

        return(FAILURE);
        }
      }

    tmpVLine[index] = '\0';

    MXMLSetAttr(E,tmpNLine,(void *)tmpVLine,mdfString);

    ptr++; /* ignore '"' */

    while (*ptr == ' ')
      ptr++;

    if ((ptr[0] == '/') && (ptr[1] == '>'))
      {
      /* element terminator reached */

      ptr += 2; /* skip '/>' */

      if (Tail != NULL)
        *Tail = ptr;

      return(SUCCESS);
      }
    }  /* END while (*ptr != '>') */

  ptr++; /* ignore '>' */

  /* skip whitespace */

  while (isspace(*ptr))
    ptr++;

  /* NOTE:  value can occur before, after, or spread amongst children */
 
  /* extract value */

  if (*ptr != '<')
    {
    char *ptr2;

    index = 0;

    if (!strncmp(ptr,CRYPTHEAD,strlen(CRYPTHEAD)))
      {
      char *tail;
      int   len;

      mxml_t *C;

      char *tmpBuf;

      /* compressed data detected, '<' symbol guaranteed to not be part of string */

      tail = strchr(ptr,'<');
 
      /* determine size of value */

      len = tail - ptr;

      /* uncompress data */

      tmpBuf = NULL;

      /* NOTE:  CRYPTHEAD header indicates encryption/compression */

      MSecDecompress((unsigned char *)ptr,(unsigned int)len,NULL,(unsigned int)0,(unsigned char **)&tmpBuf,NULL);

      /* process expanded buffer (guaranteed to be a single element */

      if ((MXMLFromString(&C,tmpBuf,NULL,EMsg) == FAILURE) ||
          (MXMLAddE(E,C) == FAILURE))
        {
        MXMLDestroyE(EP);

        if ((EMsg != NULL) &&
            (EMsg[0] == '\0'))
          {
          strcpy(EMsg,"cannot add child element");
          }

        return(FAILURE);
        }

      tmpBuf = NULL;

      /* move pointer to end of compressed data */

      ptr = tail;
      }  /* END if (!strncmp(ptr,CRYPTHEAD,strlen(CRYPTHEAD))) */

    while (*ptr != '<')
      {
      tmpVLine[index++] = *(ptr++);

      if (index >= MMAX_XBUFFER)
        break;
      }

    tmpVLine[index] = '\0';

    E->Val = strdup(tmpVLine);

    /* restore '<' symbols */

    for (ptr2 = strchr(E->Val,(char)14);ptr2 != NULL;ptr2 = strchr(ptr2,(char)14))
      *ptr2 = '<';
    }  /* END if (*ptr != '<') */

  /* extract children */

  while (ptr[1] != '/')
    {
    mxml_t *C;

    C = NULL;

    if (DoAppend == TRUE)
      {
      char *ptr2;
      char  tmpCName[MMAX_NAME];

      int   index;

      /* FORMAT:  <NAME>... */

      /* locate name */

      ptr2 = ptr + 1;  /* ignore '<' */

      index = 0;

      while ((*ptr2 != ' ') && (*ptr2 != '>'))
        {
        if ((ptr2[0] == '/') && (ptr2[1] == '>'))
          {
          break;
          }

        tmpCName[index++] = *(ptr2++);

        if ((index >= MMAX_LINE) || (ptr2[0] == '\0'))
          {
          if (EMsg != NULL)
            sprintf(EMsg,"element name is too long - %.10s",
              tmpCName);

          MXMLDestroyE(EP);

          return(FAILURE);
          }
        }

      tmpCName[index] = '\0';

      MXMLGetChild(E,tmpCName,NULL,&C);
      }

    if ((MXMLFromString(&C,ptr,&tail,EMsg) == FAILURE) ||
        (MXMLAddE(E,C) == FAILURE))
      {
      break;
      }

    ptr = tail;

    if ((ptr == NULL) || (ptr[0] == '\0'))
      {
      /* XML is corrupt */

      if (Tail != NULL)
        *Tail = ptr;

      if ((EMsg != NULL) && (EMsg[0] == '\0'))
        strcpy(EMsg,"cannot extract child");

      MXMLDestroyE(EP);

      return(FAILURE);
      }
    }  /* END while (ptr[1] != '/') */

  /* ignore whitespace */

  while (isspace(*ptr))
    ptr++;

  /* value may follow children */

  if (E->Val == NULL)
    {
    if (!strncmp(ptr,CRYPTHEAD,strlen(CRYPTHEAD)))
      {
      char *tail;
      int   len;

      mxml_t *C;

      char *tmpBuf;

      /* compressed data detected, '<' symbol guaranteed to not be part of string */

      tail = strchr(ptr,'<');

      /* determine size of value */

      len = tail - ptr;

      /* uncompress data */

      tmpBuf = NULL;

      /* NOTE:  CRYPTHEAD header indicates encryption/compression */

      MSecDecompress((unsigned char *)ptr,(unsigned int)len,NULL,(unsigned int)0,(unsigned char **)&tmpBuf,NULL);

      /* process expanded buffer (guaranteed to be a single element */

      if ((MXMLFromString(&C,tmpBuf,NULL,EMsg) == FAILURE) ||
          (MXMLAddE(E,C) == FAILURE))
        {
        MXMLDestroyE(EP);

        if ((EMsg != NULL) &&
            (EMsg[0] == '\0'))
          {
          strcpy(EMsg,"cannot add child element");
          }

        return(FAILURE);
        }

      tmpBuf = NULL;

      /* move pointer to end of compressed data */

      ptr = tail;
      }  /* END if (!strncmp(ptr,CRYPTHEAD,strlen(CRYPTHEAD))) */

    index = 0;

    while (*ptr != '<')
      {
      tmpVLine[index++] = *(ptr++);

      if ((index >= MMAX_XBUFFER) || (*ptr == '\0'))
        {
        if (EMsg != NULL)
          sprintf(EMsg,"cannot load value line - %.10s (%s)",
            tmpVLine,
            (index >= MMAX_XBUFFER) ? "too long" : "corrupt");

        MXMLDestroyE(EP);

        return(FAILURE);
        }

      if ((*ptr == '/') && (ptr[1] == '>'))
        break;
      }

    tmpVLine[index] = '\0';

    if (index > 0)
      E->Val = strdup(tmpVLine);
    }  /* END if (tmpVLine[0] == '\0') */

  /* process tail */

  if (*ptr == '/')
    {
    /* process '/>' */

    ptr++; /* ignore '/' */
    }
  else if (*ptr != '\0')
    {
    /* NOTE: corrupt XML string may move ptr beyond string terminator */

    ptr++; /* ignore '<' */

    ptr++; /* ignore '/' */

    ptr += strlen(E->Name);
    }

  if (*ptr == '\0')
    {
    if (EMsg != NULL)
      sprintf(EMsg,"xml tail is corrupt");

    MXMLDestroyE(EP);

    return(FAILURE);
    }

  ptr++; /* ignore '>' */

  if (Tail != NULL)
    *Tail = ptr;

  return(SUCCESS);
  }  /* END MXMLFromString() */




mbool_t MXMLStringIsValid(

  char *Buf)  /* I */

  {
  char *ptr;

  /* NOTE:  only limited checks performed */

  /* check if line starts with '<' */

  if ((Buf == NULL) || (Buf[0] == '\0'))
    {
    return(FALSE);
    }

  ptr = strchr(Buf,'<');

  if (ptr == NULL)
    {
    return(FALSE);
    }

  ptr--;

  while (ptr > Buf)
    {
    if (!isspace(*ptr))
      {
      return(FALSE);
      }

    ptr--;
    }  /* END while (ptr > Buf) */

  /* check if line contains '<' */

  ptr = strchr(Buf,'>');

  if (ptr == NULL)
    {
    return(FALSE);
    }

  return(TRUE);
  }  /* END MXMLStringIsValid() */




int MXMLDupE(

  mxml_t  *SrcE,   /* I */
  mxml_t **DstEP)  /* O */

  {
  char Buffer[MMAX_BUFFER];

  if (DstEP == NULL)
    {
    return(FAILURE);
    }

  *DstEP = NULL;

  if (SrcE == NULL)
    {
    return(FAILURE);
    }

  if (MXMLToString(SrcE,Buffer,sizeof(Buffer),NULL,TRUE) == FAILURE)
    {
    return(FAILURE);
    }

  if (MXMLFromString(DstEP,Buffer,NULL,NULL) == FAILURE)
    {
    return(FAILURE);
    }

  return(SUCCESS);
  }  /* END MXMLDupE() */
  
/* END MXML.c */



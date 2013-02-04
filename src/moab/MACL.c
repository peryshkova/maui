/*
Package:  moab
Module:   MACL.c
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
 
#include "moab.h"
#include "msched-proto.h"
 
extern mlog_t mlog;

extern const char *MHRObj[];
extern const char *MComp[];
extern const char *MAttrO[];




char *MACLListShow(

  macl_t *ACL,
  int     OType,
  int     Mode,
  char   *Buffer)  /* O: (required) */
 
  {
  int aindex;
  int oindex;

  char *ptr;

  char  tmpLine[MAX_MLINE];

  int ACLFound = FALSE;
 
  /* OType != -1 Format:  <A>[:<B>]... */
  /*   or                 <OBJECT>=<A> <OBJECT>=<B>... */

  if (Buffer == NULL)
    {
    return(NULL);
    }

  Buffer[0] = '\0';

  for (oindex = 0;oindex < MAX_MATTRTYPE;oindex++)
    {
    if ((OType != -1) && (OType != oindex))
      continue;

    tmpLine[0] = '\0';

    for (aindex = 0;ACL[aindex].Type != maNONE;aindex++)
      {
      if (ACL[aindex].Type != oindex)
        continue;

      ACLFound = TRUE;

      ptr = MACLShow(ACL[aindex],Mode,FALSE);

      if (tmpLine[0] != '\0')
        {
        if (OType == -1)
          strcat(tmpLine,":");
        else
          strcat(tmpLine,":");
        }

      strcat(tmpLine,ptr);
      }
 
    if (tmpLine[0] != '\0')
      {
      if ((OType == -1) || (Mode & (1 << mfmVerbose)))
        {
        strcat(Buffer,MAttrO[oindex]);

        if ((tmpLine[0] != '=') &&
            (tmpLine[0] != '<') &&
            (tmpLine[0] != '>'))
          {
          strcat(Buffer,"=");
          }

        strcat(Buffer,tmpLine);
        }
      else
        {
        if (!strncmp(tmpLine,"==",2))
          strcat(Buffer,&tmpLine[2]);
        else
          strcat(Buffer,tmpLine);
        }

      if (Mode & (1 << mfmAVP))
        strcat(Buffer,";");
      else
        strcat(Buffer," ");
      }
    }    /* END for (aindex) */

  if (ACLFound == FALSE)
    {
    if (Mode & (1 << mfmAVP))
      strcat(Buffer,NONE);

    return(Buffer);
    }

  return(Buffer);
  }  /* END MACLListShow() */



  
     
char *MACLShow(
 
  macl_t ACL,
  int    Mode,
  int    ShowObject)
 
  {
  int  cindex;
 
  static char Line[MAX_MLINE];
 
  char ACLString[MAX_MNAME << 1];
  char ModString[MAX_MNAME];
 
  Line[0] = '\0';
 
  if (ShowObject == TRUE)
    strcpy(ACLString,MHRObj[(int)ACL.Type]);
  else
    ACLString[0] = '\0';

  if (Mode & (1 << mfmVerbose))
    {
    cindex = 0;
 
    switch((int)ACL.Affinity)
      {
      case nmPositiveAffinity:
 
        /* default */
 
        ModString[cindex++] = '+';

        break;

      case nmNeutralAffinity:
 
        ModString[cindex++] = '=';

        break;
 
      case nmNegativeAffinity:
 
        ModString[cindex++] = '-';
 
        break;
 
      case nmUnavailable:
      case nmRequired:
      case nmNone:
      default:
 
        ModString[cindex++] = '?';

        break;
      }  /* END switch((int)ACL.Affinity) */
 
    if (ACL.Flags & (1 << maclRequired))
      ModString[cindex++] = '*';
 
    if (ACL.Flags & (1 << maclDeny))
      ModString[cindex++] = '!';
 
    if (ACL.Flags & (1 << maclXOR))
      ModString[cindex++] = '^';
 
    ModString[cindex] = '\0';
    }
  else
    {
    ModString[0] = '\0';
    }

  cindex = ACL.Cmp;

  if (Mode & (1 << mfmHuman))
    {
    if (cindex == mcmpSEQ)
      cindex = mcmpEQ;
    else if (cindex == mcmpSNE)
      cindex = mcmpNE;
    }

  switch(ACL.Cmp)
    {
    case mcmpSEQ:
    case mcmpSSUB:
    case mcmpSNE:
    default:
 
      sprintf(&ACLString[strlen(ACLString)],"%s%s%s",
        MComp[cindex],
        ACL.Name,
        ModString);
 
      break;
 
    case mcmpLT:
    case mcmpLE:
    case mcmpEQ:
    case mcmpNE:
    case mcmpGE:
    case mcmpGT: 

      if ((ACL.Type == maDuration) && (Mode & (1 << mfmHuman)))
        {
        /* human readable */

        sprintf(&ACLString[strlen(ACLString)],"%s%s%s",
          MComp[cindex],
          MULToTString(ACL.Value),
          ModString);
        }
      else
        { 
        sprintf(&ACLString[strlen(ACLString)],"%s%ld%s",
          MComp[cindex],
          ACL.Value,
          ModString);
        }

      break;
    }   /* END switch(ACL.Cmp) */

  if (Mode & (1 << mfmHuman))
    { 
    if (Line[0] != '\0')
      strcat(Line," ");
    }
  else if (Mode & (1 << mfmAVP))
    {
    if (Line[0] != '\0')
      strcat(Line,":");
    }
 
  strcat(Line,ACLString);

  if ((Mode & (1 << mfmAVP)) && (Line[0] == '\0'))
    strcpy(Line,NONE);
     
  return(Line);
  }  /* END MACLShow() */ 
 


 
 
int MACLLoadConfigLine(

  macl_t *ACL,
  char   *ACLLine)

  {
  char *ptr;
  char *TokPtr;

  char *ACLVal[2];

  int   oindex;

  ACLVal[1] = NULL;

  /* FORMAT:  <OBJTYPE><CMP><VAL><MODIFIER>{<WS>|;|,}... */

  ptr = MUStrTok(ACLLine," \t\n;,",&TokPtr);

  while (ptr != NULL)
    {
    if ((oindex = MUGetIndex(ptr,MAttrO,TRUE,0)) != 0)
      {
      ACLVal[0] = ptr + strlen(MAttrO[oindex]);

      MACLLoadConfig(ACL,ACLVal,1,oindex);     
      }

    ptr = MUStrTok(NULL," \t\n;,",&TokPtr);        
    }  /* END while (ptr != NULL) */

  return(SUCCESS);
  }  /* END MACLLoadConfigLine() */




int MACLLoadConfig(
 
  macl_t  *ACL,      /* O */
  char   **ACLList,  /* I */
  int      ACLCount, /* I */
  int      ObjType)  /* I */
 
  {
  int index;
  int len;

  int aindex;
  int ACLStart;
 
  int AIndex;
 
  char *ptr;
  char *ptr2;
  char *tail;
 
  char *TokPtr;

  const char *FName = "MACLLoadConfig";

  DBG(7,fCONFIG) DPrint("%s(ACL,%s,%d,%s)\n",
    FName,
    (ACLList != NULL) ? ACLList[0] : "NULL",
    ACLCount,
    MAttrO[ObjType]);
 
  /* FORMAT: [<CMP>]{[<MODIFIER>]<OBJECTVAL>[<AFFINITY>]}[{:,}{[<MODIFIER>]<OBJECTVAL>[<AFFINITY>]}]... */
 
  if ((ACL == NULL) || (ACLList == NULL))
    {
    return(FAILURE);
    }
 
  for (ACLStart = 0;ACLStart < MAX_MACL;ACLStart++)
    {
    if ((ACL[ACLStart].Name[0] == '\0') && (ACL[ACLStart].Value == 0))
      break;
    }  /* END for (ACLStart = 0;...) */
 
  if (ACLStart == MAX_MACL)
    {
    return(FAILURE);
    }
 
  AIndex = 0;
 
  for (aindex = 0;aindex < ACLCount;aindex++)
    {
    if (ObjType != maDuration)
      ptr = MUStrTok(ACLList[aindex],":|,",&TokPtr);
    else
      ptr = MUStrTok(ACLList[aindex],"|,",&TokPtr);

    while (ptr != NULL)
      {
      if ((ACLStart + aindex) >= MAX_MACL)
        break;
 
      ACL[ACLStart + AIndex].Type = (char)ObjType;

      /* extract affinity */

      ACL[ACLStart + AIndex].Affinity = nmPositiveAffinity;

      tail = ptr + strlen(ptr) - 1;

      if (strchr("-+=%^!*",*tail) != NULL)
        {
        switch(*tail)
          {
          case '-':
 
            tail[0] = '\0'; 
 
            ACL[ACLStart + AIndex].Affinity = nmNegativeAffinity;
 
            break;
 
          case '=':
 
            tail[0] = '\0';
 
            ACL[ACLStart + AIndex].Affinity = nmNeutralAffinity;
 
            break;
 
          case '+':
 
            tail[0] = '\0';
  
            ACL[ACLStart + AIndex].Affinity = nmPositiveAffinity;
 
            break;

          case '!':

            *tail = '\0';

            ACL[ACLStart + AIndex].Flags |= (1 << maclDeny);

            break;

          case '^':

            *tail = '\0';

            ACL[ACLStart + AIndex].Flags |= (1 << maclXOR);

            break;

          case '*':

            *tail = '\0';

            ACL[ACLStart + AIndex].Flags |= (1 << maclRequired);

            break;

          default:

            /* NO-OP */
 
            break;
          }  /* END switch(*tail) */
        }    /* END if (tail) */

      /* extract modifier */

      /* FORMAT:  [<CMD>][!^*][<CMP>]<ACLVAL> */

      if ((ptr[0] == '=') && (strchr("<>!=%",ptr[1])))
        ptr++;

      ptr2 = ptr;             

      if ((index = MUCmpFromString(ptr2,&len)) != 0)
        {
        ACL[ACLStart + AIndex].Cmp = index;

        ptr2 += len; 
        }
      else
        {
        switch(ObjType)
          {
          case maDuration:
          case maTask:
          case maProc:

            ACL[ACLStart + AIndex].Cmp = mcmpLE;

            break;

          default:

            ACL[ACLStart + AIndex].Cmp = mcmpSEQ;

            break;
          }  /* END switch(ObjType) */
        }
 
      if (ptr2[0] == '!')
        {
        ACL[ACLStart + AIndex].Flags |= (1 << maclDeny);
 
        ptr2++;
        }
 
      if (ptr2[0] == '^')
        {
        ACL[ACLStart + AIndex].Flags |= (1 << maclXOR);
 
        ptr2++;
        }
 
      if (ptr2[0] == '*')
        {
        ACL[ACLStart + AIndex].Flags |= (1 << maclRequired);
 
        ptr2++;
        }

      switch(ObjType)
        {
        case maDuration:
        case maTask:
        case maProc:

          /* do nothing */

          break;

        default:

          if (ACL[ACLStart + AIndex].Cmp == mcmpEQ)
            ACL[ACLStart + AIndex].Cmp = mcmpSEQ;
          else if (ACL[ACLStart + AIndex].Cmp == mcmpNE)
            ACL[ACLStart + AIndex].Cmp = mcmpSNE;

          break;       
        }  /* END switch(ObjType) */
 
      switch(ACL[ACLStart + AIndex].Cmp)
        {
        case mcmpSEQ:
        case mcmpSNE:
        case mcmpSSUB:

          MUStrCpy(ACL[ACLStart + AIndex].Name,ptr2,sizeof(ACL[0].Name));    
 
          break;
 
        default:

          MUStrCpy(ACL[ACLStart + AIndex].Name,ptr2,sizeof(ACL[0].Name));       

          if (ObjType == maDuration)
            ACL[ACLStart + AIndex].Value = MUTimeFromString(ptr2);
          else 
            ACL[ACLStart + AIndex].Value = strtol(ptr2,NULL,0);      
 
          break;
        }  /* END switch(ObjType) */
 
      DBG(7,fCONFIG) DPrint("INFO:     ACL[%d] loaded with %s %s (Affinity: %d)\n",
        ACLStart + AIndex,
        MAttrO[ObjType],
        ptr2,
        ACL[ACLStart + AIndex].Affinity);
 
      AIndex++;

      if (ObjType != maDuration)
        ptr = MUStrTok(NULL,":|,",&TokPtr);
      else
        ptr = MUStrTok(NULL,"|,",&TokPtr);
      }  /* END while (ptr != NULL) */
    }    /* END for (aindex) */
 
  return(SUCCESS);
  }  /* END MACLLoadConfig() */





/* access granted if:  */
/*   R1 CL matches R2 ACL (R2 grants access to R1) */
/*   R2 CL matches R1 ACL (R1 grants X ) */
/*   R1 CL matches R2 RCL */
/*   R2 CL matches R1 RCL */

int MACLCheckAccess(
 
  macl_t *ACL,         /* I: access control list */
  macl_t *CL,          /* I: cred list */
  char   *Affinity,
  int    *IsInclusive)
 
  {
  int aindex;
  int cindex;
  int oindex;
 
  int Inclusive[MAX_MATTRTYPE];
 
  int tmpIsInclusive = FALSE;

  mbool_t NonReqNeeded = FALSE;
  mbool_t NonReqFound  = FALSE;
 
  if (IsInclusive == NULL)
    {
    return(FAILURE);
    }
 
  memset(Inclusive,FALSE,sizeof(Inclusive));
 
  /* check 'deny' ACLs */
 
  for (aindex = 0;ACL[aindex].Name[0] != '\0';aindex++)
    {
    if (ACL[aindex].Flags & (1 << maclDeny))
      Inclusive[(int)ACL[aindex].Type] = TRUE;

    if ((!(ACL[aindex].Flags & (1 << maclDeny))) &&
        (!(ACL[aindex].Flags & (1 << maclRequired))) &&
        (!(ACL[aindex].Flags & (1 << maclXOR))))
      {
      NonReqNeeded = TRUE;
      }
    }  /* END for (raindex) */
 
  /* check other ACLs */
 
  for (aindex = 0;ACL[aindex].Type != maNONE;aindex++)
    {
    char ACLMatch = FALSE;
 
    for (cindex = 0;CL[cindex].Type != maNONE;cindex++)
      {
      char ValMatch = TRUE;
 
      if (CL[cindex].Type != ACL[aindex].Type)
        continue;
 
      switch(ACL[aindex].Cmp)
        {
        case mcmpEQ:
 
          if (CL[cindex].Value != ACL[aindex].Value)
            ValMatch = FALSE;
 
          break;
 
        case mcmpGT:

          if (CL[cindex].Value <= ACL[aindex].Value)
            ValMatch = FALSE;

          break;

        case mcmpGE:
 
          if (CL[cindex].Value < ACL[aindex].Value)
            ValMatch = FALSE;
 
          break;
 
        case mcmpLT:

          if (CL[cindex].Value >= ACL[aindex].Value)
            ValMatch = FALSE;

        case mcmpLE:
 
          if (CL[cindex].Value > ACL[aindex].Value)
            ValMatch = FALSE;
 
          break;
 
        case mcmpNE:
 
          if (CL[cindex].Value == ACL[aindex].Value)
            ValMatch = FALSE;
 
          break;
 
        case mcmpSEQ:
        default:
 
          if ((CL[cindex].Name[0] != ACL[aindex].Name[0]) &&
              (CL[cindex].Name[0] != '['))
            {
            ValMatch = FALSE;
            }
          else if ((strcmp(CL[cindex].Name,ACL[aindex].Name)) &&
                   (strcmp(CL[cindex].Name,ALL)))
            {
            ValMatch = FALSE;
            }
 
          break; 
        }  /* END switch(ACL[aindex].Type) */
 
      if (ValMatch != TRUE)
        {
        if (CL[cindex].Flags & (1 << maclRequired))
          {
          /* required credential request not matched */
 
          *IsInclusive = FALSE;
 
          return(FAILURE);
          }
 
        continue;
        }
 
      /* match found */
 
      if (ACL[aindex].Flags & (1 << maclDeny))
        {
        /* deny match found, reservation is exclusive */
 
        *IsInclusive = FALSE;
 
        return(FAILURE);
        }
      else if (ACL[aindex].Flags & (1 << maclXOR))
        {
        Inclusive[(int)ACL[aindex].Type] = FALSE;
 
        continue;
        }
      else if (ACL[aindex].Flags & (1 << maclRequired))
        {
        /* NO-OP */
        }
      else
        {
        NonReqFound = TRUE;
        }

 
      if (Affinity != NULL)
        *Affinity = ACL[aindex].Affinity;
 
      ACLMatch = TRUE;
 
      tmpIsInclusive = TRUE;
      }  /* END for (cindex) */
 
    if ((ACL[aindex].Flags & (1 << maclRequired)) &&
        (ACLMatch != TRUE))
      {
      /* cannot locate 'required' ACL match */
 
      *IsInclusive = FALSE;
 
      return(FAILURE);
      }
    }    /* END for (aindex) */

  if ((NonReqNeeded == TRUE) && (NonReqFound == FALSE))
    {
    /* cannot locate 'required' ACL match */

    *IsInclusive = FALSE;

    return(FAILURE);
    }  /* END ((NonReqNeeded == TRUE) && (NonReqFound == FALSE)) */
 
  if (tmpIsInclusive == FALSE)
    {
    for (oindex = 1;oindex < MAX_MATTRTYPE;oindex++)
      {
      if (Inclusive[oindex] == TRUE)
        {
        tmpIsInclusive = TRUE;
 
        break;
        }
      }    /* END for (oindex) */
    }
 
  *IsInclusive = tmpIsInclusive;
 
  return(SUCCESS);
  }  /* END MACLCheckAccess() */




int MACLSet(

  macl_t *ACL,     /* I */
  int     Type,
  void   *Val,
  int     Cmp,
  int     Affinity,
  long    Flags,
  int     Mode)  /* I: 0 -> unique type */

  {
  int aindex;

  for (aindex = 0;aindex < MAX_MACL;aindex++)
    {
    if (ACL[aindex].Type != maNONE)
      {
      if ((Mode != 0) || (ACL[aindex].Type != Type))
        continue;
      }

    if (ACL[aindex].Type == maNONE)
      ACL[aindex + 1].Type = maNONE;

    /* free slot located */

    switch(Cmp)
      {
      case mcmpSEQ:
      case mcmpSSUB:
      case mcmpSNE:

        strncpy(ACL[aindex].Name,(char *)Val,MAX_MNAME);

        break;

      default:

        ACL[aindex].Value = (long)(*(long *)Val);

        break;
      }  /* END switch(Cmp) */

    ACL[aindex].Cmp      = Cmp;
    ACL[aindex].Affinity = Affinity;
    ACL[aindex].Type     = Type;

    ACL[aindex].Flags    = Flags;

    return(SUCCESS);
    }  /* END for (aindex) */

  return(FAILURE);
  }  /* END MACLSet() */




int MACLGet(

  macl_t  *ACL,
  int      OType,
  void   **Value,
  int     *Start)

  {
  int aindex;
  int sindex;

  if (Start != NULL)
    sindex = *Start;
  else
    sindex = 0;

  for (aindex = sindex;ACL[aindex].Type != maNONE;aindex++)
    {
    if (ACL[aindex].Type != OType)
      continue;

    if (Value != NULL)
      {
      switch(ACL[aindex].Cmp)
        { 
        case mcmpSEQ:
        case mcmpSNE:
        case mcmpSSUB:

          *Value = (void *)ACL[aindex].Name;

          break;

        default:

          *Value = (void *)&ACL[aindex].Value;

          break;
        }  /* END switch(ACL[aindex].Cmp) */
      }    /* END if (Value != NULL) */

    return(SUCCESS);
    }  /* END for (aindex) */

  /* matching ACL not located */

  return(FAILURE);
  }  /* END MACLGet() */




int MACLClear(

  macl_t *ACL,
  int     OType)

  {
  int aindex;
  int tindex;

  /* locate tail */

  for (tindex = 0;tindex < MAX_MACL;tindex++)
    {
    if (ACL[tindex].Type == maNONE)
      break;
    }

  if (tindex == MAX_MACL)
    {
    return(FAILURE);
    }
 
  /* remove all instances of object type ACL's in list */

  for (aindex = 0;aindex < tindex;aindex++)
    {
    if (ACL[aindex].Type != OType)
      continue;

    /* remove type */

    memcpy(&ACL[aindex],&ACL[tindex - 1],sizeof(macl_t));

    aindex--;

    tindex--;

    ACL[tindex].Type = maNONE;
    }  /* END for (aindex) */
 
  return(SUCCESS);
  }  /* END MACLClear() */


/* END MACL.c */


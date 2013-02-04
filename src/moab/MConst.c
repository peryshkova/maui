/*
Package:  moab
Module:   MConst.c
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

const char *MBool[] = {
  "FALSE",
  "TRUE",
  "NOTSET",
  NULL };

const char *MComp[] = {
  "NC",
  "<",
  "<=",
  "==",
  ">=",
  ">",
  "<>",
  "=",
  "!=",
  "%<",
  "%!",
  "%=",
  NULL };

const char *MAMOCmp[] = {
  NONE,
  "lt",
  "le",
  "eq",
  "ge",
  "gt",
  "ne",
  NULL };
 
const char *MCKeyword[] = {
  NONE,
  "SC=",
  "ARG=",
  "AUTH=",
  "CMD=",
  "DT=",
  "CLIENT=",
  "TS=",
  "CK=",
  NULL };

/* repository for char arrays */

const char *MJobNodeMatchType[] = { NONE, "EXACTNODE", "EXACTPROC", NULL };
const char *MPolicyMode[]      = { "DEFAULT", "OFF", "ON", "SOFT", "HARD", "EXEMPT", NULL };
const char *MSimQPolicy[]      = { "NORMAL", "CONSTANTJOBDEPTH", "CONSTANTPSDEPTH", NULL };
const char *MSimNCPolicy[]     = { "NORMAL", "UNIFORM", "PARTITIONED", NULL };
const char *MBFPolicy[]        = { "NONE", "FIRSTFIT", "BESTFIT", "GREEDY", "BESTTIMEFIT", "LAZY", "PREEMPT", NULL };
const char *MStatusCode[]       = { "FAILURE", "SUCCESS", NULL };
const char *MAMType[]          = { NONE, "QBANK", "RESD", "FILE", "GOLD", NULL };
const char *MAMState[]         = { NONE, "Active", "Down", "Corrupt", NULL };     
const char *MAMProtocol[]      = { NONE, "XML", "KVP", NULL };

const char *MAMChargePolicy[] = {
  NONE,
  "DEBITALLWC",
  "DEBITALLCPU",
  "DEBITALLPE",
  "DEBITSUCCESSFULWC",
  "DEBITSUCCESSFULCPU",
  "DEBITSUCCESSFULPE",
  NULL };

const char *MRMState[] = { NONE, "Active", "Down", "Corrupt", NULL };

/* sync with enum MRMTypeEnum */

const char *MRMType[] = { 
  NONE,
  "LL",
  "OTHER",
  "PBS",
  "SGE",
  "SSS",
  "WIKI",
  "RMS",
  "LSF",
  "NATIVE",
  NULL };

const char *MRMSubType[]   = { NONE, "RMS", NULL };        

/* sync w/MRMFuncEnum */

const char *MRMFuncType[]  = {
  NONE,
  "clusterquery",
  "cyclefinalize",
  "jobcancel",
  "jobcheckpoint",
  "jobgetproximatetasks",
  "jobmigrate",
  "jobmodify",
  "jobquery",
  "jobrequeue",
  "jobresume",
  "jobstart",
  "jobsubmit",
  "jobsuspend",
  "queuequery",
  "resourcemodify",
  "resourcequery",
  "rmeventquery",
  "rmgetdata",
  "rminitialize",
  "rmquery",
  "workloadquery",
  NULL };

 
const char *MTimeLogic[]   = { "OR", "AND", NULL };

const char *MSimFlagType[] = { 
  NONE, 
  "IGNHOSTLIST", 
  "IGNCLASS", 
  "IGNQOS", 
  "IGNMODE", 
  "IGNFEATURES", 
  "IGNFRAME",
  "IGNALL", 
  NULL };  

const char *MJobPrioAccrualPolicyType[] = 
                      { NONE, "ALWAYS", "QUEUEPOLICY", "FULLPOLICY", NULL };
const char *MBFPriorityPolicyType[] =
                      { NONE, "RANDOM", "DURATION", "HWDURATION", NULL };
const char *MResourceLimitPolicyType[] =
                      { NONE, "ALWAYS", "EXTENDEDVIOLATION", "BLOCKEDWORKLOADONLY", NULL };
const char *MPolicyAction[] =
                      { NONE, "CANCEL", "REQUEUE", "SUSPEND", NULL };
const char *MNodeLoadPolicyType[] =
                      { NONE, "ADJUSTSTATE", "ADJUSTPROCS", NULL };
const char *MFSPolicyType[] =
                      { NONE, "DEDICATEDPS", "DEDICATEDPES", "UTILIZEDPS", NULL };

const char *MSRPeriodType[] = { 
  NONE, 
  "DAY", 
  "WEEK", 
  "INFINITY", 
  NULL };

const char *MPolicyType[] = { 
  NONE, 
  "MAXJOB", 
  "MAXNODE", 
  "MAXPE", 
  "MAXPROC", 
  "MAXPS", 
  "MAXWC", 
  "MAXMEM", 
  NULL };

const char *MResSelType[] = { 
  "NONE",
  "NORMAL",
  "BESTEFFORT",
  "FORCE", 
  NULL };

const char *MGridCtlCmds[] = {
  NONE,
  "initialize",
  "commit",
  "list",
  "set",
  "remove",
  "query",
  "submit",
  "modify",
  "reset",
  "register",
  NULL };

const char *MJobCtlCmds[] = {
  NONE,
  "cancel",
  "checkpoint",
  "diagnose",
  "modify",
  "query",
  "requeue",
  "resume",
  "show",
  "start",
  "submit",
  "suspend",
  "terminate",
  NULL };

const char *MResCtlCmds[] = {
  NONE,
  "cancel",
  "create",
  "modify",
  "query",
  NULL };

const char *MBalCmds[] = {
  NONE,
  "execute",
  "query",
  NULL };

const char *MClientMode[] = {
  "NONE",
  "RELATIVE",
  "SUMMARY",
  "GREP",
  "VERBOSE",
  "FORCE",
  "PARSE", 
  "FORCE2", 
  "COMPLETE",
  "BLOCK",
  "NONBLOCK",
  "OVERLAP",
  "CLEAR",
  NULL };

const char *MQALType[] = { "", "&", "^", NULL };

const char *MCDisplayType[] = { 
  "NONE", 
  "NODECENTRIC", 
  NULL };

const char *MResFlags[] = { 
  NONE,
  "STANDINGRES", 
  "SINGLEUSE", 
  "BYNAME", 
  "META",
  "PREEMPTEE",
  "TIMEFLEX",
  "SPACEFLEX",
  "DEDICATEDNODE",
  "DEDICATEDRESOURCE",
  "ADVRES",
  "FORCE",
  "OWNERPREEMPT",
  NULL };

/* job reservation */

const char *MJRType[] = { 
  "NONE", 
  "ActiveJob", 
  "Priority", 
  "QOSReserved", 
  "Deadline", 
  "Meta", 
  "User", 
  NULL };

const char *MResType[] = { 
  "NONE",
  "Job", 
  "User",
  "Meta",
  NULL };

const char *MNAccessPolicy[] = {
  NONE,
  "SHARED",
  "SINGLEJOB",
  "SINGLETASK",
  "SINGLEUSER",
  NULL };

/* NOTE: sync w/ MAX_MATTR, enum MExpAttrEnum */

const char *MAttrType[] = {
  "Feature",
  "Partition",
  "QOS",
  "Class",
  "Network",
  "Opsys",
  "Arch",
  "NodeState",
  "JobState",
  "SysAttr",
  "GRes",
  "JFeature",
  NULL };

const char *MResSetSelectionType[] = {
  NONE,
  "ONEOF",
  "ANYOF",
  "FIRSTOF",
  NULL };

const char *MResSetAttrType[] = {
  NONE,
  "FEATURE",
  "MEMORY",
  "PROCSPEED",
  NULL };

const char *MResSetPrioType[] = {
  NONE,
  "BESTFIT",
  "WORSTFIT",
  "BESTRESOURCE",
  "MINLOSS",
  NULL };

const char *BNFCommand[] = {
  NONE,
  "query",
  "status",
  "message",
  "set",
  NULL };

const char *MNodeAttr[] = {
  NONE,
  "ACCESS",
  "ARCH",
  "GRES",
  "AVLCLASS",
  "AVLMEMWEIGHT",
  "AVLPROCWEIGHT",
  "CFGCLASS",
  "CFGDISK",
  "CFGMEM",
  "CFGMEMWEIGHT",
  "CFGPROCWEIGHT",
  "CFGSWAP",
  "EXTLOAD",
  "FEATURES",
  "FRAME",
  "LOAD",
  "LOADWEIGHT",
  "MAXJOB",
  "MAXJOBPERUSER",
  "MAXLOAD",
  "MAXPEPERJOB",
  "MAXPROC",
  "MAXPROCPERCLASS",
  "MAXPROCPERUSER",
  "NETWORK",
  "NODEID",
  "NODESTATE",
  "NODETYPE",
  "OS",
  "PARTITION",
  "PRIORITYF",
  "PRIORITY",
  "PRIOWEIGHT",
  "PROCSPEED",
  "RADISK",
  "RAMEM",
  "RAPROC",
  "RASWAP",
  "RCDISK",
  "RCMEM",
  "RCPROC",
  "RCSWAP",
  "RESOURCES",
  "SIZE",
  "SLOT",
  "SPEED",
  "SPEEDWEIGHT",
  "STATACTIVETIME",
  "STATTOTALTIME",
  "STATUPTIME",
  "TASKCOUNT",
  "USAGEWEIGHT",
  NULL };

const char *MNPComp[] = {
  NONE,
  "ADISK",
  "AMEM",
  "APROCS",
  "ASWAP",
  "CDISK",
  "CMEM",
  "CPROCS",
  "CSWAP",
  "JOBCOUNT",
  "LOAD",
  "PREF",
  "PRIORITY",
  "RESAFFINITY",
  "SPEED",
  "USAGE",
  NULL };

const char *MAMAttr[] = {
  NONE,
  "APPENDMACHINENAME",
  "CHARGEPOLICY",
  "CONFIGFILE",
  "CSALGO",
  "CSKEY",
  "DEFERJOBONFAILURE",
  "FALLBACKACCOUNT",
  "FLUSHINTERVAL",
  "HOST",
  "JFACTION",
  "PORT",
  "SERVER",
  "SOCKETPROTOCOL",
  "TIMEOUT",
  "TYPE",
  "WIREPROTOCOL",
  NULL };

const char *MJFActionType[] = {
  NONE,
  "CANCEL",
  "DEFER",
  NULL };

const char *MAMFuncType[]  = {
  NONE,
  "joballocreserve",
  "joballocdebit",
  "resallocreserve",
  "resallocdebit",
  "userdefaultquery",
  "amsync",
  NULL };

const char *MFSAttr[] = {
  NONE, 
  "Target",
  NULL };

const char *MRMAttr[] = {
  NONE,
  "AUTHTYPE",
  "ASYNCJOBSTART",
  "CONFIGFILE",
  "CSALGO",
  "CSKEY",
  "EPORT",
  "HOST",
  "LOCALDISKFS",
  "MINETIME",
  "NAME",
  "NMPORT",
  "NMSERVER",
  "PORT",
  "SOCKETPROTOCOL",
  "SUSPENDSIG",
  "TIMEOUT",
  "TYPE",
  "VERSION",
  "WIREPROTOCOL",
  NULL };

const char *MCredAttr[] = {
  NONE,
  "PRIORITY",
  "MAXJOB",
  "MAXNODE",
  "MAXPE",
  "MAXPROC",
  "MINPROC",
  "MAXPS",
  "MAXWC",
  "MAXMEM",
  "MAXIJOB",
  "MAXINODE",
  "MAXIPE",
  "MAXIPROC",
  "MAXIPS", 
  "MAXIWC",
  "MAXIMEM",
  "OMAXJOB",
  "OMAXNODE",
  "OMAXPE",
  "OMAXPROC",
  "OMAXPS",
  "OMAXWC",
  "OMAXMEM",
  "OMAXIJOB",
  "OMAXINODE",
  "OMAXIPE",
  "OMAXIPROC",
  "OMAXIPS",
  "OMAXIWC",
  "OMAXIMEM",
  "OMAXJNODE",
  "OMAXJPE",
  "OMAXJPROC",
  "OMAXJPS",
  "OMAXJWC",
  "OMAXJMEM",
  "FSTARGET",
  "QLIST",
  "QDEF",
  "PLIST",
  "PDEF",
  "ALIST",
  "ADEF",
  "JOBFLAGS",   
  "MAXJOBPERUSER",
  "MAXNODEPERUSER",
  "MAXPROCPERUSER",
  "MAXPROCPERNODEPERQUEUE",
  "OVERRUN",
  "ID",
  "DEFAULT.WCLIMIT",
  "MAX.WCLIMIT",
  "MAXPROCPERNODE",
  "MAXNODEPERJOB",
  "MAXPROCPERJOB",
  NULL };

const char *MOServAttr[] = {
  NONE,
  "CSALGO",
  "CSKEY",
  "HOST",
  "PORT",
  "SPROTOCOL",
  "VERSION",
  NULL };

const char *MCredCfgParm[] = {
  NULL,
  "ACCOUNTCFG",
  NULL,
  "CLASSCFG",
  NULL,
  NULL,
  NULL,
  NULL,
  "GROUPCFG",
  NULL,
  NULL,
  "NODECFG",
  "PARCFG",
  NULL,
  "QOSCFG",
  "QUEUECFG",
  NULL,
  NULL,
  NULL,
  NULL,
  "SCHEDCFG",
  NULL,
  NULL,
  NULL,
  "SYSCFG",
  "USERCFG",
  NULL };

const char *MQOSAttr[] = {
  NONE,
  "PRIORITY",
  "MAXJOB",
  "MAXPROC",
  "MAXNODE",
  "XFWEIGHT",
  "QTWEIGHT",
  "XFTARGET",
  "QTTARGET",
  "QFLAGS",
  "FSTARGET",
  NULL };

const char *MClassAttr[] = {
  NONE,
  "OCNODE",
  "DEFAULT.FEATURES",
  "HOSTLIST",
  "NAME",
  "NODEACCESSPOLICY",
  "MAXPROCPERNODE",
  "OCDPROCFACTOR",
  "STATE",
  "WCOVERRUN",
  NULL };

const char *MGroupAttr[] = {
  NONE,
  "CLASSWEIGHT",
  NULL };

const char *MUserAttr[] = {
  NONE,
  "MAX.WCLIMIT",
  NULL };

const char *MStatAttr[] = {
  NONE,
  "TJC",
  "TNJC",
  "TQT",
  "MQT",
  "TRT",
  "TET",
  "TMSA",
  "TMSD",
  "TPSR",
  "TPSE",
  "TPSD",
  "TPSU",
  "TJA",
  "TNJA",
  "TXF",
  "TNXF",
  "MXF",
  "TBP",
  "MBP",
  "TQM",
  NULL };

const char *MLimitAttr[] = {
  NONE,
  "UJobs",
  "UProcs",
  "UPS",
  NULL };

const char *MSchedAttr[] = {
  NONE,
  "CPVERSION",
  "FBSERVER",
  "HOMEDIR",
  "MODE",
  "NAME",
  "SERVER", 
  NULL };

const char *MClientAttr[] = {
  NONE,
  "CSALGO",
  "TIMEOUT",
  "FLAGS",
  NULL };

const char *MSysAttr[] = {
  NONE,
  "time",
  "statInitTime",
  "syncTime",
  "version",
  NULL };

const char *MFrameAttr[] = {
  NONE,
  "Index",
  "Name",
  NULL };

const char *MClusterAttr[] = {
  NONE,
  "MaxSlot",
  "Name",
  "PresentTime",
  NULL };

const char *MResAttr[] = {
  NONE,
  "AAccount",
  "ACL",
  "AGroup",
  "AUser",
  "creds",
  "duration",
  "endtime",
  "flags",
  "HostExp", 
  "JState",     
  "MaxTasks",
  "Messages",
  "Name",
  "NodeCount",
  "NodeList",
  "Owner",
  "Resources",
  "starttime",
  "StatCAPS",
  "StatCIPS",
  "StatTAPS",
  "StatTIPS",
  "TaskCount",
  "Type",
  "XAttr",
  NULL };

const char *MNResAttr[] = {
  NONE,
  "DRes",
  "End",
  "Name",
  "State",
  "Start",
  "TC",
  "Type",
  NULL };

const char *MSResAttr[] = {
  NONE,
  "ACCESS",
  "ACCOUNTLIST",
  "CHARGEACCOUNT",
  "CLASSLIST",
  "DAYS",
  "DEPTH",
  "ENDTIME",
  "FLAGS",
  "GROUPLIST",
  "HOSTLIST",
  "IDLETIME",
  "JOBATTRLIST",
  "MAXTIME",
  "NAME",
  "NODEFEATURES",
  "OWNER",
  "PARTITION",
  "PERIOD",
  "PRIORITY",
  "PROCLIMIT",
  "QOSLIST",
  "RESOURCES",
  "STARTTIME",
  "STIDLETIME",
  "STTOTALTIME",
  "TASKCOUNT",
  "TASKLIMIT",
  "TIMELIMIT",
  "TPN",
  "USERLIST",
  "WENDTIME",
  "WSTARTTIME",
  NULL };

const char *MJobAttr[] = {
  NONE,
  "Account",
  "AllocNodeList",
  "Args",
  "AWDuration",
  "Calendar",
  "CmdFile",
  "CompletionTime",
  "CPULimit",
  "Depend",
  "DRMJID",
  "EEWDuration",
  "Env",
  "ExcHList",
  "Exec",
  "Flags",
  "GAttr",
  "Group",
  "Hold",
  "HostList",
  "IsInteractive",
  "IsRestartable",
  "IsSuspendable",
  "IWD",
  "JobID",
  "JobName",
  "MasterHost",
  "Messages",
  "Notification",
  "PAL",
  "Priority",
  "QOS",
  "QOSReq",
  "ReqAWDuration",
  "ReqCMaxTime",
  "ReqNodes",
  "ReqProcs",
  "ReqReservation",
  "ReqSMinTime",
  "RMJID",
  "RMXString",
  "RsvAccess",
  "SRMJID",
  "StartCount",
  "StartTime",
  "State",
  "StatMSUtl",
  "StatPSDed",
  "StatPSUtl",
  "StdErr",
  "StdIn",
  "StdOut",
  "StepID",
  "SubmitLanguage",
  "SubmitString",
  "SubmissionTime",
  "SuspendDuration",
  "SysPrio",
  "SysSMinTime",
  "User",
  "UserPrio",
  "UtlMem",
  "UtlProcs",
  NULL };

const char *MRMXAttr[] = {
  NONE,
  "ADVRES",
  "DDISK",
  "DISTPOLICY",
  "DMEM",
  "FLAGS",
  "GEOMETRY",
  "HOSTLIST",
  "MFEATURE",
  "MMEM",
  "NACCESSPOLICY",
  "NALLOCPOLICY",
  "NODESET",
  "PARTITION",
  "PREF",
  "QOS",
  "QUEUEJOB",
  "SGE",
  "SID",
  "SJID",
  "TPN",
  "TRL",
  NULL };

const char *MJobFlags[] = {
  NONE,
  "BENCHMARK",
  "BACKFILL",
  "SPAN",
  "ADVRES",
  "NOQUEUE",
  "HOSTLIST",
  "RESMAP",
  "SHAREDRESOURCES",
  "BYNAME",
  "BESTEFFORT",
  "RESTARTABLE",
  "PREEMPTEE",
  "PREEMPTOR",
  "DEDICATEDNODE",
  "PRESTART",
  "REMOTE",
  "NASINGLETASK",
  "SPVIOLATION",
  "IGNNODEPOLICIES",
  "NORMSTART",
  "GLOBALQUEUE",
  NULL };

const char *MReqAttr[] = {
  NONE,
  "AllocNodeList",
  "ReqArch",
  "ReqClass",
  "ReqDiskPerTask",
  "ReqMemPerTask",
  "ReqNodeDisk",
  "ReqNodeFeature",
  "ReqNodeMem",
  "ReqNodeProc",
  "ReqNodeSwap",
  "ReqOpsys",
  "ReqPartition",
  "ReqSwapPerTask",
  "NCReqMax",
  "NCReqMin",
  "TCReqMax",
  "TCReqMin",
  "TPN",
  NULL };

const char *MQOSFlags[] = {
  "IGNJOBPERUSER",
  "IGNPROCPERUSER",
  "IGNNODEPERUSER",
  "IGNPSPERUSER",
  "IGNJOBQUEUEDPERUSER",
  "IGNSYSMAXPROC",
  "IGNSYSMAXTIME",
  "IGNSYSMAXPS",
  "IGNSRMAXTIME",
  "IGNUSER",
  "IGNSYSTEM",
  "IGNALL",
  "PREEMPTOR",
  "PREEMPTEE",
  "DEDICATED",
  "RESERVEALWAYS",
  "USERESERVED",
  "NOBF",
  "NORESERVATION",
  "RESTARTPREEMPT",
  "NTR",
  "RUNNOW",
  "PREEMPTSPV",
  "IGNHOSTLIST",
  NULL };

/* sync with MLogFacilityEnum */

const char *MLogFacilityType[] = {
  "fCORE",
  "fSCHED",
  "fSOCK",
  "fUI",
  "fLL",
  "fSDR",
  "fCONFIG",
  "fSTAT",
  "fSIM",
  "fSTRUCT",
  "fFS",
  "fCKPT",
  "fAM",
  "fRM",
  "fPBS",
  "fWIKI",
  "fSGE",
  "fSSS",
  "fLSF",
  "fNAT",
  "fALL",
  NULL };

const char *MSysNodeAttr[] = {
  "NONE",
  "JMD",
  "Batch",
  "Interactive",
  "Login",
  "HPSS",
  "PIOFS",
  "System",
  "Gateway",
  "EPrimary",
  NULL
  };

const char *MTLimitType[] = {
  NONE,
  "active",
  "idle",
  "system",
  NULL };

const char *MResThresholdType[] = {
  "NONE",
  "BYPASS",
  "QUEUETIME",
  "XFACTOR",
  NULL };

const char *MNAllocPolicy[] = { 
  NONE,
  "FIRSTAVAILABLE",
  "LASTAVAILABLE", 
  "MINLOCAL", 
  "MINGLOBAL", 
  "MINRESOURCE", 
  "PRIORITY",
  "CPULOAD",
  "FIRSTSET",
  "LOCAL",
  "CONTIGUOUS",
  "MAXBALANCE",
  "FASTEST",
  NULL };

const char *MAllocLocalityPolicy[] = {
  NONE,
  "BESTEFFORT",
  "FORCED",
  "RMSPECIFIC",
  NULL };

const char *MTaskDistributionPolicy[] = {
  NONE,
  "DEFAULT",
  "LOCAL",
  "ARBGEO",
  "PACK",
  "ROUNDROBIN",
  NULL };

const char *MNAvailPolicy[] = {
  NONE,
  "COMBINED",
  "DEDICATED",
  "UTILIZED",
  NULL };

const char *BFWindowTraversal[] = { NONE, "LONGESTFIRST", "WIDESTFIRST", NULL };

const char *MBFMPolicy[]  = { 
  NONE,
  "PROCS",
  "NODES",
  "PROCSECONDS",
  "SECONDS", 
  NULL };

const char *MJSPolicy[]   = { "MINPROC", "MAXPROC", "NDMAXPROC", NULL };
const char *MResPolicy[]  = { "DEFAULT", "HIGHEST", "CURRENTHIGHEST", "NEVER" };
const char *MHoldType[]   = { NONE, "User", "System", "Batch", "Defer", "All", NULL };
const char *MComType[]    = { "ROUNDROBIN", "BROADCAST", "TREE", "MASTERSLAVE", NULL };

const char *MDefReason[]   = { 
  "NONE",
  "Admin",
  "NoResources",
  "SystemLimitsExceeded",
  "BankFailure",
  "CannotDebitAccount",
  "RMFailure",
  "RMReject",
  "PolicyViolation",
  "QOSAccess",
  NULL };

const char *MCPType[] = { 
  "Sched",
  "JOB",
  "RESERVATION",
  "SRES",
  "NODE",
  "USER",
  "GROUP",
  "ACCOUNT",
  "TOTAL",
  "RTOTAL",
  "CTOTAL",
  "GTOTAL",
  "SYSSTATS",
  "RM",
  "AM",
  "Sys",
  NULL };

const char *MStatType[] = {
  "AVGXFACTOR", 
  "MAXXFACTOR", 
  "AVGQTIME",
  "AVGBYPASS", 
  "MAXBYPASS", 
  "JOBCOUNT", 
  "PHREQUEST",
  "PHRUN",
  "WCACCURACY",
  "BFCOUNT",
  "BFPHRUN",
  "JOBEFFICIENCY",
  "QOSDELIVERED",
  NULL };

const char *MLLJobState[] = {
  "Idle",
  "Pending",
  "Starting",
  "Running",
  "CompletePending",
  "RejectPending",
  "RemovePending",
  "VacatePending",
  "Completed",
  "Rejected",
  "Removed",
  "Vacated",
  "Cancelled",
  "NotRun",
  "Terminated",
  "Unexpanded",
  "SubmissionErr",
  "Hold",
  "Deferred",
  "NotQueued",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  "???",
  NULL };

const char *MService[] = {
  NONE,
  "showstate",
  "setspri",
  "setupri",
  "showq",
  "sethold",
  "releasehold",
  "showhold",
  "showstats",
  "resetstats",
  "setres",
  "releaseres",
  "showres",
  "schedctl",
  "diagnose",
  "setdeadline",
  "releasedeadline",
  "showdeadline",
  "showstart",
  "setqos",
  "showgrid",
  "showbf",
  "showconfig",
  "checkjob",
  "checknode",
  "runjob",
  "canceljob",
  "changeparam",
  "migratejob",
  "showstart",
  "query",
  "mjobctl",
  "mgridctl",
  "mnodectl",
  "mresctl",
  "mschedctl",
  "mstat",
  "mdiag",
  "mshow",
  "mbal",
  NULL };


/* sync with MClientCmdEnum */

const char *MClientCmd[] = {
  NONE,
  "mbal",
  "mdiag",      /* diagnose */    
  "mgridctl",   
  "mjobctl",    /* runjob, canceljob, setqos, sethold, releasehold, setspri, setupri */
  "mnodectl",   
  "mresctl",    /* setres */
  "mschedctl",  /* schedctl, changeparam, resetstats, showconfig */
  "mshow",      /* showq, checknode, checkjob, showres, showstate */     
  "mstat",      /* showstats, showgrid */
  "msub",
  NULL };

/* sync with enum MAllocRejEnum */

const char *MAllocRejType[] = {
  "Features",
  "Class",
  "Partition",
  "CPU",
  "Memory",
  "Disk",
  "Swap",
  "Network",
  "State",
  "EState",
  "Opsys",
  "Arch",
  "ReleaseTime",
  "ReserveTime",
  "NodeCount",
  "Hold",
  "Policy",
  "Locality",
  "Dependency",
  "ShortPool",
  "SystemLimits",
  "PartitionAccess",
  "Corruption",
  "FairShare",
  "HostList",
  "Pool",
  NULL };

const char *MJobDependType[] = {
  NONE,
  "jobstart",
  "jobcomplete",
  "jobsuccessfulcomplete",
  "jobfailedcomplete",
  NULL };

const char *MPolicyRejection[] = {
  NONE,
  "MaxJobPerUser",
  "MaxProcPerUser",
  "MaxNodePerUser",
  "MaxProcSecondPerUser",
  "MaxJobQueuedPerUser",
  "MaxPEPerUser",
  "MaxJobPerGroup",
  "MaxNodePerGroup",
  "MaxNodeSecondPerGroup",
  "MaxJobQueuedPerGroup",
  "MaxJobPerAccount",
  "MaxNodePerAccount",
  "MaxNodeSecondPerAccount",
  "MaxJobQueuedPerAccount",
  "MaxSystemJobSize",
  "MaxSystemJobTime", "MaxSystemJobPS",
  "UnknownUser",
  "UnknownGroup",
  "UnknownAccount",
  NULL };
 
const char *FrameName[] = { "0",
   "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9", "10",
  "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
  "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
  "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
  NULL };

const char *FrName[] = { "0",
  "fr1n", "fr2n", "fr3n", "fr4n", "fr5n", "fr6n", "fr7n", "fr8n", "fr9n", "fr10",
  "fr11", "fr12", "fr13", "fr14", "fr15", "fr16", "fr17", "fr18", "fr19", "fr20",
  "fr21", "fr22", "fr23", "fr24", "fr25", "fr26", "fr27", "fr28", "fr29", "fr30",
  "fr31", "fr32", "fr33", "fr34", "fr35", "fr36", "fr37", "fr38", "fr39", "fr40",
  "fr41", "fr42", "fr43", "fr44", "fr45", "fr46", "fr47", "fr48", "fr49", "fr50",
  NULL };

const char *NodeName[] = {
  "00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16",
  NULL };

const char *MSchedMode[] = {
  NONE,
  "NORMAL",
  "PROFILE",
  "SIMULATION",
  "SINGLESTEP",
  "TEST",
  NULL };

const char *MNodeState[] = {
  "NONE",
  "None",
  "Down",
  "Idle",
  "Busy",
  "Running",
  "Drained",
  "Drain",
  "Flush",
  "Reserved",
  "Unknown",
  NULL };

const char *MWCVAction[] = {
  NONE,
  "CANCEL",
  "PREEMPT",
  NULL };

const char *MTimePolicy[] = {
  NONE,
  "REAL",
  NULL };


/* config data */

const mcfg_t MCfg[] = {
  { NONE,                       pParamNONE,                   mdfString,  -1,       NULL },
  { "LOGLEVEL",                 pLogLevel,                    mdfInt,     mxoSched, NULL },
  { "LOGDIR",                   pSchedLogDir,                 mdfString,  mxoSched, NULL },
  { "LOGFACILITY",              pLogFacility,                 mdfStringArray, mxoSched, NULL },
  { "LOGFILEMAXSIZE",           pLogFileMaxSize,              mdfInt,     mxoSched, NULL },
  { "LOGFILE",                  pSchedLogFile,                mdfString,  mxoSched, NULL },
  { "LOGFILEROLLDEPTH",         pLogFileRollDepth,            mdfInt,     mxoSched, NULL },
  { "ACCOUNTCAP",               pCACap,                       mdfInt,     mxoPar,   NULL },
  { "ACCOUNTWEIGHT",            pCAWeight,                    mdfInt,     mxoPar,   NULL },
  { "ADMIN1",                   mcoAdmin1Users,               mdfStringArray, mxoSched, NULL },
  { "ADMIN2",                   mcoAdmin2Users,               mdfStringArray, mxoSched, NULL },
  { "ADMIN3",                   mcoAdmin3Users,               mdfStringArray, mxoSched, NULL },
  { "ADMIN4",                   mcoAdmin4Users,               mdfStringArray, mxoSched, NULL },
  { "ADMINHOSTS",               mcoAdminHosts,                mdfStringArray, mxoSched, NULL },
  { "ADMINS",                   mcoAdminUsers,                mdfStringArray, mxoSched, NULL },
  { "AFSWEIGHT",                pOLDAFSWeight,                mdfInt,     mxoPar,   NULL },
  { "APIFAILURETHRESHHOLD",     pAPIFailureThreshhold,        mdfInt,     mxoSched, NULL },
  { "ATTRWEIGHT",               pAttrWeight,                  mdfString,  mxoPar,   NULL },
  { "ATTRCAP",                  pAttrCap,                     mdfString,  mxoPar,   NULL },
  { "ATTRSTATEWEIGHT",          pAJobStateWeight,             mdfString,  mxoPar,   NULL },
  { "ATTRATTRWEIGHT",           pAJobAttrWeight,              mdfString,  mxoPar,   NULL },
  { "ATTRSTATECAP",             pAJobStateCap,                mdfString,  mxoPar,   NULL },
  { "ATTRATTRCAP",              pAJobAttrCap,                 mdfString,  mxoPar,   NULL },
  { "BACKFILLDEPTH",            pBFDepth,                     mdfInt,     mxoPar,   NULL },
  { "BACKFILLMAXSCHEDULES",     pBFMaxSchedules,              mdfInt,     mxoPar,   NULL },
  { "BACKFILLMETRIC",           pBFMetric,                    mdfString,  mxoPar,   NULL },
  { "BACKFILLPOLICY",           pBFPolicy,                    mdfString,  mxoPar,   NULL },
  { "BACKFILLPROCFACTOR",       pBFProcFactor,                mdfInt,     mxoPar,   NULL },
  { "BACKFILLTYPE",             pBFType,                      mdfString,  mxoPar,   NULL },
  { "BANKAPPENDMACHINENAME",    pAMAppendMachineName,         mdfString,  mxoAM,    NULL },
  { "BANKCHARGEPOLICY",         pAMChargePolicy,              mdfString,  mxoAM,    NULL },
  { "BANKDEFERONJOBFAILURE",    pAMDeferOnJobFailure,         mdfString,  mxoAM,    NULL },
  { "BANKFALLBACKACCOUNT",      pAMFallbackAccount,           mdfString,  mxoAM,    NULL },
  { "BANKFLUSHINTERVAL",        pAMFlushInterval,             mdfString,  mxoAM,    NULL },
  { "BANKHOST",                 pAMHost,                      mdfString,  mxoAM,    NULL },
  { "BANKPORT",                 pAMPort,                      mdfInt,     mxoAM,    NULL },
  { "BANKPROTOCOL",             pAMProtocol,                  mdfString,  mxoAM,    NULL },
  { "BANKSERVER",               pOLDBankServer,               mdfString,  mxoAM,    NULL },
  { "BANKTIMEOUT",              pAMTimeout,                   mdfString,  mxoAM,    NULL },
  { "BANKTYPE",                 pAMType,                      mdfString,  mxoAM,    NULL },
  { "BFCHUNKDURATION",          mcoBFChunkDuration,           mdfString,  mxoPar,   NULL },
  { "BFCHUNKSIZE",              mcoBFChunkSize,               mdfInt,     mxoPar,   NULL },
  { "BFPRIORITYPOLICY",         pBFPriorityPolicy,            mdfString,  mxoPar,   NULL },
  { "BYPASSCAP",                pSBPCap,                      mdfInt,     mxoPar,   NULL },
  { "BYPASSWEIGHT",             pSBPWeight,                   mdfInt,     mxoPar,   NULL },
  { "CHECKPOINTEXPIRATIONTIME", pCheckPointExpirationTime,    mdfString,  mxoSched, NULL },
  { "CHECKPOINTFILE",           pCheckPointFile,              mdfString,  mxoSched, NULL },
  { "CHECKPOINTINTERVAL",       pCheckPointInterval,          mdfString,  mxoSched, NULL },
  { "CLASSCAP",                 pCCCap,                       mdfInt,     mxoPar,   NULL },
  { "CLASSWEIGHT",              pCCWeight,                    mdfInt,     mxoPar,   NULL },
  { "CLIENTCFG",                pClientCfg,                   mdfString,  mxoSched, NULL },
  { "CLIENTTIMEOUT",            pClientTimeout,               mdfString,  mxoSched, NULL },
  { "COMINTERFRAMECOST",        pInterFrameCost,              mdfDouble,  mxoSim,   NULL },
  { "COMINTRAFRAMECOST",        pIntraFrameCost,              mdfDouble,  mxoSim,   NULL },
  { "COMPUTEHOSTS",             mcoComputeHosts,              mdfStringArray, mxoSched, NULL },
  { "CONSUMEDCAP",              pUConsCap,                    mdfInt,     mxoPar,   NULL },
  { "CONSUMEDWEIGHT",           pUConsWeight,                 mdfInt,     mxoPar,   NULL },
  { "CREDCAP",                  pCredCap,                     mdfInt,     mxoPar,   NULL },
  { "CREDWEIGHT",               pCredWeight,                  mdfString,  mxoPar,   NULL },
  { "DEFAULTACCOUNT",           pDefaultAccountName,          mdfString,  mxoSched, NULL },
  { "DEFAULTCLASSLIST",         pDefaultClassList,            mdfStringArray, mxoSched, NULL },
  { "DEFAULTDOMAIN",            pDefaultDomain,               mdfString,  mxoSched, NULL },
  { "DEFAULTQMHOST",            pDefaultQMHost,               mdfString,  mxoSched, NULL },
  { "DEFERCOUNT",               pDeferCount,                  mdfInt,     mxoSched, NULL },
  { "DEFERSTARTCOUNT",          pDeferStartCount,             mdfInt,     mxoSched, NULL },
  { "DEFERTIME",                mcoDeferTime,                 mdfString,  mxoSched, NULL },
  { "DIRECTORYSERVER",          mcoDirectoryServer,           mdfString,  mxoSched, NULL },
  { "DIRECTSPECWEIGHT",         pOLDDirectSpecWeight,         mdfInt,     mxoPar,   NULL },
  { "DISKCAP",                  pRDiskCap,                    mdfInt,     mxoPar,   NULL },
  { "DISKWEIGHT",               pRDiskWeight,                 mdfInt,     mxoPar,   NULL },
  { "DISPLAYFLAGS",             pDisplayFlags,                mdfStringArray, mxoSched, NULL },
  { "ENABLEMULTINODEJOBS",      mcoEnableMultiNodeJobs,       mdfString,  mxoPar,   NULL },
  { "ENABLEMULTIREQJOBS",       mcoEnableMultiReqJobs,        mdfString,  mxoPar,   NULL },
  { "ENABLENEGJOBPRIORITY",     mcoEnableNegJobPriority,      mdfString,  mxoPar,   NULL },
  { "EVENTSERVER",              mcoEventServer,               mdfString,  mxoSched, NULL },
  { "FEATURENODETYPEHEADER",    pNodeTypeFeatureHeader,       mdfString,  mxoSched, NULL },
  { "FEATUREPARTITIONHEADER",   pPartitionFeatureHeader,      mdfString,  mxoSched, NULL },
  { "FEATUREPROCSPEEDHEADER",   pProcSpeedFeatureHeader,      mdfString,  mxoSched, NULL },
  { "FEEDBACKPROGRAM",          mcoJobFBAction,               mdfString,  mxoSched, NULL },
  { "ALLOCLOCALITYPOLICY",      mcoAllocLocalityPolicy,       mdfString,  mxoSched, NULL },
  { "FSACCOUNTCAP",             pFACap,                       mdfInt,     mxoPar,   NULL },
  { "FSACCOUNTWEIGHT",          pFAWeight,                    mdfInt,     mxoPar,   NULL },
  { "FSACCOUNTWEIGHT",          pOLDFSAWeight,                mdfInt,     mxoPar,   NULL },
  { "FSCAP",                    pFSCap,                       mdfInt,     mxoPar,   NULL },
  { "FSCLASSCAP",               pFCCap,                       mdfInt,     mxoPar,   NULL },
  { "FSCLASSWEIGHT",            pFCWeight,                    mdfInt,     mxoPar,   NULL },
  { "FSCLASSWEIGHT",            pOLDFSCWeight,                mdfInt,     mxoPar,   NULL },
  { "FSCONFIGFILE",             pFSConfigFile,                mdfString,  mxoPar,   NULL },
  { "FSDECAY",                  pFSDecay,                     mdfDouble,  mxoPar,   NULL },
  { "FSDEPTH",                  pFSDepth,                     mdfInt,     mxoPar,   NULL },
  { "FSENFORCEMENT",            pFSEnforcement,               mdfString,  mxoPar,   NULL },
  { "FSGROUPCAP",               pFGCap,                       mdfInt,     mxoPar,   NULL },
  { "FSGROUPWEIGHT",            pFGWeight,                    mdfInt,     mxoPar,   NULL },
  { "FSGROUPWEIGHT",            pOLDFSGWeight,                mdfInt,     mxoPar,   NULL },
  { "FSINTERVAL",               pFSInterval,                  mdfString,  mxoPar,   NULL },
  { "FSPOLICY",                 pFSPolicy,                    mdfString,  mxoPar,   NULL },
  { "FSQOSCAP",                 pFQCap,                       mdfInt,     mxoPar,   NULL },
  { "FSQOSWEIGHT",              pFQWeight,                    mdfInt,     mxoPar,   NULL },
  { "FSQOSWEIGHT",              pOLDFSQWeight,                mdfInt,     mxoPar,   NULL },
  { "FSSECONDARYGROUPS",        pFSSecondaryGroups,           mdfString,  mxoPar,   NULL },
  { "FSUSERCAP",                pFUCap,                       mdfInt,     mxoPar,   NULL },
  { "FSUSERWEIGHT",             pFUWeight,                    mdfInt,     mxoPar,   NULL },
  { "FSUSERWEIGHT",             pOLDFSUWeight,                mdfInt,     mxoPar,   NULL },
  { "FSWEIGHT",                 pFSWeight,                    mdfString,  mxoPar,   NULL },
  { "GFSWEIGHT",                pOLDGFSWeight,                mdfInt,     mxoPar,   NULL }, 
  { "GROUPCAP",                 pCGCap,                       mdfInt,     mxoPar,   NULL },
  { "GROUPWEIGHT",              pCGWeight,                    mdfInt,     mxoPar,   NULL },
  { "IGNPBSGROUPLIST",          pIgnPbsGroupList,             mdfString,  mxoPar,   NULL },
  { "JOBAGGREGATIONTIME",       pJobAggregationTime,          mdfString,  mxoSched, NULL },
  { "JOBMAXOVERRUN",            pJobMaxOverrun,               mdfString,  mxoSched, NULL },
  { "JOBMAXSTARTTIME",          pMaxJobStartTime,             mdfString,  mxoPar,   NULL },
  { "JOBNODEMATCHPOLICY",       pJobNodeMatch,                mdfStringArray, mxoPar, NULL },
  { "JOBPRIOACCRUALPOLICY",     pJobPrioAccrualPolicy,        mdfString,  mxoPar,   NULL },
  { "JOBPRIOF",                 mcoJobAttrPrioF,              mdfString,  mxoPar,   NULL },
  { "JOBPURGETIME",             pJobPurgeTime,                mdfString,  mxoSched, NULL },
  { "JOBSIZEPOLICY",            pJobSizePolicy,               mdfString,  mxoPar,   NULL },
  { "JOBSYNCTIME",              pJobSyncDeadline,             mdfString,  mxoSched, NULL },
  { "LOCKFILE",                 pSchedLockFile,               mdfString,  mxoSched, NULL },
  { "MACHINECONFIGFILE",        pMachineConfigFile,           mdfString,  mxoSched, NULL },
  { "MAILPROGRAM",              mcoMailAction,                mdfString,  mxoSched, NULL },
  { "MAXJOBPERACCOUNTCOUNT",    pHMaxJobPerAccountCount,      mdfInt,     mxoSched, NULL },
  { "MAXJOBPERACCOUNTPOLICY",   pMaxJobPerAccountPolicy,      mdfString,  mxoSched, NULL },
  { "MAXJOBPERGROUPCOUNT",      pHMaxJobPerGroupCount,        mdfInt,     mxoSched, NULL }, 
  { "MAXJOBPERGROUPPOLICY",     pMaxJobPerGroupPolicy,        mdfString,  mxoSched, NULL },
  { "MAXJOBPERITERATION",       pMaxJobPerIteration,          mdfInt,     mxoSched, NULL },
  { "MAXJOBPERUSERCOUNT",       pHMaxJobPerUserCount,         mdfInt,     mxoSched, NULL },
  { "MAXJOBPERUSERPOLICY",      pMaxJobPerUserPolicy,         mdfString,  mxoSched, NULL },
  { "MAXJOBQUEUEDPERACCOUNTCOUNT", pHMaxJobQueuedPerAccountCount, mdfInt, mxoSched, NULL },
  { "MAXJOBQUEUEDPERACCOUNTPOLICY", pMaxJobQueuedPerAccountPolicy, mdfString, mxoSched, NULL },
  { "MAXJOBQUEUEDPERGROUPCOUNT", pHMaxJobQueuedPerGroupCount, mdfInt,     mxoSched, NULL },
  { "MAXJOBQUEUEDPERGROUPPOLICY", pMaxJobQueuedPerGroupPolicy, mdfString, mxoSched, NULL },
  { "MAXJOBQUEUEDPERUSERCOUNT", pHMaxJobQueuedPerUserCount,   mdfInt,     mxoSched, NULL },
  { "MAXJOBQUEUEDPERUSERPOLICY", pMaxJobQueuedPerUserPolicy,  mdfString,  mxoSched, NULL },
  { "MAXNODEPERUSERCOUNT",      pHMaxNodePerUserCount,        mdfInt,     mxoSched, NULL },
  { "MAXNODEPERUSERPOLICY",     pMaxNodePerUserPolicy,        mdfString,  mxoSched, NULL },
  { "MAXPEPERUSERCOUNT",        pHMaxPEPerUserCount,          mdfInt,     mxoSched, NULL },
  { "MAXPEPERUSERPOLICY",       pMaxPEPerUserPolicy,          mdfString,  mxoSched, NULL },
  { "MAXPROCPERACCOUNTCOUNT",   pHMaxNodePerAccountCount,     mdfInt,     mxoSched, NULL },
  { "MAXPROCPERACCOUNTPOLICY",  pMaxNodePerAccountPolicy,     mdfString,  mxoSched, NULL },
  { "MAXPROCPERGROUPCOUNT",     pHMaxNodePerGroupCount,       mdfInt,     mxoSched, NULL },
  { "MAXPROCPERGROUPPOLICY",    pMaxNodePerGroupPolicy,       mdfString,  mxoSched, NULL },
  { "MAXPROCPERUSERCOUNT",      pHMaxProcPerUserCount,        mdfInt,     mxoSched, NULL },
  { "MAXPROCPERUSERPOLICY",     pMaxProcPerUserPolicy,        mdfString,  mxoSched, NULL },
  { "MAXPROCSECONDPERACCOUNTCOUNT", pHMaxPSPerAccountCount,   mdfInt,     mxoSched, NULL },
  { "MAXPROCSECONDPERACCOUNTPOLICY", pMaxPSPerAccountPolicy,  mdfString,  mxoSched, NULL },
  { "MAXPROCSECONDPERGROUPCOUNT", pHMaxPSPerGroupCount,       mdfInt,     mxoSched, NULL },
  { "MAXPROCSECONDPERGROUPPOLICY", pMaxPSPerGroupPolicy,      mdfString,  mxoSched, NULL },
  { "MAXPROCSECONDPERUSERCOUNT", pHMaxPSPerUserCount,         mdfInt,     mxoSched, NULL },
  { "MAXPROCSECONDPERUSERPOLICY", pMaxPSPerUserPolicy,        mdfString,  mxoSched, NULL },
  { "MAXSLEEPITERATION",        pMaxSleepIteration,           mdfInt,     mxoSched, NULL },
  { "MCSOCKETPROTOCOL",         pMCSocketProtocol,            mdfString,  mxoSched, NULL },
  { "MEMCAP",                   pRMemCap,                     mdfInt,     mxoPar,   NULL },
  { "MEMWEIGHT",                pRMemWeight,                  mdfInt,     mxoPar,   NULL },
  { "METAMAXTASKS",             pMaxMetaTasks,                mdfInt,     mxoSched, NULL },
  { "MINADMINSTIME",            mcoAdminMinSTime,             mdfString,  mxoSched, NULL },
  { "MINDISPATCHTIME",          pMinDispatchTime,             mdfString,  mxoSched, NULL },
  { "NODEACCESSPOLICY",         pNAPolicy,                    mdfString,  mxoSched, NULL },
  { "NODEALLOCMAXPS",           pNAMaxPS,                     mdfString,  mxoSched, NULL },
  { "NODEALLOCATIONPOLICY",     pNodeAllocationPolicy,        mdfString,  mxoPar,   NULL },
  { "NODECAP",                  pRNodeCap,                    mdfInt,     mxoPar,   NULL },
  { "NODECPUOVERCOMMITFACTOR",  pNodeCPUOverCommitFactor,     mdfDouble,  mxoSched, NULL }, 
  { "NODEDOWNSTATEDELAYTIME",   pNodeDownStateDelayTime,      mdfString,  mxoSched, NULL },
  { "NODELOADPOLICY",           pNodeLoadPolicy,              mdfString,  mxoPar,   NULL },
  { "NODEMAXLOAD",              pNodeMaxLoad,                 mdfDouble,  mxoSched, NULL },
  { "NODEMEMOVERCOMMITFACTOR",  pNodeMemOverCommitFactor,     mdfDouble,  mxoSched, NULL },
  { "NODEPOLLFREQUENCY",        pNodePollFrequency,           mdfInt,     mxoSched, NULL },
  { "NODEPURGETIME",            pNodePurgeTime,               mdfString,  mxoSched, NULL },
  { "NODESETATTRIBUTE",         pNodeSetAttribute,            mdfString,  mxoPar,   NULL },
  { "NODESETDELAY",             pNodeSetDelay,                mdfString,  mxoPar,   NULL },
  { "NODESETLIST",              pNodeSetList,                 mdfStringArray, mxoPar, NULL },
  { "NODESETPOLICY",            pNodeSetPolicy,               mdfString,  mxoPar,   NULL },
  { "NODESETPRIORITYTYPE",      pNodeSetPriorityType,         mdfString,  mxoPar,   NULL },
  { "NODESETTOLERANCE",         pNodeSetTolerance,            mdfDouble,  mxoPar,   NULL },
  { "NODESYNCTIME",             pNodeSyncDeadline,            mdfString,  mxoSched, NULL },
  { "NODEUNTRACKEDLOADFACTOR",  pNodeUntrackedProcFactor,     mdfDouble,  mxoSched, NULL },
  { "NODEWEIGHT",               pRNodeWeight,                 mdfInt,     mxoPar,   NULL },
  { "NOTIFICATIONINTERVAL",     pAdminEInterval,              mdfString,  mxoSched, NULL },
  { "NOTIFICATIONPROGRAM",      pAdminEAction,                mdfString,  mxoSched, NULL },
  { "PARIGNQUEUELIST",          pParIgnQList,                 mdfStringArray, mxoSched, NULL },
  { "PECAP",                    pRPECap,                      mdfInt,     mxoPar,   NULL },
  { "PERCENTCAP",               pUPerCCap,                    mdfInt,     mxoPar,   NULL },
  { "PERCENTWEIGHT",            pUPerCWeight,                 mdfInt,     mxoPar,   NULL },
  { "PEWEIGHT",                 pRPEWeight,                   mdfInt,     mxoPar,   NULL },
  { "PLOTMAXPROC",              pPlotMaxNode,                 mdfInt,     mxoSched, NULL },
  { "PLOTMAXTIME",              pPlotMaxTime,                 mdfString,  mxoSched, NULL },
  { "PLOTMINPROC",              pPlotMinNode,                 mdfInt,     mxoSched, NULL },
  { "PLOTMINTIME",              pPlotMinTime,                 mdfString,  mxoSched, NULL },
  { "PLOTPROCSCALE",            pPlotNodeScale,               mdfInt,     mxoSched, NULL },
  { "PLOTTIMESCALE",            pPlotTimeScale,               mdfInt,     mxoSched, NULL },
  { "PREEMPTPOLICY",            pPreemptPolicy,               mdfString,  mxoSched, NULL },
  { "PROCCAP",                  pRProcCap,                    mdfInt,     mxoPar,   NULL },
  { "PROCWEIGHT",               pRProcWeight,                 mdfInt,     mxoPar,   NULL },
  { "PSCAP",                    pRPSCap,                      mdfInt,     mxoPar,   NULL },
  { "PSWEIGHT",                 pRPSWeight,                   mdfInt,     mxoPar,   NULL },
  { "QOSCAP",                   pCQCap,                       mdfInt,     mxoPar,   NULL },
  { "QOSFLAGS",                 pQOSFlags,                    mdfStringArray, mxoQOS, NULL },
  { "QOSNAME",                  pQOSName,                     mdfString,  mxoQOS,   NULL },
  { "QOSPRIORITY",              pQOSPriority,                 mdfInt,     mxoQOS,   NULL },
  { "QOSQTWEIGHT",              pQOSQTWeight,                 mdfInt,     mxoQOS,   NULL },
  { "QOSTARGETQT",              pQOSTargetQT,                 mdfInt,     mxoQOS,   NULL },
  { "QOSTARGETXF",              pQOSTargetXF,                 mdfDouble,  mxoQOS,   NULL },
  { "QOSWEIGHT",                pCQWeight,                    mdfInt,     mxoPar,   NULL },
  { "QOSXFWEIGHT",              pQOSXFWeight,                 mdfInt,     mxoQOS,   NULL },
  { "QUEUETIMECAP",             pSQTCap,                      mdfInt,     mxoPar,   NULL },
  { "QUEUETIMETARGETWEIGHT",    pOLDQTWeight,                 mdfInt,     mxoPar,   NULL },
  { "QUEUETIMEWEIGHT",          pSQTWeight,                   mdfInt,     mxoPar,   NULL }, 
  { "REJECTNEGPRIOJOBS",        mcoRejectNegPrioJobs,         mdfString,  mxoPar,   NULL },
  { "REMAININGCAP",             pURemCap,                     mdfInt,     mxoPar,   NULL },
  { "REMAININGWEIGHT",          pURemWeight,                  mdfInt,     mxoPar,   NULL },
  { "REMOTESTARTCOMMAND",       pRemoteStartCommand,          mdfString,  mxoSched, NULL },
  { "RESCAP",                   pResCap,                      mdfInt,     mxoPar, NULL },
  { "RESCTLPOLICY",             pResCtlPolicy,                mdfString,  mxoSched, NULL },
  { "RESDEPTH",                 pResDepth,                    mdfInt,     mxoSched, NULL },
  { "RESERVATIONDEPTH",         pReservationDepth,            mdfInt,     mxoSched, NULL },
  { "RESERVATIONPOLICY",        pResPolicy,                   mdfString,  mxoPar,   NULL },
  { "RESERVATIONQOSLIST",       pResQOSList,                  mdfStringArray, mxoSched, NULL },
  { "RESERVATIONRETRYTIME",     pResRetryTime,                mdfString,  mxoPar,   NULL },
  { "RESERVATIONTHRESHOLDTYPE", pResThresholdType,            mdfString,  mxoPar,   NULL },
  { "RESERVATIONTHRESHOLDVALUE", pResThresholdValue,          mdfInt,     mxoPar,   NULL },
  { "RESLIMITPOLICY",           mcoResLimitPolicy,            mdfString,  mxoSched, NULL },   
  { "NODEAVAILABILITYPOLICY",   pNodeAvailPolicy,             mdfStringArray, mxoPar, NULL },
  { "RESOURCECOLLECTIONPOLICY", pResourceCollectionPolicy,    mdfString,  mxoSched, NULL },
  { "RESOURCEDAEMON",           pResourceCommand,             mdfString,  mxoSched, NULL },
  { "RESOURCEDATAFILE",         pResourceDataFile,            mdfString,  mxoSched, NULL },
  { "RESOURCELIMITPOLICY",      mcoResourceLimitPolicy,       mdfStringArray, mxoPar, NULL },
  { "RESOURCELOCKFILE",         pResourceLockFile,            mdfString,  mxoSched, NULL },
  { "RESOURCEPORT",             pResourcePort,                mdfInt,     mxoSched, NULL },
  { "RESOURCEREPORTWAIT",       pResourceReportWait,          mdfInt,     mxoSched, NULL },
  { "RESOURCESAMPLEINTERVAL",   pResourceSampleInterval,      mdfInt,     mxoSched, NULL },
  { "RESWEIGHT",                pResWeight,                   mdfString,  mxoPar, NULL },
  { "RMAUTHTYPE",               pRMAuthType,                  mdfString,  mxoRM, NULL },
  { "RMCONFIGFILE",             pRMConfigFile,                mdfString,  mxoRM, NULL },
  { "RMEPORT",                  mcoRMEPort,                   mdfInt,     mxoRM, NULL },
  { "RMHOST",                   pRMHost,                      mdfString,  mxoRM, NULL },
  { "RMLOCALDISKFS",            pRMLocalDiskFS,               mdfString,  mxoRM, NULL }, 
  { "RMNAME",                   pRMName,                      mdfString,  mxoRM, NULL },
  { "RMNMPORT",                 pRMNMPort,                    mdfInt,     mxoRM, NULL },
  { "RMPOLLINTERVAL",           pRMPollInterval,              mdfString,  mxoSched, NULL },
  { "RMPORT",                   pRMPort,                      mdfInt,     mxoRM, NULL },
  { "RMSERVER",                 pOLDRMServer,                 mdfString,  mxoRM, NULL },
  { "RMTIMEOUT",                pRMTimeout,                   mdfString,  mxoRM, NULL },
  { "RMTYPE",                   pRMType,                      mdfString,  mxoRM, NULL },
  { "SERVERCONFIGFILE",         pSchedConfigFile,             mdfString,  mxoSched, NULL },
  { "SERVERHOMEDIR",            pMServerHomeDir,              mdfString,  mxoSched, NULL },
  { "SERVERHOST",               pServerHost,                  mdfString,  mxoSched, NULL },
  { "SERVERMODE",               pSchedMode,                   mdfString,  mxoSched, NULL },
  { "SERVERNAME",               pServerName,                  mdfString,  mxoSched, NULL },
  { "SERVERPORT",               pServerPort,                  mdfInt,     mxoSched, NULL },
  { "SERVICETARGETWEIGHT",      pOLDServWeight,               mdfInt,     mxoPar, NULL },
  { "SERVICEWCAP",              pServCap,                     mdfInt,     mxoPar, NULL },
  { "SERVICEWEIGHT",            pServWeight,                  mdfString,  mxoPar, NULL },
  { "SIMAUTOSHUTDOWN",          pSimAutoShutdown,             mdfString,  mxoSim, NULL },
  { "SIMCHECKPOINTINTERVAL",    pSimCheckpointInterval,       mdfString,  mxoSim, NULL },
  { "SIMCOMRATE",               pComRate,                     mdfDouble,  mxoSim,   NULL },
  { "SIMCOMTYPE",               pCommunicationType,           mdfString,  mxoSim,   NULL },
  { "SIMDEFAULTJOBFLAGS",       pSimDefaultJobFlags,          mdfStringArray, mxoSim, NULL },
  { "SIMEXITITERATION",         pExitIteration,               mdfInt,     mxoSim, NULL },
  { "SIMFLAGS",                 pSimFlags,                    mdfStringArray, mxoSim, NULL },
  { "SIMIGNOREJOBFLAGS",        pSimIgnoreJobFlags,           mdfStringArray, mxoSim, NULL },
  { "SIMINITIALQUEUEDEPTH",     pSimInitialQueueDepth,        mdfInt,     mxoSim, NULL },
  { "SIMJOBSUBMISSIONPOLICY",   pSimJobSubmissionPolicy,      mdfString,  mxoSim, NULL },
  { "SIMNODECONFIGURATION",     pSimNCPolicy,                 mdfString,  mxoSim, NULL },
  { "SIMNODECOUNT",             pSimNodeCount,                mdfInt,     mxoSim, NULL },
  { "SIMRANDOMIZEJOBSIZE",      pRandomizeJobSize,            mdfString,  mxoSim, NULL },
  { "SIMRESOURCETRACEFILE",     pResourceTraceFile,           mdfString,  mxoSim, NULL },
  { "SIMSCALEJOBRUNTIME",       pSimScaleJobRunTime,          mdfString,  mxoSim, NULL },
  { "SIMSTARTTIME",             pSimStartTime,                mdfString,  mxoSim, NULL },
  { "SIMSTOPITERATION",         pStopIteration,               mdfInt,     mxoSim, NULL },
  { "SIMTIMEPOLICY",            mcoTimePolicy,                mdfString,  mxoSim, NULL },
  { "SIMWCACCURACYCHANGE",      pSimWCAccuracyChange,         mdfDouble,  mxoSim, NULL },
  { "SIMWCACCURACY",            pSimWCAccuracy,               mdfDouble,  mxoSim, NULL },
  { "SIMWCSCALINGPERCENT",      pSimWCScalingPercent,         mdfInt,     mxoSim, NULL },
  { "SIMWORKLOADTRACEFILE",     pWorkloadTraceFile,           mdfString,  mxoSim, NULL },
  { "SMAXJOBPERACCOUNTCOUNT",   pMaxJobPerAccountCount,       mdfInt,     mxoSched, NULL },
  { "SMAXJOBPERGROUPCOUNT",     pMaxJobPerGroupCount,         mdfInt,     mxoSched, NULL }, 
  { "SMAXJOBPERUSERCOUNT",      pMaxJobPerUserCount,          mdfInt,     mxoSched, NULL },
  { "SMAXJOBQUEUEDPERACCOUNTCOUNT", pMaxJobQueuedPerAccountCount, mdfInt, mxoSched, NULL },
  { "SMAXJOBQUEUEDPERGROUPCOUNT", pMaxJobQueuedPerGroupCount, mdfInt,     mxoSched, NULL },
  { "SMAXJOBQUEUEDPERUSERCOUNT", pMaxJobQueuedPerUserCount,   mdfInt,     mxoSched, NULL },
  { "SMAXNODEPERUSERCOUNT",     pMaxNodePerUserCount,         mdfInt,     mxoSched, NULL },
  { "SMAXPEPERUSERCOUNT",       pMaxPEPerUserCount,           mdfInt,     mxoSched, NULL },
  { "SMAXPROCPERACCOUNTCOUNT",  pMaxNodePerAccountCount,      mdfInt,     mxoSched, NULL },
  { "SMAXPROCPERGROUPCOUNT",    pMaxNodePerGroupCount,        mdfInt,     mxoSched, NULL },
  { "SMAXPROCPERUSERCOUNT",     pMaxProcPerUserCount,         mdfInt,     mxoSched, NULL },
  { "SMAXPROCSECONDPERACCOUNTCOUNT", pMaxPSPerAccountCount,   mdfInt,     mxoSched, NULL },
  { "SMAXPROCSECONDPERGROUPCOUNT", pMaxPSPerGroupCount,       mdfInt,     mxoSched, NULL },
  { "SMAXPROCSECONDPERUSERCOUNT", pMaxPSPerUserCount,         mdfInt,     mxoSched, NULL },
  { "SPVIOLATIONCAP",           pSSPVCap,                     mdfInt,     mxoPar,   NULL },
  { "SPVIOLATIONWEIGHT",        pSSPVWeight,                  mdfInt,     mxoPar,   NULL },
  { "SRACCESS",                 pSRAccess,                    mdfString,  mxoSRes,  NULL },
  { "SRACCOUNTLIST",            pSRAccountList,               mdfStringArray, mxoSRes, NULL },
  { "SRCHARGEACCOUNT",          pSRChargeAccount,             mdfString,  mxoSRes,  NULL },
  { "SRCLASSLIST",              pSRClassList,                 mdfStringArray, mxoSRes, NULL },
  { "SRDAYS",                   pSRDays,                      mdfStringArray, mxoSRes, NULL },
  { "SRDEPTH",                  pSRDepth,                     mdfInt,     mxoSRes,  NULL },
  { "SRENDTIME",                pSREndTime,                   mdfString,  mxoSRes,  NULL },
  { "SRFEATURES",               pSRFeatures,                  mdfStringArray, mxoSRes, NULL },
  { "SRFLAGS",                  pSRFlags,                     mdfStringArray, mxoSRes, NULL },
  { "SRGROUPLIST",              pSRGroupList,                 mdfStringArray, mxoSRes, NULL },
  { "SRHOSTLIST",               pSRHostList,                  mdfStringArray, mxoSRes, NULL },
  { "SRIDLETIME",               pSRIdleTime,                  mdfString,  mxoSRes,  NULL },
  { "SRMAXTASKS",               pSRMaxTasks,                  mdfInt,     mxoSRes,  NULL },
  { "SRMAXTIME",                pSRMaxTime,                   mdfString,  mxoSRes,  NULL },
  { "SRMINLOAD",                pSRMinLoad,                   mdfString,  mxoSRes,  NULL },
  { "SRMINTASKS",               pSRMinTasks,                  mdfInt,     mxoSRes,  NULL },
  { "SRNAME",                   pSRName,                      mdfString,  mxoSRes,  NULL },
  { "SRPARTITION",              pSRPartition,                 mdfString,  mxoSRes,  NULL },
  { "SRPERIOD",                 pSRPeriod,                    mdfString,  mxoSRes,  NULL },
  { "SRPRIORITY",               pSRPriority,                  mdfInt,     mxoSRes,  NULL },
  { "SRQOSLIST",                pSRQOSList,                   mdfStringArray, mxoSRes, NULL },
  { "SRRESOURCES",              pSRResources,                 mdfString,  mxoSRes,  NULL },
  { "SRSTARTTIME",              pSRStartTime,                 mdfString,  mxoSRes,  NULL }, 
  { "SRTASKCOUNT",              pSRTaskCount,                 mdfInt,     mxoSRes,  NULL },
  { "SRTIMELOGIC",              pSRTimeLogic,                 mdfString,  mxoSRes,  NULL },
  { "SRTPN",                    pSRTPN,                       mdfInt,     mxoSRes,  NULL },
  { "SRUSERLIST",               pSRUserList,                  mdfStringArray, mxoSRes, NULL },
  { "SRWENDTIME",               pSRWEndTime,                  mdfString,  mxoSRes,  NULL },
  { "SRWSTARTTIME",             pSRWStartTime,                mdfString,  mxoSRes,  NULL },
  { "STATDIR",                  pStatDir,                     mdfString,  mxoSched, NULL },
  { "STEPCOUNT",                pSchedStepCount,              mdfInt,     mxoSched, NULL },
  { "SWAPCAP",                  pRSwapCap,                    mdfInt,     mxoPar,   NULL },
  { "SWAPWEIGHT",               pRSwapWeight,                 mdfInt,     mxoPar,   NULL },
  { "SYSTEMMAXJOBWALLTIME",     pSystemMaxJobTime,            mdfString,  mxoPar,   NULL },
  { "SYSTEMMAXPROCPERJOB",      pSystemMaxJobProc,            mdfInt,     mxoPar,   NULL },
  { "SYSTEMMAXPROCSECONDPERJOB", pSystemMaxJobPS,             mdfInt,     mxoPar,   NULL },
  { "TARGETCAP",                pTargCap,                     mdfInt,     mxoPar,   NULL },
  { "TARGETQUEUETIMECAP",       pTQTCap,                      mdfInt,     mxoPar,   NULL },
  { "TARGETQUEUETIMEWEIGHT",    pTQTWeight,                   mdfInt,     mxoPar,   NULL },
  { "TARGETWEIGHT",             pTargWeight,                  mdfString,  mxoPar,   NULL },
  { "TARGETXFACTORCAP",         pTXFCap,                      mdfInt,     mxoPar,   NULL },
  { "TARGETXFACTORWEIGHT",      pTXFWeight,                   mdfInt,     mxoPar,   NULL },
  { "TASKDISTRIBUTIONPOLICY",   pTaskDistributionPolicy,      mdfString,  mxoPar,   NULL },
  { "TOOLSDIR",                 pSchedToolsDir,               mdfString,  mxoSched, NULL },
  { "TRAPFUNCTION",             pMonitoredFunction,           mdfString,  mxoSched, NULL },
  { "TRAPJOB",                  pMonitoredJob,                mdfString,  mxoSched, NULL },
  { "TRAPNODE",                 pMonitoredNode,               mdfString,  mxoSched, NULL },
  { "TRAPRES",                  pMonitoredRes,                mdfString,  mxoSched, NULL },
  { "UFSWEIGHT",                pOLDUFSWeight,                mdfInt,     mxoPar,   NULL },
  { "UJOBWEIGHT",               pRUJobWeight,                 mdfInt,     mxoPar,   NULL },
  { "UPROCWEIGHT",              pRUProcWeight,                mdfInt,     mxoPar,   NULL },
  { "USAGEEXECUTIONTIMECAP",    pUExeTimeCap,                 mdfInt,     mxoPar,   NULL },
  { "USAGEEXECUTIONTIMEWEIGHT", pUExeTimeWeight,              mdfInt,     mxoPar,   NULL },
  { "USAGECAP",                 pUsageCap,                    mdfInt,     mxoPar,   NULL },
  { "USAGEWEIGHT",              pUsageWeight,                 mdfString,  mxoPar,   NULL },
  { "USECPUTIME",               pUseCPUTime,                  mdfString,  mxoPar,   NULL },
  { "USEJOBREGEX",              mcoUseJobRegEx,               mdfString,  mxoSched, NULL },
  { "USELOCALMACHINEPRIORITY",  pUseLocalMachinePriority,     mdfString,  mxoSched, NULL },
  { "USEMACHINESPEED",          pUseMachineSpeed,             mdfString,  mxoSched, NULL },
  { "USEMACHINESPEEDFORFS",     pUseMachineSpeedForFS,        mdfString,  mxoSched, NULL },
  { "USERCAP",                  pCUCap,                       mdfInt,     mxoPar,   NULL },
  { "USERWEIGHT",               pCUWeight,                    mdfInt,     mxoPar,   NULL },
  { "USESYSLOG",                mcoUseSyslog,                 mdfString,  mxoSched, NULL },
  { "USESYSTEMQUEUETIME",       pUseSystemQueueTime,          mdfString,  mxoPar,   NULL },
  { "WALLTIMECAP",              pRWallTimeCap,                mdfInt,     mxoPar,   NULL }, 
  { "WALLTIMEWEIGHT",           pRWallTimeWeight,             mdfInt,     mxoPar,   NULL },
  { "WCVIOLATIONACTION",        mcoWCViolAction,              mdfString,  mxoSched, NULL },
  { "XFACTORCAP",               pSXFCap,                      mdfInt,     mxoPar,   NULL },
  { "XFACTORTARGETWEIGHT",      pOLDXFWeight,                 mdfInt,     mxoPar,   NULL },
  { "XFACTORWEIGHT",            pSXFWeight,                   mdfInt,     mxoPar,   NULL },
  { "XFMINWCLIMIT",             pXFMinWCLimit,                mdfString,  mxoPar,   NULL },
  { NULL,                       -1,                           -1,         -1,       NULL } };


/* preempt policies */

const char *MPreemptPolicy[] = {
  NONE,
  "REQUEUE",
  "SUSPEND",
  "CHECKPOINT",
  "OVERCOMMIT",
  NULL };

/* resctl polices */

const char *MResCtlPolicy[] = {
  NONE,
  "ADMINONLY",
  "ANY",
  NULL };

/* resource types */

/* NOTE:  sync with MResLimitResourceEnum, MResourceTypeEnum */

const char *MResourceType[] = {
  NONE,
  "NODE",
  "PROC",
  "MEM",
  "SWAP",
  "DISK",
  NULL };

/* object types */

/* NOTE:  MAttrO must be sync'd with MAttrEnum, MAX_MATTRTYPE */

const char *MAttrO[] = {
  "NONE",
  "JOB",
  "NODE",
  "RES",
  "USER",
  "GROUP",
  "ACCT",
  "PAR",
  "SCHED",
  "SYSTEM",
  "CLASS",
  "QOS",
  "JFEATURE",
  "DURATION",
  "TASK",
  "PROC",
  "FRAME",
  "QUEUE",
  "CLUSTER",
  NULL };

const char *MXO[] = {
  NONE,
  "acct",
  "am",
  "class",
  "cluster",
  "cp",
  "frame",
  "fs",
  "group",
  "job",
  "limits",
  "node",
  "par",
  "priority",
  "qos",
  "queue",
  "range",
  "req",
  "rsv",
  "rm",
  "sched",
  "sim",
  "sres",
  "stats",
  "sys",
  "user",
  NULL };

const char *MXOC[] = {
  NONE,
  "ACCT",
  "AM",
  "CLASS",
  "CLUSTER",
  "CP",
  "FRAME",
  "FS",
  "GROUP",
  "JOB",
  "LIMITS",
  "NODE",
  "PAR",
  "PRIORITY",
  "QOS",
  "QUEUE",
  "RANGE",
  "REQ",
  "RSV",
  "RM",
  "SCHED",
  "SIM",
  "SRES",
  "STATS",
  "SYS",
  "USER",
  NULL };

const char *MHRObj[] = {
  "NONE",
  "job",
  "node",
  "reservation",
  "user",
  "group",
  "account",
  "partition",
  "scheduler",
  "system",
  "class",
  "QOS",
  "jobfeature",
  "duration",
  "task",
  "proc",
  "frame",
  "queue",
  "cluster",
  NULL };
 
const char *MWeekDay[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", NULL};
const char *MWEEKDAY[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT", NULL};

const char *ResModeS[] = {
  "InclusiveShared",
  "ExclusiveShared",
  "ExclusivePrivate",
  "Ignored",
  NULL };

const char *MCBType[] = {
  "RESCANCEL",
  "RESSTART",
  "RESEND",
  "JOBSTART",
  "JOBEND",
  "JOBSTAGE",
  NULL };

const char *MRMAuthType[]  = { 
  "NONE", 
  "CHECKSUM", 
  "PKI", 
  "SECUREPORT", 
  NULL };

const char *WMCommandList[] = {
  "NONE",
  "SUBMITJOB",
  "GETJOBS",
  "GETNODES",
  "UPDATEJOB",
  "STARTJOB",
  "CANCELJOB",
  "SUSPENDJOB",
  "RESUMEJOB",
  "CHECKPOINTJOB",
  "MIGRATEJOB",
  "PURGEJOB",
  "STARTTASK",
  "KILLTASK",
  "SUSPENDTASK",
  "RESUMETASK",
  "GETTASKSTATUS",
  "GETNODESTATUS",
  "GETJOBSTATUS",
  "UPDATETASKSTATUS",
  "UPDATENODESTATUS",
  "UPDATEJOBSTATUS",
  "ALLOCATENODE",
  "STARTNODEMAN",
  "SPAWNTASKMAN",
  "SPAWNJOBMAN",
  "RECONFIG",
  "SHUTDOWN",
  "DIAGNOSE",
  "REPARENT",
  NULL };

const char *WikiNodeAttribute[] = {
  "NONE"
  "UpdateTime",
  "State",
  "OS",
  "Arch",
  "CacheSize",
  "L2CacheSize",
  "ConfMemory",
  "AvailMemory",
  "ConfSwap",
  "AvailSwap",
  "ConfLocalDisk",
  "AvailLocalDisk",
  "ConfProcCount",
  "AvailProcCount",
  "ConfNetworkList",
  "AvailNetworkList",
  "CPULoad",
  "MaxTasks",
  NULL
  };

const char *MWikiNodeAttr[] = {
  "NONE",
  "UPDATETIME",
  "STATE",
  "OS",
  "ARCH",
  "CMEMORY",
  "AMEMORY",
  "CSWAP",
  "ASWAP",
  "CDISK",
  "ADISK",
  "CPROC", 
  "APROC",
  "CNET",
  "ANET",
  "CRES",
  "ARES",
  "CPULOAD",
  "CCLASS",
  "ACLASS",
  "FEATURE",
  "PARTITION",
  "EVENT",
  "CURRENTTASK",
  "MAXTASK",
  "SPEED",
  "NAME",
  NULL };

const char *MWikiJobAttr[] = {
  "NONE",
  "UPDATETIME",
  "STATE",
  "WCLIMIT",
  "TASKS",
  "NODES",
  "GEOMETRY",
  "QUEUETIME",
  "STARTDATE",
  "STARTTIME",
  "COMPLETETIME",
  "UNAME",
  "GNAME",
  "ACCOUNT",
  "RFEATURES",
  "RNETWORK",
  "DNETWORK",
  "RCLASS",
  "ROPSYS",
  "RARCH",
  "RMEM",
  "RMEMCMP",
  "DMEM",
  "RDISK",
  "RDISKCMP",
  "DDISK",
  "RSWAP",
  "RSWAPCMP",
  "DSWAP",
  "PARTITIONMASK",
  "EXEC",
  "ARGS",
  "IWD",
  "COMMENT",
  "REJCOUNT",
  "REJMESSAGE",
  "REJCODE",
  "EVENT",
  "TASKLIST",
  "TASKPERNODE",
  "QOS",
  "ENDDATE",
  "DPROCS",
  "HOSTLIST",
  "SUSPENDTIME",
  "RESACCESS",
  "NAME",
  "ENV",
  "INPUT",
  "OUTPUT",
  "ERROR",
  "FLAGS",
  "SUBMITSTRING",
  "SUBMITRM",
  NULL
  };

const char *WikiException[] = {
  "NONE",
  "NOREPORT",
  "NOPARENT",
  NULL
  };

const char *WikiStatType[] = {
  "NONE",
  "JOB",
  "NODE",
  NULL 
  };

const char *MJobState[] = {
  "NONE",
  "Idle",
  "Starting",
  "Running",
  "Removed",
  "Completed",
  "Hold",
  "Deferred",
  "SubmitErr",
  "Vacated",
  "NotRun",
  "NotQueued",
  "Unknown",
  "BatchHold",
  "UserHold",
  "SystemHold",
  "Staging",
  "Staged",
  "Suspended",
  "Lost",
  NULL };

const char *MS3CName[] = {
  NONE,
  "system-monitor",
  "queue-manager",
  "scheduler",
  "meta-scheduler",
  "process-manager",
  "allocation-manager",
  "event-manager",
  "service-directory",
  "www",
  NULL };

const char *MS3JobState[] = {
  "NONE",
  "idle",
  "starting",
  "running",
  "removed",
  "completed",
  "held",
  "deferred",
  "submiterr",
  "vacated",
  "notrun",
  "notqueued",
  "unknown",
  "batchhold",
  "userhold",
  "systemhold",
  "staging",
  "staged",
  "suspended",
  "lost",
  NULL };
 
const char *MAMOType[] = {
  NONE,
  "account",
  "class",
  "wallclock",
  "jobid",
  "jobtype",
  "machine",
  "nodetype",
  "procs",
  "proccrate",
  "qos",
  "user",
  NULL };


const char *MSAN[] = {
  NONE,
  "action",
  "args",
  "flags",
  "name",
  "object",
  "op",     
  "option",
  "value",
  NULL };


const char *MSON[] = {
  NONE,
  "Body",
  "Data",
  "Envelope",
  "Get",
  "Object",
  "Request",
  "Response",
  "Set",
  "Where",
  NULL };

/* END MConst.c */            

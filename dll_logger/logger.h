
/*
** prevent multiple inclusion
*/

#ifndef	__LOGGER_H__
#define	__LOGGER_H__

/******************************************************************************
**                                                                           **
** VERSION CONTROL                                                           **
**                                                                           **
******************************************************************************/

#define LOGGER_APPLICATION	"LOGGER"
#define	LOGGER_VERSION		"1.01"


/******************************************************************************
**                                                                           **
**  CONSTANT MACROS                                                          **
**                                                                           **
******************************************************************************/

/*
** maximum number of loggers
*/
#define	LOGGER_MAX_LOGGERS	30

/*
** the default logger identifier
*/
#define	LOGGER_DEFAULT_LOGGER	0

/*
** message classes
*/

#define	LOGGER_BARE				0
#define	LOGGER_INFO				1
#define	LOGGER_WARN				2
#define	LOGGER_ERROR			3
#define	LOGGER_DEBUG			4
#define	LOGGER_AUDIT_SUCCESS	5
#define	LOGGER_AUDIT_FAILURE	6

/*
** message destinations
*/

#define	LOGGER_NONE				  0

#define	LOGGER_FMTONLY			100

#define	LOGGER_ANSI_STDOUT		200
#define	LOGGER_ANSI_FILENAME	201
#define	LOGGER_ANSI_FILEPTR		202
#define	LOGGER_ANSI_FILEHANDLE	203

#define	LOGGER_WIN32_CONSOLE	300
#define	LOGGER_WIN32_FILENAME	301
#define	LOGGER_WIN32_FILEHANDLE	302

#define	LOGGER_WIN32_EVENTLOG	400

#define	LOGGER_SYBASE_SRVLOG	500

#define	LOGGER_UNIX_SYSLOG		600

/*
** maximum (final) message size (including elements added by LOGGER)
*/
#define LOGGER_BUFFERSIZE	5000

/*
** value returned by LoggerGetUnusedLogger if no free loggers are available
*/
#define	LOGGER_NO_UNUSED_LOGGER	-1

/*
** domain for logger identifier
*/
typedef short int LOGGER_ID;

/*
** filter(s) for an existing logger message classes
*/

#define	LOGGER_BARE_FILTER				1
#define	LOGGER_INFO_FILTER				2
#define	LOGGER_WARN_FILTER				4
#define	LOGGER_ERROR_FILTER				8
#define	LOGGER_DEBUG_FILTER				16
#define	LOGGER_AUDIT_SUCCESS_FILTER		32
#define	LOGGER_AUDIT_FAILURE_FILTER		64
#define	LOGGER_ALL_CLASSES_FILTER		((int)0xFFFFFFFF)

/******************************************************************************
**                                                                           **
** COMPILE / LINK / BUILD MACROS                                             **
**                                                                           **
******************************************************************************/

/*
** DLL import and export storage class modifiers for Win32 API
*/
#ifdef	WIN32
#ifndef LOGGER_DLLFN
#define LOGGER_DLLFN	__declspec(dllimport)
#endif

/*
** no storage class modifiers are required for Linux
*/
#else

#ifdef	LOGGER_DLLFN
#undef	LOGGER_DLLFN
#endif
#define LOGGER_DLLFN
#endif

/*
** storage specifications for inclusion in C and C++ programs
*/
#if defined(__cplusplus)
#define	DECL_START	extern "C" {
#define DECL_END	}
#else
#define	DECL_START
#define DECL_END
#endif

/******************************************************************************
**                                                                           **
** FUNCTION PROTOTYPES                                                       **
**                                                                           **
******************************************************************************/

/*
** set/get the debug level
*/
DECL_START
int LOGGER_DLLFN LoggerGetDebugLevel();
DECL_END

DECL_START
int LOGGER_DLLFN LoggerSetDebugLevel(int DbgLvl);
DECL_END

/*
** get the id of the next unused logger
*/
DECL_START
LOGGER_ID LOGGER_DLLFN LoggerGetUnusedLogger();
DECL_END

/*
** mark a logger as unused
*/
DECL_START
void LOGGER_DLLFN LoggerMarkUnused
(
	LOGGER_ID LoggerId
);
DECL_END

/*
** configure an existing logger
*/
DECL_START
int LOGGER_DLLFN LoggerConfigure
(
	LOGGER_ID  LoggerId,
	char      *Hostname,
	char      *Application,
	int        Destination,
	void      *DestDetails1,
	void      *DestDetails2,
	int       *ErrorPtr,
	char      *ErrorMsgPtr
);
DECL_END

/*
** define filter(s) for an existing logger message classes
*/

DECL_START
void LOGGER_DLLFN LoggerSetFilter
(
	LOGGER_ID LoggerId,
	int       FilterAll,
	int       MsgClass,
	int       MsgSeverity,
	int       ThreadId,
	char     *SourceFile,
	char     *FuncName
);
DECL_END

/*
** write a message to a configured logger
*/
DECL_START
void LOGGER_DLLFN LoggerWriteMessage
(
	int   MsgClass,
	int   MsgSeverity,
	int   ThreadId,
	char *SourceFile,
	int   LineNumber,
	char *FuncName,
	char *MsgText,
	...
);
DECL_END

/******************************************************************************
**                                                                           **
** DEBUG MACROS                                                              **
**                                                                           **
******************************************************************************/

/* which target is this? (Debug, Release) */
#ifdef _DEBUG

/* this is the Debug target */
#define	LOGGER_DEBUG_ON
/* compilation message */
#pragma	message("Logger Message: building DEBUG Target")

#else	/* _NDEBUG should be set */

/* this is the Release target */
#ifdef	LOGGER_DEBUG_ON
#undef	LOGGER_DEBUG_ON
#endif
/* compilation message */
#pragma	message("Logger Message: building RELEASE Target")

#endif	/* _DEBUG */

/*
** macros for debug executable
*/
#ifdef	LOGGER_DEBUG_ON

#define	LOGGER_SET_DEBUG_LEVEL(d)	LoggerSetDebugLevel((int)(d));

#define	LOGGER_LOG_DEBUG(m)	if(LoggerGetDebugLevel()>0)	\
	{ LoggerWriteMessage(LOGGER_DEBUG,0,-2,__FILE__,__LINE__,"",m); }
#define	LOGGER_LOG_DEBUG1(m,p1)	if(LoggerGetDebugLevel()>0)	\
	{ LoggerWriteMessage(LOGGER_DEBUG,0,-2,__FILE__,__LINE__,"",m,p1); }
#define	LOGGER_LOG_DEBUG2(m,p1,p2)	if(LoggerGetDebugLevel()>0)	\
	{ LoggerWriteMessage(LOGGER_DEBUG,0,-2,__FILE__,__LINE__,"",m,p1,p2); }
#define	LOGGER_LOG_DEBUG3(m,p1,p2,p3)	if(LoggerGetDebugLevel()>0)	\
	{ LoggerWriteMessage(LOGGER_DEBUG,0,-2,__FILE__,__LINE__,"",m,p1,p2,p3); }
#define	LOGGER_LOG_DEBUG4(m,p1,p2,p3,p4)	if(LoggerGetDebugLevel()>0)	\
	{ LoggerWriteMessage(LOGGER_DEBUG,0,-2,__FILE__,__LINE__,"",m,p1,p2,p3,p4); }

/*
** macros for non-debug executable
*/

#else

#define	LOGGER_SET_DEBUG_LEVEL(d)

#define	LOGGER_LOG_DEBUG(m)
#define	LOGGER_LOG_DEBUG1(m,p1)
#define	LOGGER_LOG_DEBUG2(m,p1,p2)
#define	LOGGER_LOG_DEBUG3(m,p1,p2,p3)
#define	LOGGER_LOG_DEBUG4(m,p1,p2,p3,p4)

#endif

/*
** common macros
*/

#define	LOGGER_LOG_INFO(m)	if(LoggerGetDebugLevel()>=0)	\
	{ LoggerWriteMessage(LOGGER_INFO,0,-2,__FILE__,__LINE__,"",m); }
#define	LOGGER_LOG_INFO1(m,p1)	if(LoggerGetDebugLevel()>=0)	\
	{ LoggerWriteMessage(LOGGER_INFO,0,-2,__FILE__,__LINE__,"",m,p1); }
#define	LOGGER_LOG_INFO2(m,p1,p2)	if(LoggerGetDebugLevel()>=0)	\
	{ LoggerWriteMessage(LOGGER_INFO,0,-2,__FILE__,__LINE__,"",m,p1,p2); }
#define	LOGGER_LOG_INFO3(m,p1,p2,p3)	if(LoggerGetDebugLevel()>=0)	\
	{ LoggerWriteMessage(LOGGER_INFO,0,-2,__FILE__,__LINE__,"",m,p1,p2,p3); }
#define	LOGGER_LOG_INFO4(m,p1,p2,p3,p4)	if(LoggerGetDebugLevel()>=0)	\
	{ LoggerWriteMessage(LOGGER_INFO,0,-2,__FILE__,__LINE__,"",m,p1,p2,p3,p4); }

#define	LOGGER_LOG_ERROR(m)	\
	LoggerWriteMessage(LOGGER_ERROR,0,-2,__FILE__,__LINE__,"",m);
#define	LOGGER_LOG_ERROR1(m,p1)	\
	LoggerWriteMessage(LOGGER_ERROR,0,-2,__FILE__,__LINE__,"",m,p1);
#define	LOGGER_LOG_ERROR2(m,p1,p2)	\
	LoggerWriteMessage(LOGGER_ERROR,0,-2,__FILE__,__LINE__,"",m,p1,p2);
#define	LOGGER_LOG_ERROR3(m,p1,p2,p3)	\
	LoggerWriteMessage(LOGGER_ERROR,0,-2,__FILE__,__LINE__,"",m,p1,p2,p3);
#define	LOGGER_LOG_ERROR4(m,p1,p2,p3,p4)	\
	LoggerWriteMessage(LOGGER_ERROR,0,-2,__FILE__,__LINE__,"",m,p1,p2,p3,p4);

/*
** common filter macros
*/

#define	LOGGER_FILTER_ALL(l)			LoggerSetFilter(l,1,0,0,0,NULL,NULL);

#define	LOGGER_FILTER_DEBUG_ONLY(l)	\
	LoggerSetFilter(l,0,LOGGER_DEBUG_FILTER,-1,-1,(char*)NULL,(char*)NULL);
#define	LOGGER_FILTER_ERROR_ONLY(l)	\
	LoggerSetFilter(l,0,LOGGER_ERROR_FILTER,-1,-1,(char*)NULL,(char*)NULL);
#define	LOGGER_FILTER_ERROR_INFO(l)	\
	LoggerSetFilter(l,0,((LOGGER_ERROR_FILTER)|(LOGGER_INFO_FILTER)),-1,-1,(char*)NULL,(char*)NULL);

#endif

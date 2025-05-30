

// this is the "main" source file
#define	LiteSrv_DLL

// we are exporting the namespace globals
#define	LiteSrv_DLL_EXPORT

// ============================================================================
//
// PROJECT HEADER FILES
//
// ============================================================================

// system headers
#include <string>

// support headers
#include <logger.h>

// class headers
#include "LiteSrv.h"

// ============================================================================
//
// EMBED VERSION INFORMATION
//
// ============================================================================

#ifdef _DEBUG
#define	LiteSrv_VERSION_STRING	"*** " APPLICATION " version " VERSION " [debug] "
#else
#define	LiteSrv_VERSION_STRING	"*** " APPLICATION " version " VERSION ""
#endif
static char __version[] = LiteSrv_VERSION_STRING;
#pragma message(LiteSrv_VERSION_STRING)

// ============================================================================
//
// NAMESPACE DECLARATIONS
//
// ============================================================================

using namespace LiteSrv;

// ============================================================================
//
// EXCEPTION MESSAGES
//
// ============================================================================
#define	COMMAND_FAILED_MESSAGE \
			"Failed to execute a command or program.  Check the program name syntax and parameters."

#define	CREATE_PROCESS_FAILED_MESSAGE \
			"Failed to create a process.  Check the program name, syntax and the PATH variable."

#define	WAIT_FAILED_MESSAGE \
			"Failed to create an event to wait (sleep).  Check system resources."

#define	WATCH_FAILED_MESSAGE \
			"Failed to watch an executing process."

#define	KILL_FAILED_MESSAGE \
			"Failed to kill an executing process."

#define	NOTIFY_FAILED_MESSAGE \
			"Failed to notify the Service Control Manager of the current status of the service."

#define	INVALID_PARAMETER_MESSAGE \
			"An invalid parameter was supplied to a function or method."

#define	GENERAL_ERROR_MESSAGE \
			"An internal error has occurred."

#define	DEFAULT_MESSAGE \
			"An internal error has occurred."

// ============================================================================
//
// GLOBAL NAMESPACE FUNCTIONS
//
// ============================================================================

// ============================================================================
//
// NAMESPACE FUNCTION : LiteSrv::<version methods>
//
// ACCESS SPECIFIER   : global
//
// DESCRIPTION        : get version information
//
// RETURNS            : version information
//
// ============================================================================

const LiteSrv_DLL_API char * LiteSrv::getApplication() { return APPLICATION ; }
const LiteSrv_DLL_API char * LiteSrv::getVersion() { return VERSION ; }


// ============================================================================
//
// PUBLIC MEMBER FUNCTIONS
//
// ============================================================================

// ============================================================================
//
// MEMBER FUNCTION : LiteSrvException::LiteSrvException
//
// ACCESS SPECIFIER: public
//
// DESCRIPTION     : constructor
//
// ARGUMENTS       : pExceptionId  IN exception id
//                   pClassName    IN name of class in which exception occured
//                   pMethodName   IN name of method in which exception occured
//                   pSourceFile   IN source file in which exception occured
//                   pLineNumber   IN line number at which exception occured
//
// ============================================================================
LiteSrvException::LiteSrvException
(
	LiteSrv_EXCEPTION pExceptionId,
	char *pClassName,
	char *pMethodName,
	char *pSourceFile,
	int   pLineNumber
)
{
	LOGGER_LOG_DEBUG1("LiteSrvException::LiteSrvException(%d)",pExceptionId)

	// copy input
	exceptionId = pExceptionId;
	strncpy(className,pClassName,sizeof(className)-1);
	strncpy(methodName,pMethodName,sizeof(methodName)-1);
	strncpy(sourceFile,pSourceFile,sizeof(sourceFile)-1);
	lineNumber = pLineNumber;

	// construct error message
	switch(exceptionId)
	{
		case LiteSrv_EXCEPTION_COMMAND_FAILED:
			strncpy(errorMessage,COMMAND_FAILED_MESSAGE,sizeof(errorMessage)-1);
			break;

		case LiteSrv_EXCEPTION_CREATE_PROCESS_FAILED:
			strncpy(errorMessage,CREATE_PROCESS_FAILED_MESSAGE,sizeof(errorMessage)-1);
			break;

		case LiteSrv_EXCEPTION_WAIT_FAILED:
			strncpy(errorMessage,WAIT_FAILED_MESSAGE,sizeof(errorMessage)-1);
			break;

		case LiteSrv_EXCEPTION_WATCH_FAILED:
			strncpy(errorMessage,WATCH_FAILED_MESSAGE,sizeof(errorMessage)-1);
			break;

		case LiteSrv_EXCEPTION_KILL_FAILED:
			strncpy(errorMessage,KILL_FAILED_MESSAGE,sizeof(errorMessage)-1);
			break;

		case LiteSrv_EXCEPTION_NOTIFY_FAILED:
			strncpy(errorMessage,NOTIFY_FAILED_MESSAGE,sizeof(errorMessage)-1);
			break;

		case LiteSrv_EXCEPTION_INVALID_PARAMETER:
			strncpy(errorMessage,INVALID_PARAMETER_MESSAGE,sizeof(errorMessage)-1);
			break;

		case LiteSrv_EXCEPTION_GENERAL_ERROR:
			strncpy(errorMessage,GENERAL_ERROR_MESSAGE,sizeof(errorMessage)-1);
			break;

		default:
			strncpy(errorMessage,DEFAULT_MESSAGE,sizeof(errorMessage)-1);
			break;
	}

}

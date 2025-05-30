
// prevent multiple inclusion

#if !defined(__SCM_CONNECTOR_H__)
#define __SCM_CONNECTOR_H__

// ============================================================================
//
// IMPORT / EXPORT
//
// ============================================================================

//
// if LiteSrv_DLL_EXPORT is #defined, then we are building the DLL
//  and exporting the classes
//
// otherwise, we are building an executable which will link with the DLL at run-time
//
// -------------------------------------------------------------
// APART FROM THE DLL ITSELF,
//  ANY SOURCE FILE WHICH #includes THIS ONE SHOULD ENSURE THAT
//  LiteSrv_DLL_EXPORT is not #defined
// -------------------------------------------------------------
//

#ifdef LiteSrv_DLL_EXPORT
#define LiteSrv_DLL_API __declspec(dllexport)
#pragma message("exporting ScmConnector")

#else

#ifdef	LiteSrv_DLL_LOCAL
#pragma message("ScmConnector is local")
#define	LiteSrv_DLL_API

#else

#define LiteSrv_DLL_API __declspec(dllimport)
#pragma message("importing ScmConnector")

#endif
#endif

// ============================================================================
//
// PROJECT HEADER FILES
//
// ============================================================================
// namespace header
#include "LiteSrv.h"

// ============================================================================
//
// NAMESPACE
//
// ============================================================================

// all the DLL classes are defined within the LiteSrv namespace
namespace LiteSrv {
	
// ============================================================================
//
// ScmConnector class
//
// ============================================================================
class LiteSrv_DLL_API ScmConnector
{
public:
	// supported statuses
	typedef enum SCM_STATUSES { STATUS_INITIALISING,STATUS_STARTING,STATUS_RUNNING,STATUS_STOPPING,
								STATUS_STOPPED,STATUS_MUST_START_AS_CONSOLE,STATUS_FAILED };

	// constructor
	ScmConnector(char *svcName,bool allowConnectErrors = false) throw (LiteSrvException);

	// destructor
	virtual ~ScmConnector();

	// service status
	void notifyScmStatus(SCM_STATUSES scmStatus,bool ignoreErrors = false) throw (LiteSrvException);
	SCM_STATUSES getScmStatus() const;

	// action to take if STOP requested by SCM
	typedef void STOP_HANDLER_FUNCTION(void*);
	void installStopCallback(bool *stopRequestedVar) throw (LiteSrvException);
	void installStopCallback(HANDLE *stopRequestedEvent) throw (LiteSrvException);
	void installStopCallback(STOP_HANDLER_FUNCTION *stopRequestedFunction,void *genericPointer)
		throw (LiteSrvException);

private: // no default constructor
	ScmConnector();

};

} // namespace LiteSrv

#endif // !defined(__SCM_CONNECTOR_H__)

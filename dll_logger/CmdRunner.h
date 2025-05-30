
// prevent multiple inclusion

#if !defined(__CMD_RUNNER_H__)
#define __CMD_RUNNER_H__

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
#pragma message("exporting CmdRunner")

#else

#ifdef	LiteSrv_DLL_LOCAL
#pragma message("CmdRunner is local")
#define	LiteSrv_DLL_API

#else

#define LiteSrv_DLL_API __declspec(dllimport)
#pragma message("importing CmdRunner")

#endif
#endif

// ============================================================================
//
// PROJECT HEADER FILES
//
// ============================================================================
// system headers
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>

// namespace header
#include "LiteSrv.h"

// forward declarations
struct CmdRunnerData;

// ============================================================================
//
// NAMESPACE
//
// ============================================================================

// all the DLL classes are defined within the LiteSrv namespace
namespace LiteSrv {

// ============================================================================
//
// CmdRunner class
//
// ============================================================================
class LiteSrv_DLL_API CmdRunner
{
public:
	// public types
	typedef enum START_MODES { COMMAND_MODE, SERVICE_MODE, ANY_MODE,
								INSTALL_MODE, INSTALL_DESKTOP_MODE, REMOVE_MODE };
	typedef enum EXECUTION_PRIORITIES {HIGH_PRIORITY, IDLE_PRIORITY, NORMAL_PRIORITY, REAL_PRIORITY };
	typedef enum SHUTDOWN_METHODS { SHUTDOWN_BY_KILL, SHUTDOWN_BY_COMMAND, SHUTDOWN_BY_WINMESSAGE };

	// start
	void start() throw (LiteSrvException);

	// startup and shutdown
	void setStartupCommand(const char *sc) throw (LiteSrvException);
	void setShutdownCommand(const char *sc) throw (LiteSrvException);
	void setWaitCommand(const char *wc) throw (LiteSrvException);
	void addStartupCommandArgument(const char *arg) throw (LiteSrvException);
	void setShutdownMethod(const SHUTDOWN_METHODS sm) throw (LiteSrvException);

	char *getStartupCommand() const;
	char *getShutdownCommand() const;
	char *getWaitCommand() const;
	SHUTDOWN_METHODS getShutdownMethod() const;

	// properties
	void setDebugLevel(int dl);
	void setWaitInterval(int wi);
	void setExecutionPriority(EXECUTION_PRIORITIES ep);
	void setStartupDelay(int sd);
	void setStartupDirectory(const char *dir) throw (LiteSrvException);

	char *getSrvName() const;
	int   getWaitInterval() const;
	int   getStartupDelay() const;
	char *getStartupDirectory() const;
	EXECUTION_PRIORITIES getExecutionPriority() const;

	// environment
	void addEnv(const char *nm,const char *val) throw (LiteSrvException);

	// start profile
	void setStartMinimised(bool sm);
	void setStartInNewWindow(bool nw);
	bool getStartMinimised() const;
	bool getStartInNewWindow() const;

	// auto-restart
	void setAutoRestart(bool ar);
	void setAutoRestartInterval(int in);
	bool getAutoRestart() const;
	int  getAutoRestartInterval() const;

	// drive mappings
	void mapLocalDrive(const char driveLetter,const char *drivePath) throw (LiteSrvException);
	void mapNetworkDrive(const char driveLetter,const char *networkPath) throw (LiteSrvException);

	// constructor and destructor
	CmdRunner(START_MODES mode = COMMAND_MODE,char *nm = NULL) throw (LiteSrvException);
	virtual ~CmdRunner();

public:	// stop callbacks - provided for use by ScmConnector ONLY

	// service stop callback variable
	bool stopCallbackVar;

	// service stop callback event
	HANDLE stopCallbackEvent;

	// service stop callback function
	static void stopCallbackFunction(void *thisObject);

private:	// member functions: internals
	// start the command
	void startCommand() throw (LiteSrvException);

	// wait for command to start
	void waitForStartup() throw (LiteSrvException);

	// watch command while it's running
	typedef enum WATCH_OUTCOMES { WATCH_COMMAND_COMPLETED, WATCH_COMMAND_WAS_STOPPED };
	WATCH_OUTCOMES watchCommand() throw (LiteSrvException);

	// kill the command
	void killCommand() throw (LiteSrvException);

private:	// data members - hidden data
	struct CmdRunnerData *cmdRunnerData;

};

} // namespace LiteSrv

#endif // !defined(__CMD_RUNNER_H__)

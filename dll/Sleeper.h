
// prevent multiple inclusion

#if !defined(__SLEEPER_H__)
#define __SLEEPER_H__


// ============================================================================
//
// NAMESPACE
//
// ============================================================================

// all the DLL classes are defined within the LiteSrv namespace
namespace LiteSrv {

// ============================================================================
//
// Sleeper class
//
// ============================================================================

class Sleeper
{
public:
	// sleep for the given number of seconds
	static void Sleep(int seconds,char *msg)
	{
		// create local wait event
		HANDLE hSleepEvent;
		hSleepEvent = CreateEvent(NULL,FALSE,FALSE,NULL);

		// wait for given time
		LOGGER_LOG_DEBUG2("waiting %dms for %s ...",1000*seconds,msg)
		(void)WaitForSingleObject(hSleepEvent,1000*seconds);
		LOGGER_LOG_DEBUG2("... wait %dms for %s complete",1000*seconds,msg)

		// close handle
		CloseHandle(hSleepEvent);

	}

private:
	Sleeper(); // no constructor
};

} // namespace LiteSrv

#endif // !defined(__SLEEPER_H__)


// prevent multiple inclusion

#if !defined(__SRV_START_H__)
#define __SRV_START_H__
// suppress warnings about the unsupported throw(...,...,...) syntax
#pragma warning(disable:4290)

// ============================================================================
//
// VERSION CONTROL
//
// ============================================================================

#define APPLICATION		"LiteSRV"
#define	VERSION			"1.01"





// export or import these symbols
// NB an invoking source file should #undef LiteSrv_DLL_EXPORT

// ============================================================================
//
// IMPORT / EXPORT
//
// ============================================================================

#ifdef LiteSrv_DLL_EXPORT
#define LiteSrv_DLL_API __declspec(dllexport)
#pragma message("exporting LiteSrv")

#else

#define LiteSrv_DLL_API __declspec(dllimport)
#pragma message("importing LiteSrv")

#endif

// ============================================================================
//
// NAMESPACE
//
// ============================================================================

// all the DLL classes are defined within the LiteSrv namespace
namespace LiteSrv {
	
	// version information
	const LiteSrv_DLL_API char *getApplication();
	const LiteSrv_DLL_API char *getVersion();

	const LiteSrv_DLL_API char *getCopyright();
	const LiteSrv_DLL_API char *getDistribution();
	const LiteSrv_DLL_API char *getWarranty();

	typedef enum LiteSrv_EXCEPTION
	{
		LiteSrv_EXCEPTION_COMMAND_FAILED,
		LiteSrv_EXCEPTION_CREATE_PROCESS_FAILED,
		LiteSrv_EXCEPTION_WAIT_FAILED,
		LiteSrv_EXCEPTION_WATCH_FAILED,
		LiteSrv_EXCEPTION_KILL_FAILED,
		LiteSrv_EXCEPTION_NOTIFY_FAILED,
		LiteSrv_EXCEPTION_INVALID_PARAMETER,
		LiteSrv_EXCEPTION_GENERAL_ERROR
	} ;

	const int LiteSrv_EXCEPTION_STRING_SIZE = 1000;
	class LiteSrv_DLL_API LiteSrvException
	{
	public:
		// data members
		LiteSrv_EXCEPTION exceptionId;
		char className[LiteSrv_EXCEPTION_STRING_SIZE];
		char methodName[LiteSrv_EXCEPTION_STRING_SIZE];
		char errorMessage[LiteSrv_EXCEPTION_STRING_SIZE];
		char sourceFile[LiteSrv_EXCEPTION_STRING_SIZE];
		int  lineNumber;
		// constructor
		LiteSrvException
		(
			LiteSrv_EXCEPTION pExceptionId,
			char *pClassName,
			char *pMethodName,
			char *pSourceFile,
			int   pLineNumber
		);
		virtual ~LiteSrvException() { ; }
	private:
		// no default constructor
		LiteSrvException() { ; }
	} ;


} // namespace LiteSrv

//
// general-purpose macro for throwing exceptions
//
#define	THROW_LiteSrv_EXCEPTION(id,cl,mt)								\
	LOGGER_LOG_ERROR3("Exception %d in Class '%s' method '%s()'",id,cl,mt)	\
	throw LiteSrvException(id,cl,mt,__FILE__,__LINE__);

#endif // !defined(__SRV_START_H__)

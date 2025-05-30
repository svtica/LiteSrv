
// prevent multiple inclusion

#if !defined(__STRING_SUBSTITUTER_H__)
#define __STRING_SUBSTITUTER_H__

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
#pragma message("exporting StringSubstituter")

#else

#ifdef	LiteSrv_DLL_LOCAL
#pragma message("StringSubstituter is local")
#define	LiteSrv_DLL_API

#else

#define LiteSrv_DLL_API __declspec(dllimport)
#pragma message("importing StringSubstituter")

#endif
#endif

// ============================================================================
//
// NAMESPACE
//
// ============================================================================

// all the DLL classes are defined within the LiteSrv namespace
namespace LiteSrv {
const int STRING_SUBSTITUTER_DEFAULT_BUFSIZE = 5000;

// ============================================================================
//
// StringSubstituter class
//
// ============================================================================
class LiteSrv_DLL_API StringSubstituter {
public:
	// string manipulations
	void stringInit(char *&str);
	void stringCopy(char *&dest, const char*src);
	void stringAppend(char *&dest, const char*src,bool addSpace=false);
	void stringDelete(char *str);

	// substitute environment values into string
	void stringSubstitute(char *&subBuf);
	
	// constructor and destructor
	StringSubstituter(int bufSize = STRING_SUBSTITUTER_DEFAULT_BUFSIZE);
	virtual ~StringSubstituter();

private:
	int _bufSize;
	char *buf;
	char *tmpString1;
	char *tmpString2;

	
};

} // namespace LiteSrv

#endif // !defined(__STRING_SUBSTITUTER_H__)

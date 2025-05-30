
// prevent multiple inclusion

#if !defined(__SERVICE_MANAGER_H__)
#define __SERVICE_MANAGER_H__

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
#pragma message("exporting ServiceManager")

#else

#ifdef	LiteSrv_DLL_LOCAL
#pragma message("ServiceManager is local")
#define	LiteSrv_DLL_API

#else

#define LiteSrv_DLL_API __declspec(dllimport)
#pragma message("importing ServiceManager")

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
struct ServiceManagerData;

// ============================================================================
//
// NAMESPACE
//
// ============================================================================

// all the DLL classes are defined within the LiteSrv namespace
namespace LiteSrv {

// ============================================================================
//
// ServiceManager class
//
// ============================================================================
class LiteSrv_DLL_API ServiceManager
{
public:
	// public types

	// install / remove
	void install() throw (LiteSrvException);
	void remove(bool ignore_errors=false) throw (LiteSrvException);

	// set / get properties
	void setDesktopService(bool ds);
	void ServiceManager::setDisplayName(char *dn);
	void ServiceManager::setBinaryPath(char *bp);
	void ServiceManager::addBinaryPathParameter(char *bpp);

	bool  getDesktopService() const;
	char *ServiceManager::getDisplayName() const;
	char *ServiceManager::getBinaryPath() const;

	// constructor and destructor
	ServiceManager(char *sn) throw (LiteSrvException);
	virtual ~ServiceManager();

private:	// member functions: internals

private:	// data members - hidden data
	struct ServiceManagerData *serviceManagerData;

};

} // namespace LiteSrv

#endif // !defined(__SERVICE_MANAGER_H__)


#if !defined(config_dbaccess_h)
#define config_dbaccess_h

#ifdef __USE_DLL_DBACCESS

	#define __EXPORT_DBACCESS __declspec(dllexport)
#else
	#define __EXPORT_DBACCESS __declspec(dllimport)
#endif
#else
	#define __EXPORT_DBACCESS
#endif


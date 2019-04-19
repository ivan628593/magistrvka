#if !defined(config_dbconnsettingsdialog_h)
#define config_dbconnsettingsdialog_h

#ifdef __USE_DLL_DBCONNSETTINGSDIALOG

	#define __EXPORT_DBCONNSETTINGSDIALOG __declspec(dllexport)
#else
	#define __EXPORT_DBCONNSETTINGSDIALOG __declspec(dllimport)
#endif
#else
	#define __EXPORT_DBCONNSETTINGSDIALOG
#endif


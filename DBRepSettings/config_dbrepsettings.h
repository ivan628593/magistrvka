#if !defined(config_dbrepsettings_h)
#define config_dbrepsettings_h

#ifdef __USE_DLL_REPSETTINGS

    #define __EXPORT_REPSETTINGS __declspec(dllexport)
#else
    #define __EXPORT_REPSETTINGS __declspec(dllimport)
#endif
#else
    #define __EXPORT_REPSETTINGS
#endif


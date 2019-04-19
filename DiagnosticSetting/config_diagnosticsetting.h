#if !defined(config_diagnosticsetting_h)
#define config_diagnosticsetting_h

#ifdef __USE_DLL_DIAGNOSTICSETTING

    #define __EXPORT_DIAGNOSTICSETTING __declspec(dllexport)
#else
    #define __EXPORT_DIAGNOSTICSETTING __declspec(dllimport)
#endif
#else
    #define __EXPORT_DIAGNOSTICSETTING
#endif

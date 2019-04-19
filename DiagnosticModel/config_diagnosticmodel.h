#if !defined(config_diagnosticmodel_h)
#define config_diagnosticmodel_h

#ifdef __USE_DLL_DIAGNOSTICMODEL

    #define __EXPORT_DIAGNOSTICMODEL __declspec(dllexport)
#else
    #define __EXPORT_DIAGNOSTICMODEL __declspec(dllimport)
#endif
#else
    #define __EXPORT_DIAGNOSTICMODEL
#endif

/**
*******************************************************************************
*	\FILE		DLL_Exports.h
*
*	\DESCRIPTION
*		Define MACROS for building Windows DLLs
*
*	\AUTHOR	Simon Berg
*		(c) LiPPERT ADLINK Technology GmbH Germany
*
*******************************************************************************
**/

#ifndef DLL_EXPORTS_H
#define DLL_EXPORTS_H

#ifdef _WIN32
    #if defined(libsema_EXPORTS) || defined(libsemaadmin_EXPORTS)
        #define DLL_EXPORT __declspec( dllexport )
    #else /* libsema_EXPORTS */	
        #define DLL_EXPORT __declspec( dllimport )
    #endif /* libsema_EXPORTS */

#else /* _WIN32 */
	#define DLL_EXPORT
#endif /* _WIN32 */
#endif /* DLL_EXPORTS_H */

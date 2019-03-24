/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://eapidk.svn.sourceforge.net/svnroot/eapidk/trunk/include/winnt/EApiOs.h $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: All rights reserved. This program and the accompanying 
 *I              materials are licensed and made available under the 
 *I              terms and conditions of the BSD License which 
 *I              accompanies this distribution. The full text of the 
 *I              license may be found at 
 *I              http://opensource.org/licenses/bsd-license.php
 *I              
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
 *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Auto Created for EApiOs.h
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiOs.h
 *I  File Location        : include\winnt
 *I  Last committed       : $Revision: 67 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-18 23:39:13 +0200 (Fr, 18 Jun 2010) $
 *I  ID                   : $Id: EApiOs.h 67 2010-06-18 21:39:13Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
/* Windows NT Common Header */
#ifndef _EAPIOS_H_        
#define _EAPIOS_H_

//Adlink start
#define WIN32_LEAN_AND_MEAN
//Adlink end
#include <windows.h>
#include <assert.h>
#ifdef _MSC_VER 
#include "inttypes.h"

#ifndef __IN
#  define __IN
#endif

#define EAPI_CALLTYPE WINAPI
#ifdef __cplusplus
extern "C" {
#endif
void EApiSleepus(unsigned long ms);
#ifdef __cplusplus
}
#endif

#define EAPI_PRINTF_ARG(Format, Arg) 
#define EAPI_EMUL_DELAY_NS(x) EApiSleepus(x/1000)

#ifndef EApiSleep
#  define EApiSleep(x) Sleep(x)
#endif

#ifndef __cplusplus
#define inline __inline
#endif // !inline


#ifdef UNICODE
#  define EAPI_strlen         wcslen
#  define EAPI_strnlen        wcsnlen
#  define EAPI_strncpy        wcsncpy
#  define EAPI_vsnprintf      _vsnwprintf
#  define EAPI_fprintf        fwprintf
#  define EAPI_printf         wprintf
#  define EAPI_fopen          _wfopen
#else
#  define EAPI_strlen         strlen
#  define EAPI_strnlen        strnlen
#  define EAPI_strncpy        strncpy
#  define EAPI_vsnprintf      _vsnprintf
#  define EAPI_fprintf        fprintf
#  define EAPI_fopen          fopen
#  define EAPI_printf         printf
#endif

#define EAPI_vsnprintfA     _vsnprintf
#define EAPI_strdup         _strdup
#define EAPI_strncpyA       strncpy
#define EAPI_strnlenA       strnlen
#define EAPI_strlenA        strlen

#define         MSVC_1_5         800
#define         MSVC_98         1200
#define         MSVC_2003       1300 /* .NET */
#define         MSVC_2005       1400
#define         MSVC_2008       1500
#define         MSVC_2010       1600

/* unreferenced formal parameter */
#  if ( _MSC_VER >= MSVC_1_5 )
#    pragma warning(disable:4127) /* conditional expression is constant */
#  endif /* if ( _MSC_VER >= MSVC_1_5 ) */
#endif /* _MSC_VER */

#endif /* _EAPIOS_H_ */



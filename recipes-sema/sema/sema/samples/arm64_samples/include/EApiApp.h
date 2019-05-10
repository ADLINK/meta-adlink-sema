/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://svn.code.sf.net/p/eapidk/code/trunk/apps/include/EApiApp.h $
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
 *I Description: Auto Created for EApiApp.h
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiApp.h
 *I  File Location        : apps\include
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-24 00:56:50 +0530 (Thu, 24 Jun 2010) $
 *I  ID                   : $Id: EApiApp.h 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef _EAPIAPP_H_    
#define _EAPIAPP_H_

#ifdef __cplusplus
#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS
#define __STDC_FORMAT_MACROS
#endif

#include <stdlib.h>
#include <stdio.h>
#include "EApiOs.h"	/* Os Specific Include File */
#include "EApi.h"
#include "EApiCommon.h"
#include "EApiAHStr.h"
#include "EApiAHI2C.h"
#include "EApiAHStorage.h"
#include "DbgChk.h"
#ifdef VXWORKS
#include "../validate/AppVer.h"
#else
#include <AppVer.h>
#endif


#ifndef EAPI_EMUL_DELAY_NS
#   define EAPI_EMUL_DELAY_NS(x)
#endif

#ifndef EAPI_MSG_OUT
#  ifdef UNICODE
#    define EAPI_MSG_OUT     wprintf
#  else
#    define EAPI_MSG_OUT     printf
#  endif
#endif

#ifndef EAPI_ERR_OUT
#  ifdef UNICODE
#    define EAPI_ERR_OUT     wprintf
#  else
#    define EAPI_ERR_OUT     printf
#  endif
#endif


#if (STRICT_VALIDATION>0)
#define EAPI_FORMATED_MES1(type, func, err, desc) \
    siFormattedMessage_M2(type, __FILE__, #func, __LINE__, \
        err, "%s\n", desc );
#else
#define EAPI_FORMATED_MES1(type, func, err, desc)
#endif

#if (STRICT_VALIDATION>0)
#define EAPI_FORMATED_MES(type, func, err, desc) \
    siFormattedMessage_SC(type, __FILE__, #func, __LINE__, \
        (EApiStatus_t)((((uintptr_t)(err))&UINT32_MAX)), "%s\n", desc );

#else
#define EAPI_FORMATED_MES(type, func, err, desc)
#endif

#define EAPI_APP_RETURN_SUCCESS(func, desc)  \
	do{\
		StatusCode=EAPI_RETURN_SUCCESS; \
		EAPI_FORMATED_MES('L', func, EAPI_RETURN_SUCCESS, desc );\
		goto ExitPoint; \
	}while(0)

#define EAPI_APP_RETURN_ERROR(func, err, desc)  \
	do{ \
		EAPI_FORMATED_MES('E', func, err, desc );\
		StatusCode=err; \
		goto ExitPoint; \
	}while(0)

#define EAPI_APP_RETURN_ERROR_IF(func, exp, err, desc)  \
  if(exp)\
  {\
    EAPI_APP_RETURN_ERROR(func, err, desc );\
  }
#define EAPI_APP_RETURN_ERROR_IF_S(func, exp, err)  \
  if(exp)\
  {\
    EAPI_APP_RETURN_ERROR(func, err, #exp );\
  }



#if (STRICT_VALIDATION>0)
#  define EAPI_APP_ASSERT_PARAMATER_CHECK(func, ret, exp, desc)  \
  EAPI_APP_RETURN_ERROR_IF(func, exp, ret, desc)
#else
#  define EAPI_APP_ASSERT_PARAMATER_CHECK(func, ret, exp, desc)
#endif

#define EAPI_APP_ASSERT_PARAMATER_CHECK_S(func, ret, exp)  \
  EAPI_APP_ASSERT_PARAMATER_CHECK(func, ret, exp, #exp)

#define EAPI_APP_ASSERT_PARAMATER_ZERO(func, ret, val)  \
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(func, ret, (val==0))

#define EAPI_APP_ASSERT_PARAMATER_NULL(func, ret, val)  \
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(func, ret, (val==NULL))


#define EAPI_APP_PREVENT_BUF_OVERFLOW(func, x, y)  \
  if(x>y)\
  {\
    EAPI_FORMATED_MES('E', func,  EAPI_STATUS_MORE_DATA, \
                  " pBuffer Overflow Prevented"#x">"#y);\
    x=y;\
  }

#define EAPI_APP_EXIT \
goto ExitPoint

#define EAPI_APP_ASSERT_EXIT \
ExitPoint:


#endif /* _EAPIAPP_H_ */


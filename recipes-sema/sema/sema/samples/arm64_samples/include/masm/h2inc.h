/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: https://eapidk.svn.sourceforge.net/svnroot/eapidk/trunk/include/masm/h2inc.h $
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
 *I Description: Auto Created for EApiConv.h
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : h2inc.h
 *I  File Location        : include\masm
 *I  Last committed       : $Revision: 38 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-01-26 07:48:22 +0100 (Di, 26 Jan 2010) $
 *I  ID                   : $Id: h2inc.h 38 2010-01-26 06:48:22Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
/*
 * Conversion File to allow easier Conversion using h2inc
 * h2inc /C /WIN32 /Zu /Ht /Fainclude\masm\EApiConv.inc include\masm\EApiConv.h
 * Please note this settings are only for valid for WIN32
 */
/*
 *  Necessary to do change 
 *  uint64_t		TYPEDEF		DWORD
 *  int64_t		  TYPEDEF		SDWORD
 *  to
 *  uint64_t		TYPEDEF		QWORD
 *  int64_t		  TYPEDEF		QWORD
 *
 *  h2inc doesn't recognise unsigned long long
 *
 * Masm doesn't support SQWORD
 */
typedef unsigned long  uint64_t;
//typedef   signed long   int64_t;
typedef unsigned long  uint32_t;
typedef   signed long   int32_t;
typedef unsigned short uint16_t;
typedef   signed short  int16_t;
typedef unsigned char  uint8_t;
typedef   signed char   int8_t;
typedef   int32_t       size_t;
typedef   uint16_t      wchar_t;

# define EEEP_INT32_C 
# define EEEP_INT16_C 
# define EEEP_INT8_C  
# define EEEP_UINT32_C 
# define EEEP_UINT16_C 
# define EEEP_UINT8_C  
# define EAPI_INT32_C 
# define EAPI_INT16_C 
# define EAPI_INT8_C  
# define EAPI_UINT32_C 
# define EAPI_UINT16_C 
# define EAPI_UINT8_C  

#define __IN
#define __OUT
#define __INOPT
#define __INOUT
#define __OUTOPT
#define __INOUTOPT


#define UINT8_MAX  0xFF
#define  INT8_MAX  0x7F
#define UINT16_MAX 0xFFFF
#define  INT16_MAX 0x7FFF
#define UINT32_MAX 0xFFFFFFFF
#define  INT32_MAX 0x7FFFFFFF
#define UINT64_MAX 0xFFFFFFFFFFFFFFFF
#define  INT64_MAX 0x7FFFFFFFFFFFFFFF


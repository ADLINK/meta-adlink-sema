/**
********************************************************************************
*	\FILE		Conv.h
*
*	\DESCRIPTION
*		Misc. conversion functions
*
*	\AUTHOR		Martin Hein
*				(c) LiPPERT Embedded Computers GmbH Germany
*
********************************************************************************
**/

#ifndef CONV_H
#define CONV_H

#include "Globals.h"
#include "DLL_Exports.h"

/* ------------------------------ Definitions ------------------------------- */
/* ------------------------------- Typedefs  -------------------------------- */
/* -------------------------------- Macros ---------------------------------- */
/* ------------------------------- Variables -------------------------------- */
/* ------------------------------- Functions -------------------------------- */

/**
********************************************************************************
*	\FUNCTION		byte Conv_IsHexDigit(char c)
*
*	\DESCRIPTION
*		tests if c is valid hex character (0..9, a..f, A..F)
*
*	\PARAMETERS
*		c		character to test
*
*	\RETURNS
*		1 if c is valid hex character, otherwise 0
********************************************************************************
**/
DLL_EXPORT byte Conv_IsHexDigit(char c);


/**
********************************************************************************
*	\FUNCTION		byte Conv_IsHexString(char *String)
*
*	\DESCRIPTION
*		tests if String contains only valid hex characters (0..9, a..f, A..F)
*
*	\PARAMETERS
*		String	null terminated string to test
*
*	\RETURNS
*		1 if String is valid hex string, otherwise 0
********************************************************************************
**/
DLL_EXPORT byte Conv_IsHexString(char *String);


/**
********************************************************************************
*	\FUNCTION		byte Conv_Hex2Dez(char c1, char c2)
*
*	\DESCRIPTION
*		Converts two hex digits to one byte
*
*	\PARAMETERS
*		c1		Hex digit containing UPPER nibble							\np
*		c2		Hex digit containing LOWER nibble
*
*	\RETURNS
*		byte value
********************************************************************************
**/
DLL_EXPORT byte Conv_Hex2Dez(char c1, char c2);


/**
********************************************************************************
*	\FUNCTION		byte Conv_GetDigit(char c)
*
*	\DESCRIPTION
*		Transforms a 1 byte hex value in a decimal value.
*
*	\PARAMETERS
*		c			Hex value 
*
*	\RETURNS
*		Decimal value of the input
********************************************************************************
**/
DLL_EXPORT byte Conv_GetDigit(char c);


/**
********************************************************************************
*	\FUNCTION byte Conv_GetHex(char* buf)
*
*	\DESCRIPTION
*		Transforms a 2 byte hex value in a decimal value.
*
*	\PARAMETERS
*		buf			Hex string value 
*
*	\RETURNS
*		Decimal value of the input
********************************************************************************
**/
DLL_EXPORT byte Conv_GetHex(char* buf);


/**
********************************************************************************
*	\FUNCTION		bool Conv_HexString2Byte(char *String, byte *Hex)
*
*	\DESCRIPTION
*		Converts up to 2 hex digits to a 8bit unsigned value
*
*		Note: An optional leading "0x" and leading zeroes will be ignored
*
*	\PARAMETERS
*		String		Pointer to string to convert							\np
*		Hex			Pointer to BYTE where the result will be stored
*
*	\RETURNS
*		\c true if conversion was successful, otherwise \c false
********************************************************************************
**/
DLL_EXPORT bool Conv_HexString2Byte(char *String, byte *Hex);


/**
********************************************************************************
*	\FUNCTION		bool Conv_HexString2Word(char *String, word *Hex)
*
*	\DESCRIPTION
*		Converts up to 4 hex digits to a 16bit unsigned value
*
*		Note: An optional leading "0x" and leading zeroes will be ignored
*
*	\PARAMETERS
*		String		Pointer to string to convert							\np
*		Hex			Pointer to WORD where the result will be stored
*
*	\RETURNS
*		\c true if conversion was successful, otherwise \c false
********************************************************************************
**/
DLL_EXPORT bool Conv_HexString2Word(char *String, word *Hex);


/**
********************************************************************************
*	\FUNCTION		bool Conv_HexString2DWord(char *String, dword *Hex)
*
*	\DESCRIPTION
*		Converts up to 8 hex digits to a 32bit unsigned value
*
*		Note: An optional leading "0x" and leading zeroes will be ignored
*
*	\PARAMETERS
*		String		Pointer to string to convert							\np
*		Hex			Pointer to DWORD where the result will be stored
*
*	\RETURNS
*		\c true if conversion was successful, otherwise \c false
********************************************************************************
**/
DLL_EXPORT bool Conv_HexString2DWord(char *String, dword *Hex);


#endif /* CONV_H */

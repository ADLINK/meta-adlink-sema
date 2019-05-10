/**
********************************************************************************
*	\FILE		SemaLog.h
*
*	\DESCRIPTION
*		Event logging functions
*
*	\AUTHOR		Martin Hein
*				(c) LiPPERT Embedded Computers GmbH Germany
********************************************************************************
**/

#ifndef SEMALOG_H
#define SEMALOG_H
#ifdef __cplusplus
extern "C" {
#endif
#ifdef WIN32
#include <windows.h>
#endif /* WIN32 */

/* ------------------------------ Definitions ------------------------------- */

#define SEMA_TITLE		"SEMA - Smart Embedded Management Agent"
#define CATEGORY_ONE                     0x00000001L
#define CATEGORY_TWO                     0x00000002L
#define EVENT_STARTED_BY                 0x00000003L
#define EVENT_BMC_EXCEPTION              0x00000004L
#define EVENT_BMC_UPDATE                 0x00000005L
#define EVENT_MESSAGE                    0x00000006L


/* ------------------------------- Typedefs  -------------------------------- */
/* -------------------------------- Macros ---------------------------------- */
/* ------------------------------- Variables -------------------------------- */
/* ------------------------------- Functions -------------------------------- */

#ifdef WIN32
#ifndef WINCE
/**
********************************************************************************
*	\FUNCTION	void Sema_PrepareEventLog(void)
*
*	\DESCRIPTION
*		Installs SEMA app as a source of events under the name of the current executable into the registry
********************************************************************************
**/
void Sema_PrepareEventLog(void);


void Sema_EventLogUpdateComplete(void);



#endif /* WINCE */
#endif /* WIN32 */

DLL_EXPORT void Sema_EventLogError(char *Message);
DLL_EXPORT void Sema_EventLogException(unsigned char Flags);

#ifdef __cplusplus
}
#endif

#endif /* SEMALOG_H */


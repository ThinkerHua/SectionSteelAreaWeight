/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include "calculation.h"
#include <string.h>
#include <windows.h>

//DLLIMPORT void HelloWorld() {
//	MessageBox(0,"Hello World from DLL!\n","Hi",MB_ICONINFORMATION);
//}

DLLIMPORT char *SectionSteelAW(char const *RawText, unsigned const CtrlCode) {
	char *FormatedText;
	char *SecSteType;
	char *Resault;
	void *obj;
	if (formatting(RawText, &FormatedText) == 0)
		return NULL;
	SecSteType = getSecSteType(FormatedText);
	if (SecSteType == NULL) 
		return NULL;
	obj = NewObj(SecSteType);
	if (obj == NULL) 
		return NULL;
	if (SetData(obj, SecSteType, FormatedText) == 0) {
		FreeObj(obj, SecSteType);
		return NULL;
	}
	Resault = getResault(obj, SecSteType, CtrlCode);
	FreeObj(obj, SecSteType);
	return Resault;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved) {
	switch(fdwReason) {
		case DLL_PROCESS_ATTACH: {
			break;
		}
		case DLL_PROCESS_DETACH: {
			break;
		}
		case DLL_THREAD_ATTACH: {
			break;
		}
		case DLL_THREAD_DETACH: {
			break;
		}
	}

	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}

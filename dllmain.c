#include "dll.h"
#include "calculation.h"
#include <string.h>
#include <windows.h>

DLLIMPORT char *SectionSteelAW(char const *RawText, unsigned const CtrlCode) {
	char *FormatedText = NULL;
	char *SecSteType = NULL;
	char *Resault = NULL;
	void *obj = NULL;
	if (formatting(RawText, &FormatedText) == 0)
		return NULL;
	SecSteType = getSecSteType(FormatedText);
	if (SecSteType == NULL) 
		return NULL;
	obj = NewObj(SecSteType);
	if (obj == NULL) 
		return NULL;
	if (SetData(obj, SecSteType, FormatedText) == 0) {
		FreeObj(&obj, SecSteType);
		return NULL;
	}
	Resault = getResault(obj, SecSteType, CtrlCode);

	FreeObj(&obj, SecSteType), obj = NULL;
	free(FormatedText), FormatedText = NULL;
	//SecSteType来自const字符串数组，不需要释放，只需赋值NULL 
	SecSteType = NULL;
	return Resault;
}


DLLIMPORT void free_dallocstr(char *str) {
	free(str);
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

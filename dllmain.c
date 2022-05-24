/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include "calculation.h"
#include <string.h>
#include <windows.h>

//DLLIMPORT void HelloWorld() {
//	MessageBox(0,"Hello World from DLL!\n","Hi",MB_ICONINFORMATION);
//}

char *SecSteTypeArr[] = {"H", "HT", "HI", "T", "J", "D", "I", "[", "[]", "2[", "L", "2L", "C", "2C", "Z", "PL", "PLT", "PLD"};

DLLIMPORT char *SectionSteelAW(char const *RawText, int const CtrlCode) {
	char *FormatedText;
	char *SecSteType;
	char *Resault;
	void *obj;
	FormatedText = Formatting(RawText);
	SecSteType = getSecSteType(FormatedText);
	obj = NewObj(SecSteType);
		
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

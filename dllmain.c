#include "dll.h"
#include "calculation.h"
#include <string.h>
#include <windows.h>

int Creat_SetData_Obj(char const *RawText, char **p_SecSteType, void **p_obj){
	int sucess = 0;
	char *FormatedText = NULL;	//指向对象是动态分配的，用完应当free 
	
	if (formatting(RawText, &FormatedText) == 0)
		return sucess;
	*p_SecSteType = getSecSteType(FormatedText);
	if (*p_SecSteType == NULL) 
		goto clean;
	*p_obj = NewObj(*p_SecSteType);
	if (*p_obj == NULL) 
		goto clean;
	if (SetData(*p_obj, *p_SecSteType, FormatedText) == 0) 
		goto clean; 
	sucess = 1;
	
clean:
	free(FormatedText), FormatedText = NULL;
	if (!sucess) {
		FreeObj(p_obj, *p_SecSteType);
		*p_SecSteType = NULL;
	}
	
	return sucess;
}

DLLIMPORT char *SectionSteel_Area_Weight(char const *RawText, unsigned const CtrlCode) {
	char *SecSteType = NULL;
	void *obj = NULL;
	char *formula = NULL;
	
	if ( Creat_SetData_Obj(RawText, &SecSteType, &obj) )
		formula = getFormula(obj, SecSteType, CtrlCode);

	FreeObj(&obj, SecSteType), obj = NULL;
	SecSteType = NULL;
	
	return formula;
}

DLLIMPORT char *Stiffener_Specifications(char const *RawText, unsigned const CtrlCode) {
	char *SecSteType = NULL;
	void *obj = NULL;
	char *stif = NULL;
	
	if ( Creat_SetData_Obj(RawText, &SecSteType, &obj) )
		stif = getStiffener(obj, SecSteType, CtrlCode);

	FreeObj(&obj, SecSteType), obj = NULL;
	SecSteType = NULL;
	
	return stif;
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

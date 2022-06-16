#include <windows.h>
#include <stdio.h>

/*
#define TYPE_AREA					1
#define TYPE_EXCLUDE_TOPSURFACE		2
#define TYPE_WEIGHT					4
#define METHOD_ROUGHLY				8
#define METHOD_PRECISELY			16
#define METHOD_LOOKUP				32

DLLIMPORT char *SectionSteelAW(char const *RawText, unsigned const CtrlCode)
*/

int main (int argc, char *argv[]) {
	char *(*p_SSAW)(char const *RawText, unsigned const CtrlCode) = NULL;
	char *resault = NULL;
	char RawText[64] = {'\0'};
	unsigned ctrlcode = 0;
	
	HMODULE module = LoadLibraryA("SectionSteelAW.dll");
	if (module == NULL) 
		return 0;
	p_SSAW = (char *(*)(char const *, unsigned const))GetProcAddress(module, "SectionSteelAW");
	if (p_SSAW == NULL)
		goto clean;
		
	while (scanf("%s %u", RawText, &ctrlcode) != EOF) {
		resault = p_SSAW(RawText, ctrlcode);
		if (resault != NULL)
			printf("%s\n", resault);
		free(resault);
		resault = NULL;
	}
	
clean:
	FreeLibrary(module);
	
	return 0;
}

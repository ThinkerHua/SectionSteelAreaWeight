#include <windows.h>
#include <stdio.h>
/*
#define TYPE_AREA					1
#define TYPE_EXCLUDE_TOPSURFACE		2
#define TYPE_WEIGHT					4
#define METHOD_ROUGHLY				8
#define METHOD_PRECISELY			16
#define METHOD_LOOKUP				32
#define PI_STYLE					64

DLLIMPORT char *SectionSteelAW(char const *RawText, unsigned const CtrlCode);
*/
typedef char *(*p_SectionSteelAW)(char const *RawText, unsigned const CtrlCode);

int main (int argc, char *argv[]) {
	HMODULE module = NULL;
	p_SectionSteelAW SSAW = NULL;
	char *resault = NULL;
	char RawText[64] = {'\0'};
	unsigned ctrlcode = 0;
	
	module = LoadLibraryA("SectionSteelAW.dll");
	if (module == NULL) {
		MessageBox(0,"Cannot start this program because of missing "
						"\"SectionSteelAW.dll\" file!\n","Error",MB_ICONERROR);
		return 0;
	}
	SSAW = (char *(*)(char const *, unsigned const))GetProcAddress(module, "SectionSteelAW");
	if (SSAW == NULL)
		goto clean;
		
	while (scanf("%s %u", RawText, &ctrlcode) != EOF) {
		resault = SSAW(RawText, ctrlcode);
		if (resault != NULL)
			printf("%s\n", resault);
		free(resault);
		resault = NULL;
	}
	
clean:
	FreeLibrary(module);
	
	return 0;
}

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

DLLIMPORT char *SectionSteel_Area_Weight(char const *RawText, unsigned const CtrlCode);
DLLIMPORT char *Stiffener_Specifications(char const *RawText, unsigned const CtrlCode);
*/
typedef char *(*P_FUNC)(char const *RawText, unsigned const CtrlCode);

int main (int argc, char *argv[]) {
	HMODULE module = NULL;
	P_FUNC ptr_func = NULL; 
	char *resault = NULL;
	char RawText[64] = {'\0'};
	unsigned ctrlcode = 0;
	char chose = '\0';
	
	module = LoadLibraryA("SectionSteelAreaWeight.dll");
	if (module == NULL) {
		MessageBox(0,"Cannot start this program because of missing "
						"\"SectionSteelAreaWeight.dll\" file!\n", "Error", MB_ICONERROR);
		return 0;
	}
		
	printf("You want to testing witch function?\n"
			"SectionSteel_Area_Weight [1]:\n"
			"Stiffener_Specification [2]:\n");
	
	chose = getchar();
	switch (chose) {
		case '1' :
			ptr_func = (char *(*)(char const *, unsigned const))GetProcAddress(module, "SectionSteel_Area_Weight");
			break;
		case '2' :
			ptr_func = (char *(*)(char const *, unsigned const))GetProcAddress(module, "Stiffener_Specification");
			break;
		default :
			printf("Not the expected value, exiting program!\n");
			goto clean;
	}
	
	if (ptr_func == NULL) {
		printf("Failed to link function, please check if \"SectionSteelAreaWeight.dll\" file is corrupted!\n");
		goto clean;
	}
		
	while (scanf("%s %u", RawText, &ctrlcode) != EOF) {
		resault = ptr_func(RawText, ctrlcode);
		if (resault != NULL)
			printf("%s\n", resault);
		free(resault);
		resault = NULL;
	}
	
clean:
	FreeLibrary(module);
	
	return 0;
}

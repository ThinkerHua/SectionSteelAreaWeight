#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

DLLIMPORT char *SectionSteelAW(char const *RawText, unsigned const CtrlCode);
DLLIMPORT void free_dallocstr(char *str);
/*
	本函数专供VB.net使用 
	C语言可直接使用free释放动态分配的字符串 
*/

#endif

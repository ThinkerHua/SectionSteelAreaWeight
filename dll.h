#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

int Creat_SetData_Obj(char const *RawText, char **p_SecSteType, void **p_obj);
/*
	创建型钢实例对象并赋值，成功返回1，失败返回0
	入参SecSteType带回型钢类型，指向的是const字符串，不需要使用时只需赋值NULL，不应free
	入参obj带回型钢实例对象，指向的对象是动态分配的，不需要使用时应free 
*/
DLLIMPORT char *SectionSteel_Area_Weight(char const *RawText, unsigned const CtrlCode);
/*
	生成型钢的单位面积或单位重量的计算式
	失败返回NULL 
	CtrlCode说明参见"calculation.h"中的"getResault"函数 
*/ 
DLLIMPORT char *Stiffener_Specification(char const *RawText, unsigned const CtrlCode);
/*
	生成型钢的加劲肋规格
	失败返回NULL 
*/ 
DLLIMPORT void free_dallocstr(char *str);
/*
	本函数专供VB.net使用 
	C语言可直接使用free释放动态分配的字符串 
*/

#endif

#ifndef _GBDATA_H_
#define _GBDATA_H_

//#define GB_NAME_LENGTH 15
#define GB_DATA_NUMS 4
typedef struct {
//	char *Type;
	char *Name;
	double Data[GB_DATA_NUMS];
	double Weight;
	double Area;
}GBSectionSteel;

double const search_AorW(char const *SecSteType, double const data[], int const AorW);
double const *search_Data_ByName(char const *SecSteType, char const *Name);
double const *search_Data_ByPart(char const *SecSteType, double const partData[]);
int compare_Arr_f(double const arr1[], double const arr2[]);
/*
返回值：	1	arr1中的每项均与arr2中对应项目相等
			0	arr1中的项目与arr2中对应的项目不全相等
			-1	arr1项目数量多于arr2项目数量
*/ 
void link_pGBSecSte(GBSectionSteel const *p, char const *SecSteType);

#endif

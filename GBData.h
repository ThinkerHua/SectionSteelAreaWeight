#ifndef _GBDATA_H_
#define _GBDATA_H_

//#define GB_NAME_LENGTH 15
#define GB_DATA_ITEMS 4
typedef struct {
//	char *Type;
	char const *Name;
	double const Data[GB_DATA_ITEMS];
	double const Weight;
	double const Area;
}GBSectionSteel;
GBSectionSteel const GBSecSte_H[];
GBSectionSteel const GBSecSte_HT[];
GBSectionSteel const GBSecSte_T[];
GBSectionSteel const GBSecSte_I[];
GBSectionSteel const GBSecSte_Chan[];
GBSectionSteel const GBSecSte_L[];
GBSectionSteel const GBSecSte_C[];
GBSectionSteel const GBSecSte_Z[];

double const search_AorW(char const *SecSteType, double const data[], int const AorW);
double const *search_Data(char const *SecSteType, char const *Name);
double const *search_Data_ByPart(char const *SecSteType, double const partData[]);
/*
返回值：	1	arr1中的每项均与arr2中对应项目相等
			0	arr1中的项目与arr2中对应的项目不全相等
			-1	arr1项目数量多于arr2项目数量
*/ 
int compare_Arr_f(double const arr1[], double const arr2[]);
void link_pGBSecSte(GBSectionSteel const *p, char const *SecSteType);

#endif

#ifndef _GBDATA_H_
#define _GBDATA_H_

typedef struct {
//	char *Type;
	char Name[15];
	double data[4];
	double area;
	double weight;
}GBSectionSteel;
GBSectionSteel GBSecSte_H[];
GBSectionSteel GBSecSte_HT[];
GBSectionSteel GBSecSte_T[];
GBSectionSteel GBSecSte_I[];
GBSectionSteel GBSecSte_Chan[];
GBSectionSteel GBSecSte_L[];
GBSectionSteel GBSecSte_C[];
GBSectionSteel GBSecSte_Z[];

double search_AorW(char const *SecSteType, double const data[], int const AorW);
double *search_Data(char const *SecSteType, char const *Name);
double *search_Data_ByPart(char const *SecSteType, double const partData[]);
/*
返回值：	1	arr1中的每项均与arr2中对应项目相等
			0	arr1中的项目与arr2中对应的项目不全相等
			-1	arr1项目数量多于arr2项目数量
*/ 
int compare_Arr_f(double *arr1[], double *arr2[]);

#endif

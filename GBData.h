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

double const search_AorW(char const *SecSteType, double const data[], int const len, int const AorW);
/*
	AorW	1	weight
			0	area 
*/
double const *search_Data_ByName(char const *SecSteType, char const *Name);
double const *search_Data_ByPart(char const *SecSteType, double const partData[], int const len);
int compare_Arr_f(double const arr1[], int const len1, double const arr2[], int const len2);
/*
	����ֵ��1	arr1�е�ÿ�����arr2�ж�Ӧ��Ŀ���
			0	arr1�е���Ŀ��arr2�ж�Ӧ����Ŀ��ȫ���
			-1	arr1��Ŀ��������arr2��Ŀ����
*/ 
int link_pGBSecSte(GBSectionSteel const **p, char const *SecSteType);
/*
	����ֵ��-1	ָ������ʧ��
			>=0	ָ�����ӵ�����ĳ��� 
*/

#endif

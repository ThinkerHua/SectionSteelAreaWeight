#include "dallocstr.h"
#include "SectionSteel.h"
#include "calculation.h"
#include <stdlib.h>
#include <string.h>

char *SecSteTypeArr[] = {
	"H", "HT", "HI", "T", "J", "D", "I", "[", "[]", "2[",
	"L", "2L", "C", "2C", "Z", "PL", "PLT", "PLD"
};
struct replaceinfo const replacetable[] = {
	{" ", ""},
	{"(", ""},
	{")", ""},
	{"£¨", ""},
	{"£©", ""},
	{"?", ""},
	{"£¿", ""},
	{"¡«", "~"},
	{"£ª", "*"},
	{"x", "*"},
	{"X", "*"},
	{"¡Á", "*"},
	{"¡ª", "-"},
	{"HW", "H"},
	{"HM", "H"},
	{"HN", "H"},
	{"TW", "T"},
	{"TM", "T"},
	{"TN", "T"},
	{"¹¤", "I"},
	{"F", "J"},
	{"][", "2["},
};

int formatting(char const *RawText, char **const p_FormatedText) {
	int i, nums;
	if (RawText == NULL)
		return 0;
	if ((*p_FormatedText = (char *)malloc(strlen(RawText) + 1)) == NULL)
		return -1;
	strcpy(*p_FormatedText, RawText);
	nums = sizeof(replacetable) / sizeof(replacetable[0]);
	for (i = 0; i < nums; i++)
		if (replace(p_FormatedText, replacetable[i].from, replacetable[i].to) <= 0)
			break;
	if (i == nums)
		return 1;
	return 0;
}


char *getSecSteType(char const *FormatedText) {
	int i, nums;
	nums = sizeof(SecSteTypeArr)/sizeof(SecSteTypeArr[0]);
	QSortStrArr(SecSteTypeArr, 0, nums - 1, &strcmp_X);
	for (i = 0; i < nums; i++)
		if (strncmp(FormatedText, SecSteTypeArr[i], strlen(SecSteTypeArr[i])) == 0)
			return SecSteTypeArr[i];
	return NULL;
}

void QSortStrArr(char *strarr[], int const left, int const right, int (*compare)(char const *str1, char const *str2)) {
	int mid, last, i;
	if (left >= right) return;
	mid = (left + right) / 2;
	swap(&strarr[left], &strarr[mid]);
	for (i = left + 1, last = left; i <= right; i++) {
		if (compare(strarr[i], strarr[left]) > 0)
			swap(&strarr[i], &strarr[++last]);
	}
	swap(&strarr[left], &strarr[last]);
	QSortStrArr(strarr, left, last - 1, compare);
	QSortStrArr(strarr, last + 1, right, compare);
}

void swap(char **op1, char **op2) {
	char *temp = NULL;
	if (op1 == op2)
		return;
	temp = *op1;
	*op1 = *op2;
	*op2 = temp;
}

int strcmp_X(char const *str1, char const *str2) {
	int len1, len2;
	len1 = strlen(str1), len2 = strlen(str2);
	if (len1 > len2) return 1;
	if (len1 < len2) return -1;
	return strcmp(str1, str2);
}

void *NewObj(char const *SecSteType) {
	if (strcmp(SecSteType, "H") == 0) {
		return new_H();
	} else if (strcmp(SecSteType, "HT") == 0) {
		return new_HT();
	} else if (strcmp(SecSteType, "HI") == 0)  {
		return new_HI();
	} else if (strcmp(SecSteType, "T") == 0) {
		return new_T();
	} else if (strcmp(SecSteType, "J") == 0) {
		return new_J();
	} else if (strcmp(SecSteType, "D") == 0) {
		return new_D();
	} else if (strcmp(SecSteType, "I") == 0) {
		return new_I();
	} else if (strcmp(SecSteType, "[") == 0) {
		return new_Chan();
	} else if (strcmp(SecSteType, "[]") == 0) {
		return new_Chan_MtM();
	} else if (strcmp(SecSteType, "2[") == 0) {
		return new_Chan_BtB();
	} else if (strcmp(SecSteType, "L") == 0) {
		return new_L();
	} else if (strcmp(SecSteType, "2L") == 0) {
		return new_2L();
	} else if (strcmp(SecSteType, "C") == 0) {
		return new_C();
	} else if (strcmp(SecSteType, "2C") == 0) {
		return new_2C();
	} else if (strcmp(SecSteType, "Z") == 0) {
		return new_Z();
	} else if (strcmp(SecSteType, "PL") == 0) {
		return new_PL();
	} else if (strcmp(SecSteType, "PLT") == 0) {
		return new_PLT();
	} else if (strcmp(SecSteType, "PLD") == 0) {
		return new_PLD();
	} else {
		return NULL;
	}
}

void FreeObj(void **p_obj, char const *SecSteType) {
	if (strcmp(SecSteType, "H") == 0) {
		free_H(p_obj);
	} else if (strcmp(SecSteType, "HT") == 0) {
		free_HT(p_obj);
	} else if (strcmp(SecSteType, "HI") == 0)  {
		free_HI(p_obj);
	} else if (strcmp(SecSteType, "T") == 0) {
		free_T(p_obj);
	} else if (strcmp(SecSteType, "J") == 0) {
		free_J(p_obj);
	} else if (strcmp(SecSteType, "D") == 0) {
		free_D(p_obj);
	} else if (strcmp(SecSteType, "I") == 0) {
		free_I(p_obj);
	} else if (strcmp(SecSteType, "[") == 0) {
		free_Chan(p_obj);
	} else if (strcmp(SecSteType, "[]") == 0) {
		free_Chan_MtM(p_obj);
	} else if (strcmp(SecSteType, "2[") == 0) {
		free_Chan_BtB(p_obj);
	} else if (strcmp(SecSteType, "L") == 0) {
		free_L(p_obj);
	} else if (strcmp(SecSteType, "2L") == 0) {
		free_2L(p_obj);
	} else if (strcmp(SecSteType, "C") == 0) {
		free_C(p_obj);
	} else if (strcmp(SecSteType, "2C") == 0) {
		free_2C(p_obj);
	} else if (strcmp(SecSteType, "Z") == 0) {
		free_Z(p_obj);
	} else if (strcmp(SecSteType, "PL") == 0) {
		free_PL(p_obj);
	} else if (strcmp(SecSteType, "PLT") == 0) {
		free_PLT(p_obj);
	} else if (strcmp(SecSteType, "PLD") == 0) {
		free_PLD(p_obj);
	}
	return;
}

int SetData(void *obj, char const *SecSteType, char const *FormatedText) {
	int (*p_setdata)(void *obj, char const *Formatedtext);
	if (strcmp(SecSteType, "H") == 0) {
		p_setdata = setData_H;
	} else if (strcmp(SecSteType, "HT") == 0) {
		p_setdata = setData_HT;
	} else if (strcmp(SecSteType, "HI") == 0)  {
		p_setdata = setData_HI;
	} else if (strcmp(SecSteType, "T") == 0) {
		p_setdata = setData_T;
	} else if (strcmp(SecSteType, "J") == 0) {
		p_setdata = setData_J;
	} else if (strcmp(SecSteType, "D") == 0) {
		p_setdata = setData_D;
	} else if (strcmp(SecSteType, "I") == 0) {
		p_setdata = setData_I;
	} else if (strcmp(SecSteType, "[") == 0) {
		p_setdata = setData_Chan;
	} else if (strcmp(SecSteType, "[]") == 0) {
		p_setdata = setData_Chan_MtM;
	} else if (strcmp(SecSteType, "2[") == 0) {
		p_setdata = setData_Chan_BtB;
	} else if (strcmp(SecSteType, "L") == 0) {
		p_setdata = setData_L;
	} else if (strcmp(SecSteType, "2L") == 0) {
		p_setdata = setData_2L;
	} else if (strcmp(SecSteType, "C") == 0) {
		p_setdata = setData_C;
	} else if (strcmp(SecSteType, "2C") == 0) {
		p_setdata = setData_2C;
	} else if (strcmp(SecSteType, "Z") == 0) {
		p_setdata = setData_Z;
	} else if (strcmp(SecSteType, "PL") == 0) {
		p_setdata = setData_PL;
	} else if (strcmp(SecSteType, "PLT") == 0) {
		p_setdata = setData_PLT;
	} else if (strcmp(SecSteType, "PLD") == 0) {
		p_setdata = setData_PLD;
	} else {
		return 0;
	}
	return p_setdata(obj, FormatedText);
}

char *getResault(void *obj, char const *SecSteType, unsigned const CtrlCode) {
	char *(*p_getresault)(void *obj, unsigned const CtrlCode);
	if (strcmp(SecSteType, "H") == 0) {
		p_getresault = getResault_H;
	} else if (strcmp(SecSteType, "HT") == 0) {
		p_getresault = getResault_HT;
	} else if (strcmp(SecSteType, "HI") == 0)  {
		p_getresault = getResault_HI;
	} else if (strcmp(SecSteType, "T") == 0) {
		p_getresault = getResault_T;
	} else if (strcmp(SecSteType, "J") == 0) {
		p_getresault = getResault_J;
	} else if (strcmp(SecSteType, "D") == 0) {
		p_getresault = getResault_D;
	} else if (strcmp(SecSteType, "I") == 0) {
		p_getresault = getResault_I;
	} else if (strcmp(SecSteType, "[") == 0) {
		p_getresault = getResault_Chan;
	} else if (strcmp(SecSteType, "[]") == 0) {
		p_getresault = getResault_Chan_MtM;
	} else if (strcmp(SecSteType, "2[") == 0) {
		p_getresault = getResault_Chan_BtB;
	} else if (strcmp(SecSteType, "L") == 0) {
		p_getresault = getResault_L;
	} else if (strcmp(SecSteType, "2L") == 0) {
		p_getresault = getResault_2L;
	} else if (strcmp(SecSteType, "C") == 0) {
		p_getresault = getResault_C;
	} else if (strcmp(SecSteType, "2C") == 0) {
		p_getresault = getResault_2C;
	} else if (strcmp(SecSteType, "Z") == 0) {
		p_getresault = getResault_Z;
	} else if (strcmp(SecSteType, "PL") == 0) {
		p_getresault = getResault_PL;
	} else if (strcmp(SecSteType, "PLT") == 0) {
		p_getresault = getResault_PLT;
	} else if (strcmp(SecSteType, "PLD") == 0) {
		p_getresault = getResault_PLD;
	} else {
		return NULL;
	}
	return p_getresault(obj, CtrlCode);
}


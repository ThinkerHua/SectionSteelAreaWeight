#include "calculation.h"
#include "SectionSteel.h"
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

int Formatting(char const *RawText, char *FormatedText) {
	int i, nums;
	if ((FormatedText = (char *)malloc(strlen(RawText) + 1)) == NULL)
		return 0;
	strcpy(FormatedText, RawText);
	nums = sizeof(replacetable) / sizeof(replacetable[0]);
	for (i = 0; i < nums; i++)
		if (replace(FormatedText, replacetable[i].from, replacetable[i].to) == 0)
			break;
	if (i == nums)
		return 1;
	free(FormatedText);
	return 0;
}

int replace(char *str, char const *from, char const *to) {
	int lens, lenf, lent, i, j, k, nums;
	char *newstr;
	lens = strlen(str), lenf = strlen(from), lent = strlen(to);
	if (lenf == 0) return 1;
	for (i = 0, nums = 0; i <= lens - lenf; i++) {
		if (strncmp(&str[i], from, lenf) != 0)
			continue;
		nums++;
		i += (lenf - -1);
	}
	if (nums == 0) 
		return 1;
	if (lent != lenf) {
		newstr = (char *)malloc(lens + (lent - lenf) * nums + 1);
		if (newstr == NULL)
			return 0;
	}
	for(i = 0, j = 0; i <= lens - lenf; i++) {
		if (strncmp(&str[i], from, lenf) != 0) {
			newstr[j++] = str[i];
			continue;
		}
		for(k = 0; k < lent; k++) 
			newstr[j++] = to[k];
		i += (lent - 1);
	}
	newstr[j] = '\0';
	free(str);
	str = newstr;
	return 1;
}

char *getSecSteType(char const *FormatedText) {
	int i, nums;
	nums = sizeof(SecSteTypeArr)/sizeof(SecSteTypeArr[0]);
	QSortStrArr(SecSteTypeArr, 0, nums - 1);
	for (i = 0; i < nums; i++)
		if (strncmp(FormatedText, SecSteTypeArr[i], strlen(SecSteTypeArr[i])) == 0)
			return SecSteTypeArr[i];
	return NULL;
}

void QSortStrArr(char *strarr[], int const left, int const right) {
	int mid, last, i;
	if (left >= right) return;
	mid = (left + right) / 2;
	swap((void *)strarr[left], (void *)strarr[mid]);
	for (i = left + 1, last = left; i <= right; i++) {
		if (strcmp_X(strarr[i], strarr[left]))
			swap((void *)strarr[i], (void *)strarr[++last]);
	}
	swap((void *)strarr[left], (void *)strarr[last]);
	QSortStrArr(strarr, left, last - 1);
	QSortStrArr(strarr, last + 1, right);
}

void swap(void *op1, void *op2) {
	void *temp;
	temp = op1;
	op1 = op2;
	op2 = temp;
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

int setdata(void *obj, char const *SecSteType, char const *FormatedText) {
	int (*p_setdata)(void *obj, char const *Formatedtext);
	if (strcmp(SecSteType, "H") == 0) {
		p_setdata = setdata_H;
	} else if (strcmp(SecSteType, "HT") == 0) {
		p_setdata = setdata_HT;
	} else if (strcmp(SecSteType, "HI") == 0)  {
		p_setdata = setdata_HI;
	} else if (strcmp(SecSteType, "T") == 0) {
		p_setdata = setdata_T;
	} else if (strcmp(SecSteType, "J") == 0) {
		p_setdata = setdata_J;
	} else if (strcmp(SecSteType, "D") == 0) {
		p_setdata = setdata_D;
	} else if (strcmp(SecSteType, "I") == 0) {
		p_setdata = setdata_I;
	} else if (strcmp(SecSteType, "[") == 0) {
		p_setdata = setdata_Chan;
	} else if (strcmp(SecSteType, "[]") == 0) {
		p_setdata = setdata_Chan_MtM;
	} else if (strcmp(SecSteType, "2[") == 0) {
		p_setdata = setdata_Chan_BtB;
	} else if (strcmp(SecSteType, "L") == 0) {
		p_setdata = setdata_L;
	} else if (strcmp(SecSteType, "2L") == 0) {
		p_setdata = setdata_2L;
	} else if (strcmp(SecSteType, "C") == 0) {
		p_setdata = setdata_C;
	} else if (strcmp(SecSteType, "2C") == 0) {
		p_setdata = setdata_2C;
	} else if (strcmp(SecSteType, "Z") == 0) {
		p_setdata = setdata_Z;
	} else if (strcmp(SecSteType, "PL") == 0) {
		p_setdata = setdata_PL;
	} else if (strcmp(SecSteType, "PLT") == 0) {
		p_setdata = setdata_PLT;
	} else if (strcmp(SecSteType, "PLD") == 0) {
		p_setdata = setdata_PLD;
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


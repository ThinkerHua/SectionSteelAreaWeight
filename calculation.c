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
	{"（", ""},
	{"）", ""},
	{"?", ""},
	{"？", ""},
	{"～", "~"},
	{"＊", "*"},
	{"x", "*"},
	{"X", "*"},
	{"×", "*"},
	{"—", "-"},
	{"HW", "H"},
	{"HM", "H"},
	{"HN", "H"},
	{"TW", "T"},
	{"TM", "T"},
	{"TN", "T"},
	{"工", "I"},
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

int replace(char **const p_str, char const *from, char const *to) {
	int len_s, len_f, len_t, len;
	int i, j, nums, lastmatchedindex;
	char *newstr = NULL;
/*
	不允许传入空字符串，否则返回0
*/ 
	if (*p_str == NULL || from == NULL || to == NULL)
		return 0;
	len_s = strlen(*p_str), len_f = strlen(from), len_t = strlen(to);
	if (len_s == 0) 
		return 0;
/*
	统计出待替换数量nums
*/
	if (len_f == 0) {
		nums = 0;
	} else {
		for (i = 0, nums = 0; i <= len_s - len_f; i++) {
			if (strncmp(&(*p_str)[i], from, len_f) != 0)
				continue;
			nums++;
			i += (len_f - 1);
		}
	}
/*
	计算替换后的字符串需占用的空间大小，并申请新空间 
	申请失败返回-1
*/ 
	newstr = (char *)malloc(len_s + (len_t - len_f) * nums + 1);
	if (newstr == NULL)
		return -1;
/*
	将不需要替换的字符和要替换成的字符依次复制到新空间 
*/
	if (nums == 0) {
		strncpy(newstr, *p_str, len_s + 1);
	} else {
		for (i = 0, lastmatchedindex = 0, j = 0; i <= len_s - len_f;) {
			if (strncmp(&(*p_str)[i], from, len_f) == 0) {
				strncpy(&newstr[j], to, len_t);
				j += len_t;
				i += len_f;
				continue;
			}
			lastmatchedindex = i;
			while (i < len_s && strncmp(&(*p_str)[i], from, len_f) != 0)
				i++;
			len = i - lastmatchedindex;
			strncpy(&newstr[j], &(*p_str)[lastmatchedindex], len);
			j += len;
		}
		newstr[j] = '\0';
	}
	free(*p_str);
	*p_str = newstr;
	newstr = NULL;
	return 1;
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
	swap((void *)strarr[left], (void *)strarr[mid]);
	for (i = left + 1, last = left; i <= right; i++) {
		if (compare(strarr[i], strarr[left]))
			swap((void *)strarr[i], (void *)strarr[++last]);
	}
	swap((void *)strarr[left], (void *)strarr[last]);
	QSortStrArr(strarr, left, last - 1, compare);
	QSortStrArr(strarr, last + 1, right, compare);
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

void FreeObj(void *obj, char const *SecSteType) {
	if (strcmp(SecSteType, "H") == 0) {
		free_H(obj);
	} else if (strcmp(SecSteType, "HT") == 0) {
		free_HT(obj);
	} else if (strcmp(SecSteType, "HI") == 0)  {
		free_HI(obj);
	} else if (strcmp(SecSteType, "T") == 0) {
		free_T(obj);
	} else if (strcmp(SecSteType, "J") == 0) {
		free_J(obj);
	} else if (strcmp(SecSteType, "D") == 0) {
		free_D(obj);
	} else if (strcmp(SecSteType, "I") == 0) {
		free_I(obj);
	} else if (strcmp(SecSteType, "[") == 0) {
		free_Chan(obj);
	} else if (strcmp(SecSteType, "[]") == 0) {
		free_Chan_MtM(obj);
	} else if (strcmp(SecSteType, "2[") == 0) {
		free_Chan_BtB(obj);
	} else if (strcmp(SecSteType, "L") == 0) {
		free_L(obj);
	} else if (strcmp(SecSteType, "2L") == 0) {
		free_2L(obj);
	} else if (strcmp(SecSteType, "C") == 0) {
		free_C(obj);
	} else if (strcmp(SecSteType, "2C") == 0) {
		free_2C(obj);
	} else if (strcmp(SecSteType, "Z") == 0) {
		free_Z(obj);
	} else if (strcmp(SecSteType, "PL") == 0) {
		free_PL(obj);
	} else if (strcmp(SecSteType, "PLT") == 0) {
		free_PLT(obj);
	} else if (strcmp(SecSteType, "PLD") == 0) {
		free_PLD(obj);
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


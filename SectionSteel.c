#include "GBData.h"
#include "SectionSteel.h"
#include <stdlib.h>
#include <string.h>

_SectionSteel_H *new_H_ (void) {
	_SectionSteel_H *obj;
	obj = (_SectionSteel_H *)malloc(sizeof(_SectionSteel_H));
	return obj;
}

SectionSteel_H *new_H (void) {
	SectionSteel_H *obj;
	obj = (SectionSteel_H *)malloc(sizeof(SectionSteel_H));
	return obj;
}

SectionSteel_HT *new_HT (void) {
	SectionSteel_HT *obj;
	obj = (SectionSteel_HT *)malloc(sizeof(SectionSteel_HT));
	return obj;
}

SectionSteel_HI *new_HI (void) {
	SectionSteel_HI *obj;
	obj = (SectionSteel_HI *)malloc(sizeof(SectionSteel_HI));
	return obj;
}

SectionSteel_T *new_T (void) {
	SectionSteel_T *obj;
	obj = (SectionSteel_T *)malloc(sizeof(SectionSteel_T));
	return obj;
}

SectionSteel_J *new_J (void) {
	SectionSteel_J *obj;
	obj = (SectionSteel_J *)malloc(sizeof(SectionSteel_J));
	return obj;
}

SectionSteel_D *new_D (void) {
	SectionSteel_D *obj;
	obj = (SectionSteel_D *)malloc(sizeof(SectionSteel_D));
	return obj;
}

SectionSteel_I *new_I (void) {
	SectionSteel_I *obj;
	obj = (SectionSteel_I *)malloc(sizeof(SectionSteel_I));
	return obj;
}

SectionSteel_Chan *new_Chan (void) {
	SectionSteel_Chan *obj;
	obj = (SectionSteel_Chan *)malloc(sizeof(SectionSteel_Chan));
	return obj;
}

SectionSteel_Chan_MtM *new_Chan_MtM (void) {
	SectionSteel_Chan_MtM *obj;
	obj = (SectionSteel_Chan_MtM *)malloc(sizeof(SectionSteel_Chan_MtM));
	return obj;
}

SectionSteel_Chan_BtB *new_Chan_BtB (void) {
	SectionSteel_Chan_BtB *obj;
	obj = (SectionSteel_Chan_BtB *)malloc(sizeof(SectionSteel_Chan_BtB));
	return obj;
}

SectionSteel_L *new_L (void) {
	SectionSteel_L *obj;
	obj = (SectionSteel_L *)malloc(sizeof(SectionSteel_L));
	return obj;
}

SectionSteel_2L *new_2L (void) {
	SectionSteel_2L *obj;
	obj = (SectionSteel_2L *)malloc(sizeof(SectionSteel_2L));
	return obj;
}

SectionSteel_C *new_C (void) {
	SectionSteel_C *obj;
	obj = (SectionSteel_C *)malloc(sizeof(SectionSteel_C));
	return obj;
}

SectionSteel_2C *new_2C (void) {
	SectionSteel_2C *obj;
	obj = (SectionSteel_2C *)malloc(sizeof(SectionSteel_2C));
	return obj;
}

SectionSteel_Z *new_Z (void) {
	SectionSteel_Z *obj;
	obj = (SectionSteel_Z *)malloc(sizeof(SectionSteel_Z));
	return obj;
}

_SectionSteel_PL *new_PL_ (void) {
	_SectionSteel_PL *obj;
	obj = (_SectionSteel_PL *)malloc(sizeof(_SectionSteel_PL));
	return obj;
}

_SectionSteel_PLT *new_PLT_ (void) {
	_SectionSteel_PLT *obj;
	obj = (_SectionSteel_PLT *)malloc(sizeof(_SectionSteel_PLT));
	return obj;
}

_SectionSteel_PLD *new_PLD_ (void) {
	_SectionSteel_PLD *obj;
	obj = (_SectionSteel_PLD *)malloc(sizeof(_SectionSteel_PLD));
	return obj;
}

SectionSteel_PL *new_PL (void) {
	SectionSteel_PL *obj;
	obj = (SectionSteel_PL *)malloc(sizeof(SectionSteel_PL));
	return obj;
}

SectionSteel_PLT *new_PLT (void) {
	SectionSteel_PLT *obj;
	obj = (SectionSteel_PLT *)malloc(sizeof(SectionSteel_PLT));
	return obj;
}

SectionSteel_PLD *new_PLD (void) {
	SectionSteel_PLD *obj;
	obj = (SectionSteel_PLD *)malloc(sizeof(SectionSteel_PLD));
	return obj;
}

void free_H_(void *object) {
	free(object);
}

void free_H(void *object) {
	free(object);
}

void free_HT(void *object) {
	free(object);
}

void free_HI(void *object) {
	free(object);
}

void free_T(void *object) {
	free(object);
}

void free_J(void *object) {
	free(object);
}

void free_D(void *object) {
	free(object);
}

void free_I(void *object) {
	free(object);
}

void free_Chan(void *object) {
	free(object);
}

void free_Chan_MtM(void *object) {
	free(object);
}

void free_Chan_BtB(void *object) {
	free(object);
}

void free_L(void *object) {
	free(object);
}

void free_2L(void *object) {
	free(object);
}

void free_C(void *object) {
	free(object);
}

void free_2C(void *object) {
	free(object);
}

void free_Z(void *object) {
	free(object);
}

void free_PL_(void *object) {
	free(object);
}

void free_PLT_(void *object) {
	free(object);
}

void free_PLD_(void *object) {
	free(object);
}

void free_PL(void *object) {
	free(object);
}

void free_PLT(void *object) {
	free(object);
}

void free_PLD(void *object) {
	free(object);
}

int setData_H_(void *object, char const *FormatedText) {
	int nums;
	double data[4];
	char **strarr;
	_SectionSteel_H *obj; 
	obj = (_SectionSteel_H *)object;
	//跳过前导类型标识符H 
	nums = strsplit(FormatedText + 1, "*", &strarr);
	switch(nums) {
		case 2:
			obj->ShortH = atof(strarr[0]);
			obj->ShortB = atof(strarr[1]);
			
			break;
		case 4:
			obj->H = average_delim(strarr[0], "~");
			obj->B = average_delim(strarr[1], "~");
			obj->tB = atof(strarr[2]);
			obj->tH = atof(strarr[3]);
			break;
		default:
			break;
	}
}

int setData_H(void *object, char const *FormatedText) {

}

int setData_HT(void *object, char const *FormatedText) {

}

int setData_HI(void *object, char const *FormatedText) {

}

int setData_T(void *object, char const *FormatedText) {

}

int setData_J(void *object, char const *FormatedText) {

}

int setData_D(void *object, char const *FormatedText) {

}

int setData_I(void *object, char const *FormatedText) {

}

int setData_Chan(void *object, char const *FormatedText) {

}

int setData_Chan_MtM(void *object, char const *FormatedText) {

}

int setData_Chan_BtB(void *object, char const *FormatedText) {

}

int setData_L(void *object, char const *FormatedText) {

}

int setData_2L(void *object, char const *FormatedText) {

}

int setData_C(void *object, char const *FormatedText) {

}

int setData_2C(void *object, char const *FormatedText) {

}

int setData_Z(void *object, char const *FormatedText) {

}

int setData_PL_(void *object, char const *FormatedText) {

}

int setData_PLT_(void *object, char const *FormatedText) {

}

int setData_PLD_(void *object, char const *FormatedText) {

}

int setData_PL(void *object, char const *FormatedText) {

}

int setData_PLT(void *object, char const *FormatedText) {

}

int setData_PLD(void *object, char const *FormatedText) {

}

char *getResault_H_(void *object, unsigned const CtrlCode) {

}

char *getResault_H(void *object, unsigned const CtrlCode) {

}

char *getResault_HT(void *object, unsigned const CtrlCode) {

}

char *getResault_HI(void *object, unsigned const CtrlCode) {

}

char *getResault_T(void *object, unsigned const CtrlCode) {

}

char *getResault_J(void *object, unsigned const CtrlCode) {

}

char *getResault_D(void *object, unsigned const CtrlCode) {

}

char *getResault_I(void *object, unsigned const CtrlCode) {

}

char *getResault_Chan(void *object, unsigned const CtrlCode) {

}

char *getResault_Chan_MtM(void *object, unsigned const CtrlCode) {

}

char *getResault_Chan_BtB(void *object, unsigned const CtrlCode) {

}

char *getResault_L(void *object, unsigned const CtrlCode) {

}

char *getResault_2L(void *object, unsigned const CtrlCode) {

}

char *getResault_C(void *object, unsigned const CtrlCode) {

}

char *getResault_2C(void *object, unsigned const CtrlCode) {

}

char *getResault_Z(void *object, unsigned const CtrlCode) {

}

char *getResault_PL_(void *object, unsigned const CtrlCode) {

}

char *getResault_PLT_(void *object, unsigned const CtrlCode) {

}

char *getResault_PLD_(void *object, unsigned const CtrlCode) {

}

char *getResault_PL(void *object, unsigned const CtrlCode) {

}

char *getResault_PLT(void *object, unsigned const CtrlCode) {

}

char *getResault_PLD(void *object, unsigned const CtrlCode) {

}

char *getArea_H_(void *object, unsigned const CtrlCode) {

}

char *getArea_H(void *object, unsigned const CtrlCode) {

}

char *getArea_HT(void *object, unsigned const CtrlCode) {

}

char *getArea_HI(void *object, unsigned const CtrlCode) {

}

char *getArea_T(void *object, unsigned const CtrlCode) {

}

char *getArea_J(void *object, unsigned const CtrlCode) {

}

char *getArea_D(void *object, unsigned const CtrlCode) {

}

char *getArea_I(void *object, unsigned const CtrlCode) {

}

char *getArea_Chan(void *object, unsigned const CtrlCode) {

}

char *getArea_Chan_MtM(void *object, unsigned const CtrlCode) {

}

char *getArea_Chan_BtB(void *object, unsigned const CtrlCode) {

}

char *getArea_L(void *object, unsigned const CtrlCode) {

}

char *getArea_2L(void *object, unsigned const CtrlCode) {

}

char *getArea_C(void *object, unsigned const CtrlCode) {

}

char *getArea_2C(void *object, unsigned const CtrlCode) {

}

char *getArea_Z(void *object, unsigned const CtrlCode) {

}

char *getArea_PL_(void *object, unsigned const CtrlCode) {

}

char *getArea_PLT_(void *object, unsigned const CtrlCode) {

}

char *getArea_PLD_(void *object, unsigned const CtrlCode) {

}

char *getArea_PL(void *object, unsigned const CtrlCode) {

}

char *getArea_PLT(void *object, unsigned const CtrlCode) {

}

char *getArea_PLD(void *object, unsigned const CtrlCode) {

}


char *getWeight_H_(void *object, unsigned const CtrlCode) {

}

char *getWeight_H(void *object, unsigned const CtrlCode) {

}

char *getWeight_HT(void *object, unsigned const CtrlCode) {

}

char *getWeight_HI(void *object, unsigned const CtrlCode) {

}

char *getWeight_T(void *object, unsigned const CtrlCode) {

}

char *getWeight_J(void *object, unsigned const CtrlCode) {

}

char *getWeight_D(void *object, unsigned const CtrlCode) {

}

char *getWeight_I(void *object, unsigned const CtrlCode) {

}

char *getWeight_Chan(void *object, unsigned const CtrlCode) {

}

char *getWeight_Chan_MtM(void *object, unsigned const CtrlCode) {

}

char *getWeight_Chan_BtB(void *object, unsigned const CtrlCode) {

}

char *getWeight_L(void *object, unsigned const CtrlCode) {

}

char *getWeight_2L(void *object, unsigned const CtrlCode) {

}

char *getWeight_C(void *object, unsigned const CtrlCode) {

}

char *getWeight_2C(void *object, unsigned const CtrlCode) {

}

char *getWeight_Z(void *object, unsigned const CtrlCode) {

}

char *getWeight_PL_(void *object, unsigned const CtrlCode) {

}

char *getWeight_PLT_(void *object, unsigned const CtrlCode) {

}

char *getWeight_PLD_(void *object, unsigned const CtrlCode) {

}

char *getWeight_PL(void *object, unsigned const CtrlCode) {

}

char *getWeight_PLT(void *object, unsigned const CtrlCode) {

}

char *getWeight_PLD(void *object, unsigned const CtrlCode) {

}

int strsplit(char const *str, char const *delim, char  ***const p_strarr) {
	int len_s, len_d;
	int i, lastmatchedindex, index;
	int nums, j;
	char *item = NULL;
/*
	不允许传入空字符串,否则返回-1
*/
	if (str == NULL || delim == NULL)
		return -1;
	len_s = strlen(str), len_d = strlen(delim);
	if (len_s == 0 || len_d == 0)
		return -1;
/*
	nums为分隔完成后字符串数组项目数
	循环体统每次循环统计出分隔符左侧应分隔出的项目数
	（分隔符在开头出现，以及连续出现分隔符，则不计数）
	循环体结束再判断最后一个分隔符右侧是否存在待分隔的项目
*/
	for (i = 0, lastmatchedindex = 0, nums = 0; i <= len_s - len_d; i++) {
		if (strncmp(&str[i], delim, len_d) != 0)
			continue;
		if (i == 0 || i == lastmatchedindex + len_d) {
			;//分隔符在开头出现，或者连续出现分隔符
		} else {
			nums++;
		}
		lastmatchedindex = i;
		i += (len_d - 1);
	}
	if (len_s > lastmatchedindex + len_d)
		nums++;
/*
	计数器为0，即被分隔后没有剩下的字符串
*/
	if (nums == 0)
		return nums;
/*
	申请字符串指针数组存储空间
*/
	*p_strarr = (char **)malloc(sizeof(char *) * nums);
	if (*p_strarr == NULL)
		return -1;
/*
	每次循环找出分隔出的字符串，申请存储空间，创建副本
	申请不成功要将前面已申请的空间（包括*strarr）释放掉，并返回NULL
*/
	for (i = 0, index = 0; i <= len_s - len_d; i++) {
		if (strncmp(&str[i], delim, len_d) == 0) {
			i += (len_d - 1);
			continue;
		}
		lastmatchedindex = i;
		while(str[i] != '\0' && strncmp(&str[i], delim, len_d) !=0) {
			i++;
		}
		item = (void *)malloc(i - lastmatchedindex + 1);
		if (item == NULL) {
			for (j = 0; j < nums; j++) 
				if ((*p_strarr)[j] != NULL) 
					free ((*p_strarr)[j]), (*p_strarr)[j] == NULL;
			free(*p_strarr), *p_strarr = NULL;
			return -1;
		}
		strncpy(item, &str[lastmatchedindex], i - lastmatchedindex);
		item[i - lastmatchedindex] = '\0';
		(*p_strarr)[index++] = item;
		item = NULL;
		if (str[i] == '\0')
			break;
		i += (len_d - 1);
	}
	return nums;
}

void strsplit_free(char ***const p_strarr, int const nums) {
	int i;
	if (*p_strarr == NULL) 
		return;
	for (i = 0; i < nums; i++) 
		free((*p_strarr)[i]), (*p_strarr)[i] = NULL;
	free(*p_strarr), *p_strarr = NULL;
}

double average_delim(char const *str, char const *delim) {
	int i, nums;
	double value;
	char **strarr;
	nums = strsplit(str, delim, &strarr);
	if (nums < 0)
		return 0;
	else if (nums == 0)
		value = atof(str);
	else {
		for (i = 0, value = 0; i < nums; i++) 
			value += atof(strarr[i]);
		value /= nums;
		strsplit_free(&strarr, nums);
	}
	return value;
}

char *dtostr(double const d, unsigned const pre) {
	int i = 0;
	int sign = 1;//正负标记 
	int pow = 1;
	int len_i, len_f;
	long num;
	char *int_part = NULL;//整数部分 
	char *float_part = NULL; //小数部分 
	char *str = NULL;
	int_part = ltostr(d);
	if (int_part == NULL) 
		return NULL;
	if (pre == 0)
		return int_part;
	while (++i <= pre)
		pow *= 10;
	num = (d - (long)d) * pow;
	if (num < 0) 
		num = ~num + 1;
	float_part = ltostr(num);
	if (float_part == NULL) {
		free(int_part);
		return NULL;
	}
	len_i = strlen(int_part), len_f = strlen(float_part);
	for (i = len_f; i > 0;) {
		if (float_part[--i] != '0') 
			break;
		len_f--;
	}
	float_part[len_f] = '\0';
	if (len_f == 0) 
		return int_part;
	str = (char *)malloc(len_i + len_f + 2);
	if (str == NULL)
		free(int_part), free(float_part);
	strcpy(str, int_part);
	str[len_i] = '.';
	strcpy(&str[++len_i], float_part);
	free(int_part), free(float_part);
	return str;
}

char *ltostr(long const l) {
	int digits;//位数 
	int sign = 1;//正负标记 
	long num, i;
	char *str = NULL;
	num = l;
	if (num < 0) {
		sign = -1;
		num = ~num + 1;
	}
	for (digits = 0, i = num; i > 0; i /= 10) 
		digits++;
	if (sign == -1) 
		digits++;
	str = (char *)malloc(digits + 1);
	if (str == NULL) 
		return NULL;
	for (str[digits--] = '\0'; digits >= 0; digits--) {
		str[digits] = num % 10 + '0';
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return str;
}

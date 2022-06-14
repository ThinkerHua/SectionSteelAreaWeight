#include "GBData.h"
#include "SectionSteel.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

SectionSteel_H_ *new_H_ (void) {
	SectionSteel_H_ *obj;
	obj = (SectionSteel_H_ *)malloc(sizeof(SectionSteel_H_));
	if (obj == NULL)
		return NULL;
	obj->Type = "H";
	obj->ShortH = obj->ShortB = obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_H *new_H (void) {
	SectionSteel_H *obj;
	obj = (SectionSteel_H *)malloc(sizeof(SectionSteel_H));
	if (obj == NULL)
		return NULL;
	obj->Type = "H";
	obj->ShortH = obj->ShortB = 
	obj->H = obj->B1 = obj->B2 = obj->tH = obj->tB1 = obj->tB2 = 0;
	return obj;
}

SectionSteel_HT *new_HT (void) {
	SectionSteel_HT *obj;
	obj = (SectionSteel_HT *)malloc(sizeof(SectionSteel_HT));
	if (obj == NULL)
		return NULL;
	obj->Type = "HT";
	obj->ShortH = obj->ShortB = obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_HI *new_HI (void) {
	SectionSteel_HI *obj;
	obj = (SectionSteel_HI *)malloc(sizeof(SectionSteel_HI));
	if (obj == NULL)
		return NULL;
	obj->Type = "HI";
	obj->H1 = obj->B1 = obj->tH1 = obj->tB1 = 
	obj->H2 = obj->B2 = obj->tH2 = obj->tB2 = 0;
	return obj;
}

SectionSteel_T *new_T (void) {
	SectionSteel_T *obj;
	obj = (SectionSteel_T *)malloc(sizeof(SectionSteel_T));
	if (obj == NULL)
		return NULL;
	obj->Type = "T";
	obj->ShortH = obj->ShortB = obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_J *new_J (void) {
	SectionSteel_J *obj;
	obj = (SectionSteel_J *)malloc(sizeof(SectionSteel_J));
	if (obj == NULL)
		return NULL;
	obj->Type = "J";
	obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_D *new_D (void) {
	SectionSteel_D *obj;
	obj = (SectionSteel_D *)malloc(sizeof(SectionSteel_D));
	if (obj == NULL)
		return NULL;
	obj->Type = "D";
	obj->D = obj->t = 0;
	return obj;
}

SectionSteel_I *new_I (void) {
	SectionSteel_I *obj;
	obj = (SectionSteel_I *)malloc(sizeof(SectionSteel_I));
	if (obj == NULL)
		return NULL;
	obj->Type = "I";
	obj->Name = NULL;
	obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_Chan *new_Chan (void) {
	SectionSteel_Chan *obj;
	obj = (SectionSteel_Chan *)malloc(sizeof(SectionSteel_Chan));
	if (obj == NULL)
		return NULL;
	obj->Type = "[";
	obj->Name = NULL;
	obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_Chan_MtM *new_Chan_MtM (void) {
	SectionSteel_Chan_MtM *obj;
	obj = (SectionSteel_Chan_MtM *)malloc(sizeof(SectionSteel_Chan_MtM));
	if (obj == NULL)
		return NULL;
	obj->Type = "[]";
	obj->Name = NULL;
	obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_Chan_BtB *new_Chan_BtB (void) {
	SectionSteel_Chan_BtB *obj;
	obj = (SectionSteel_Chan_BtB *)malloc(sizeof(SectionSteel_Chan_BtB));
	if (obj == NULL)
		return NULL;
	obj->Type = "2[";
	obj->Name = NULL;
	obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_L *new_L (void) {
	SectionSteel_L *obj;
	obj = (SectionSteel_L *)malloc(sizeof(SectionSteel_L));
	if (obj == NULL)
		return NULL;
	obj->Type = "L";
	obj->Name = NULL;
	obj->B1 = obj->B2 = obj->t = 0;
	return obj;
}

SectionSteel_2L *new_2L (void) {
	SectionSteel_2L *obj;
	obj = (SectionSteel_2L *)malloc(sizeof(SectionSteel_2L));
	if (obj == NULL)
		return NULL;
	obj->Type = "2L";
	obj->Name = NULL;
	obj->B1 = obj->B2 = obj->t = 0;
	return obj;
}

SectionSteel_C *new_C (void) {
	SectionSteel_C *obj;
	obj = (SectionSteel_C *)malloc(sizeof(SectionSteel_C));
	if (obj == NULL)
		return NULL;
	obj->Type = "C";
	obj->H = obj->B = obj->C = obj->t = 0;
	return obj;
}

SectionSteel_2C *new_2C (void) {
	SectionSteel_2C *obj;
	obj = (SectionSteel_2C *)malloc(sizeof(SectionSteel_2C));
	if (obj == NULL)
		return NULL;
	obj->Type = "2C";
	obj->H = obj->B = obj->C = obj->t = 0;
	return obj;
}

SectionSteel_Z *new_Z (void) {
	SectionSteel_Z *obj;
	obj = (SectionSteel_Z *)malloc(sizeof(SectionSteel_Z));
	if (obj == NULL)
		return NULL;
	obj->Type = "Z";
	obj->H = obj->B = obj->C = obj->t = 0;
	return obj;
}

SectionSteel_PL_ *new_PL_ (void) {
	SectionSteel_PL_ *obj;
	obj = (SectionSteel_PL_ *)malloc(sizeof(SectionSteel_PL_));
	if (obj == NULL)
		return NULL;
	obj->Type = "PL";
	obj->B = obj->L = obj->t = 0;
	obj->pNext = NULL;
	return obj;
}

SectionSteel_PLT_ *new_PLT_ (void) {
	SectionSteel_PLT_ *obj;
	obj = (SectionSteel_PLT_ *)malloc(sizeof(SectionSteel_PLT_));
	if (obj == NULL)
		return NULL;
	obj->Type = "PLT";
	obj->B = obj->L = obj->t = 0;
	obj->pNext = NULL;
	return obj;
}

SectionSteel_PLD_ *new_PLD_ (void) {
	SectionSteel_PLD_ *obj;
	obj = (SectionSteel_PLD_ *)malloc(sizeof(SectionSteel_PLD_));
	if (obj == NULL)
		return NULL;
	obj->Type = "PLD";
	obj->D = obj->t = 0;
	obj->pNext = NULL;
	return obj;
}

SectionSteel_PL *new_PL (void) {
	SectionSteel_PL *obj;
	obj = (SectionSteel_PL *)malloc(sizeof(SectionSteel_PL));
	obj->pPL = NULL;
	obj->pPLT = NULL;
	obj->pPLD = NULL;
	return obj;
}

SectionSteel_PLT *new_PLT (void) {
	SectionSteel_PLT *obj;
	obj = (SectionSteel_PLT *)malloc(sizeof(SectionSteel_PLT));
	if (obj == NULL)
		return NULL;
	obj->Type = "PLT";
	obj->B = obj->L = obj->t = 0;
	return obj;
}

SectionSteel_PLD *new_PLD (void) {
	SectionSteel_PLD *obj;
	obj = (SectionSteel_PLD *)malloc(sizeof(SectionSteel_PLD));
	if (obj == NULL)
		return NULL;
	obj->Type = "PLD";
	obj->D = obj->t = 0;
	return obj;
}

void free_H_(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_H(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_HT(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_HI(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_T(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_J(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_D(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_I(void **p_object) {
	SectionSteel_I *obj;
	obj = *p_object;
	free(obj->Name);
	free(*p_object);
	*p_object = NULL;
}

void free_Chan(void **p_object) {
	SectionSteel_Chan *obj;
	obj = *p_object;
	free(obj->Name);
	free(*p_object);
	*p_object = NULL;
}

void free_Chan_MtM(void **p_object) {
	SectionSteel_Chan_MtM *obj;
	obj = *p_object;
	free(obj->Name);
	free(*p_object);
	*p_object = NULL;
}

void free_Chan_BtB(void **p_object) {
	SectionSteel_Chan_BtB *obj;
	obj = *p_object;
	free(obj->Name);
	free(*p_object);
	*p_object = NULL;
}

void free_L(void **p_object) {
	SectionSteel_L *obj;
	obj = *p_object;
	free(obj->Name);
	free(*p_object);
	*p_object = NULL;
}

void free_2L(void **p_object) {
	SectionSteel_2L *obj;
	obj = *p_object;
	free(obj->Name);
	free(*p_object);
	*p_object = NULL;
}

void free_C(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_2C(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_Z(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_PL_(void **p_object) {
	SectionSteel_PL_ *obj = *p_object;
	if (obj->pNext != NULL)
		free_PL_((void **)&obj->pNext);
	free(*p_object);
	*p_object = NULL;
}

void free_PLT_(void **p_object) {
	SectionSteel_PLT_ *obj = *p_object;
	if (obj->pNext != NULL)
		free_PLT_((void **)&obj->pNext);
	free(*p_object);
	*p_object = NULL;
}

void free_PLD_(void **p_object) {
	SectionSteel_PLD_ *obj = *p_object;
	if (obj->pNext != NULL)
		free_PLD_((void **)&obj->pNext);
	free(*p_object);
	*p_object = NULL;
}

void free_PL(void **p_object) {
	SectionSteel_PL *obj = *p_object;
	if (obj->pPL != NULL)
		free_PL_((void **)&obj->pPL);
	if (obj->pPLT != NULL)
		free_PLT_((void **)&obj->pPLT);
	if (obj->pPLD != NULL)
		free_PLD_((void **)&obj->pPLD);
	free(*p_object);
	*p_object = NULL;
}

void free_PLT(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

void free_PLD(void **p_object) {
	free(*p_object);
	*p_object = NULL;
}

int setData_H_(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_H_ *obj = object; 
	
	//跳过前导类型标识符H
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, LINKSYM, &strarr);
	switch(nums) {
		case 2:
			obj->ShortH = atof(strarr[0]);
			obj->ShortB = atof(strarr[1]);
			if (expand_H_(object) == 0) 
				failure = 1;
			break;
		case 4:
			obj->H = average_delim(strarr[0], GRADSYM);
			obj->B = average_delim(strarr[1], GRADSYM);
			obj->tH = atof(strarr[2]);
			obj->tB = atof(strarr[3]);
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf("Debug: H = %.1f,  B = %.1f,  tH = %.1f,  tB= %.1f\n", 
//					obj->H, 	obj->B, 	obj->tH, 	obj->tB);
	return 1;
}

int expand_H_(void *object) {
	char *Name = NULL, *Name1 = NULL, *Name2 = NULL;
	double const *data = NULL;
	double partdata[2] = {0};
	SectionSteel_H_ *obj = object;
	
	Name = (char *)calloc(GBSECSTE_NAME_LENGTH, sizeof(char));
	if (Name == NULL)
		return 0;
	*Name = '\0';
	
	Name1 = dtostr(obj->ShortH, DATA_PRECISION);
	Name2 = dtostr(obj->ShortB, DATA_PRECISION);
	if (Name1 == NULL || Name2 == NULL) {
		free(Name), free(Name1), free(Name2);
		Name = NULL, Name1 = NULL, Name2 = NULL;
		return 0;
	}
	Name = strcat(Name, Name1);
	Name = strcat(Name, LINKSYM);
	Name = strcat(Name, Name2);
	
	//将数据当做型号名进行搜索，搜索不到则当做缺省数据进行搜索 
	data = search_Data_ByName(obj->Type, Name);
	free(Name1), free(Name2);
	if (data == NULL) {
		free(Name);
		partdata[0] = obj->ShortH, partdata[1] = obj->ShortB;
		data = search_Data_ByPart(obj->Type, partdata, 2);
		if (data == NULL)
			return 0;
	}
	
	obj->H = data[0];
	obj->B = data[1];
	obj->tH = data[2];
	obj->tB = data[3];
	return 1;
}

int setData_H(void *object, char const *FormatedText) {
	int failure = 0;
	int nums1 = 0, nums2 = 0;
	char const *DataText = NULL;
	char **strarr1 = NULL, **strarr2 = NULL;
	SectionSteel_H *obj = object; 
	
	//跳过前导类型标识符H 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums1 = strsplit(DataText, LINKSYM, &strarr1);
	switch(nums1) {
		case 2:
			obj->ShortH = atof(strarr1[0]);
			obj->ShortB = atof(strarr1[1]);
			if (expand_H(object) == 0) 
				failure = 1;
			break;
		case 4:
			obj->H = average_delim(strarr1[0], GRADSYM);
			{		
				nums2 = strsplit(strarr1[1], DIVSYM, &strarr2);
				obj->B1 = average_delim(strarr2[0], GRADSYM);
				if (nums2 == 2) 
					obj->B2 = average_delim(strarr2[1], GRADSYM);
				else
					obj->B2 = obj->B1;
				strsplit_free(&strarr2, nums2);
			}	
			obj->tH = atof(strarr1[2]);
			{
				nums2 = strsplit(strarr1[3], DIVSYM, &strarr2);
				obj->tB1 = atof(strarr2[0]);
				if (nums2 == 2) 
					obj->tB2 = atof(strarr2[1]);
				else
					obj->tB2 = obj->tB1;
				strsplit_free(&strarr2, nums2);
			}
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr1, nums1);
	if (failure)
		return 0;
//	printf("Debug: H = %.1f,  B1 = %.1f,  B2 = %.1f,  tH = %.1f,  tB1= %.1f,  tB2= %.1f\n", 
//					obj->H, 	obj->B1, 	obj->B2, 	obj->tH, 	obj->tB1,	obj->tB2);
	return 1;
}

int expand_H(void *object) {
	int failure = 0;
	SectionSteel_H_ *_obj = NULL;
	SectionSteel_H *obj = object;
	
	_obj = new_H_();
	if (_obj == NULL)
		return 0;
		
	_obj->ShortH = obj->ShortH;
	_obj->ShortB = obj->ShortB;
	
	if (expand_H_(_obj)) {
		obj->H = _obj->H;
		obj->B1 = obj->B2 = _obj->B;
		obj->tH = _obj->tH;
		obj->tB1 = obj->tB2 = _obj->tB;
	} else
		failure = 1;
	
	free_H_((void **)&_obj);
	if (failure)
		return 0;
	return 1;
}

int setData_HT(void *object, char const *FormatedText) {
	if (setData_H_(object, FormatedText) == 0)
		return 0;
	return 1;
}

int setData_HI(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_H_ *sub_H1 = NULL, *sub_H2 = NULL;
	SectionSteel_HI *obj = object;
	
	//跳过前导类型标识符HI 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, WELDSYM, &strarr);
	switch(nums) {
		case 1:
			sub_H1 = new_H_();
			if (sub_H1 == NULL) {
				failure = 1;
				break;
			}
			if (setData_H_(sub_H1, strarr[0]) == 0) {
				failure = 1;
				break;
			}
			obj->H1 = obj->H2 = sub_H1->H;
			obj->B1 = obj->B2 = sub_H1->B;
			obj->tH1 = obj->tH2 = sub_H1->tH;
			obj->tB1 = obj->tB2 = sub_H1->tB;
			free_H_((void **)&sub_H1);
			break;
		case 2:
			sub_H1 = new_H_(), sub_H2 = new_H_();
			if (sub_H1 == NULL || sub_H2 == NULL) {
				failure = 1;
				break;
			}
			if (setData_H_(sub_H1, strarr[0]) == 0 || setData_H_(sub_H2, strarr[1]) == 0) {
				failure = 1;
				break;
			}
			obj->H1 = sub_H1->H;
			obj->B1 = sub_H1->B;
			obj->tH1 = sub_H1->tH;
			obj->tB1 = sub_H1->tB;
			obj->H2 = sub_H2->H;
			obj->B2 = sub_H2->B;
			obj->tH2 = sub_H2->tH;
			obj->tB2 = sub_H2->tB;
			break;
		default:
			failure = 1;
			break;
	}
	
	free_H_((void **)&sub_H1);
	free_H_((void **)&sub_H2);
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf(	"Debug: H1 = %.1f,  B1 = %.1f,  tH1 = %.1f,  tB1= %.1f\n"
//			"       H2 = %.1f,  B2 = %.1f,  tH2 = %.1f,  tB2= %.1f\n", 
//					obj->H1, 	obj->B1, 	obj->tH1,	obj->tB1,
//					obj->H2, 	obj->B2, 	obj->tH2, 	obj->tB2);
	return 1;
}

int setData_T(void *object, char const *FormatedText) {
	if (setData_H_(object, FormatedText) == 0)
		return 0;
	return 1;
}

int setData_J(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_J *obj = object;

	//跳过前导类型标识符J 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, LINKSYM, &strarr);
	switch(nums) {
		case 2:
			obj->H = obj->B = average_delim(strarr[0], GRADSYM);
			obj->tH = obj->tB = atof(strarr[1]);
			break;
		case 3:
			obj->H = average_delim(strarr[0], GRADSYM);
			obj->B = average_delim(strarr[1], GRADSYM);
			obj->tH = obj->tB = atof(strarr[2]);
			break;
		case 4:
			obj->H = average_delim(strarr[0], GRADSYM);
			obj->B = average_delim(strarr[1], GRADSYM);
			obj->tH = atof(strarr[2]);
			obj->tB = atof(strarr[3]);
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf("Debug: H = %.1f,  B = %.1f,  tH = %.1f,  tB= %.1f\n", 
//					obj->H,		obj->B,		obj->tH, 	obj->tB);
	return 1;
}

int setData_D(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_D *obj = object;

	//跳过前导类型标识符D 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, LINKSYM, &strarr);
	switch(nums) {
		case 2:
			obj->D = atof(strarr[0]);
			obj->t = atof(strarr[1]);
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf("Debug: D = %.1f,  t= %.1f\n", 
//					obj->D,		obj->t);
	return 1;

}

int setData_I(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_I *obj = object;

	//跳过前导类型标识符I 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, LINKSYM, &strarr);
	switch(nums) {
		case 1:
			//strarr会被释放掉，Name必须申请一片新空间以复制 
			obj->Name = (char *)calloc(strlen(strarr[0]) + 1, sizeof(char));
			if (obj->Name == NULL) {
				failure = 1;
				break;
			}
			*obj->Name = '\0';
			strcpy(obj->Name, strarr[0]);
			if (expand_I(object) == 0)
				failure = 1;
			break;
		case 2:
			obj->H = atof(strarr[0]);
			obj->B = atof(strarr[1]);
			if (expand_I(object) == 0)
				failure = 1;
			break;
		case 4: case 5: 
			obj->H = atof(strarr[0]);
			obj->B = atof(strarr[1]);
			obj->tH = atof(strarr[2]);
			obj->tB = atof(strarr[3]);
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf("Debug: H = %.1f,  B = %.1f,  tH = %.1f,  tB= %.1f\n", 
//					obj->H,		obj->B,		obj->tH, 	obj->tB);
	return 1;
}

int expand_I(void *object) {
	double const *data = NULL;
	double partdata[2] = {0};
	SectionSteel_I *obj = object;
	
	partdata[0] = obj->H, partdata[1] = obj->B;
	//存在Name则根据Name进行搜索，不存在则根据缺省数据进行搜索 
	if (obj->Name == NULL)
		data = search_Data_ByPart(obj->Type, partdata, 2);
	else
		data = search_Data_ByName(obj->Type, obj->Name);
	if (data == NULL) 
		return 0;
	
	obj->H = data[0];
	obj->B = data[1];
	obj->tH = data[2];
	obj->tB = data[3];
	return 1;
}

int setData_Chan(void *object, char const *FormatedText) {
	return setData_I(object, FormatedText);
}

int setData_Chan_MtM(void *object, char const *FormatedText) {
	return setData_I(object, FormatedText);
}

int setData_Chan_BtB(void *object, char const *FormatedText) {
	return setData_I(object, FormatedText);
}

int setData_L(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_L *obj = object;

	//跳过前导类型标识符L 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, LINKSYM, &strarr);
	switch(nums) {
		case 1:
			//strarr会被释放掉，Name必须申请一片新空间以复制 
			obj->Name = (char *)calloc(strlen(strarr[0]) + 1, sizeof(char));
			if (obj->Name == NULL) {
				failure = 1;
				break;
			}
			*obj->Name = '\0';
			strcpy(obj->Name, strarr[0]);
			if (expand_L(object) == 0)
				failure = 1;
			break;
		case 2:
			obj->B1 = obj->B2 = atof(strarr[0]);
			obj->t = atof(strarr[1]);
			break;
		case 3:
			obj->B1 = atof(strarr[0]);
			obj->B2 = atof(strarr[1]);
			obj->t = atof(strarr[2]);
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf("Debug: B1 = %.1f,  B2 = %.1f,  t = %.1f\n", 
//					obj->B1,	obj->B2,	obj->t);
	return 1;
}

int expand_L(void *object) {
	double const *data = NULL;
	SectionSteel_L *obj = object;
	
	//存根据Name进行搜索
	if (obj->Name == NULL)
		return 0;
	data = search_Data_ByName(obj->Type, obj->Name);
	if (data == NULL) 
		return 0;
	
	obj->B1 = data[0];
	obj->B2 = data[1];
	obj->t = data[2];
	return 1;
}

int setData_2L(void *object, char const *FormatedText) {
	return setData_L(object, FormatedText);
}

int setData_C(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_C *obj = object;

	//跳过前导类型标识符C 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, LINKSYM, &strarr);
	switch(nums) {
		case 4:	
			obj->H = atof(strarr[0]);
			obj->B = atof(strarr[1]);
			obj->C = atof(strarr[2]);
			obj->t = atof(strarr[3]);
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf("Debug: H = %.1f,  B = %.1f,  C = %.1f,  t = %.1f\n", 
//					obj->H,		obj->B,		obj->C, 	obj->t);
	return 1;
}

int setData_2C(void *object, char const *FormatedText) {
	return setData_C(object, FormatedText);
}

int setData_Z(void *object, char const *FormatedText) {
	return setData_C(object, FormatedText);
}

int setData_PL_(void *object, char const *FormatedText) {
	return setData_PLT(object, FormatedText);
}

int setData_PLT_(void *object, char const *FormatedText) {
	return setData_PLT(object, FormatedText);
}

int setData_PLD_(void *object, char const *FormatedText) {
	return setData_PLD(object, FormatedText);
}

int setData_PL(void *object, char const *FormatedText) {
	int i;
	int failure = 0;
	int nums = 0;
	char **strarr = NULL;
	SectionSteel_PL *obj = object;
	SectionSteel_PL_ *sub_PL = NULL;
	SectionSteel_PLT_ *sub_PLT = NULL;
	SectionSteel_PLD_ *sub_PLD = NULL;
	
	nums = strsplit(FormatedText, CUTSYM, &strarr);
	for (i = nums - 1; i >= 0; i--) {
		if (strncmp(strarr[i], "PLD", 3) == 0) {
			sub_PLD = new_PLD_();
			if (sub_PLD == NULL) {
				failure = 1;
				break;
			}
			if (setData_PLD_(sub_PLD, strarr[i]) == 0) {
				failure = 1;
				free_PLD_((void **)&sub_PLD);
				break;
			}
			sub_PLD->pNext = obj->pPLD;
			obj->pPLD = sub_PLD;
		} else if (strncmp(strarr[i], "PLT", 3) == 0) {
			sub_PLT = new_PLT_();
			if (sub_PLT == NULL) {
				failure = 1;
				break;
			}
			if (setData_PLT_(sub_PLT, strarr[i]) == 0) {
				failure = 1;
				free_PLT_((void **)&sub_PLT);
				break;
			}
			sub_PLT->pNext = obj->pPLT;
			obj->pPLT = sub_PLT;
		} else if (strncmp(strarr[i], "PL", 2) == 0) {
			sub_PL = new_PL_();
			if (sub_PL == NULL) {
				failure = 1;
				break;
			}
			if (setData_PL_(sub_PL, strarr[i]) == 0) {
				failure = 1;
				free_PL_((void **)&sub_PL);
				break;
			}
			sub_PL->pNext = obj->pPL;
			obj->pPL = sub_PL;
		} else 
			continue;
	}
	
	strsplit_free(&strarr, nums);
	if (failure) 
		return 0;
	return 1;
}

int setData_PLT(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_PLT *obj = object;

	//跳过前导类型标识符PLT 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, LINKSYM, &strarr);
	switch(nums) {
		case 2:	
			obj->B = average_delim(strarr[0], GRADSYM);
			obj->t = atof(strarr[1]);
			break;
		case 3:
			obj->B = average_delim(strarr[0], GRADSYM);
			obj->L = average_delim(strarr[1], GRADSYM);
			obj->t = atof(strarr[2]);
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf("Debug: B = %.1f,  L = %.1f,  t = %.1f\n", 
//					obj->B,		obj->L, 	obj->t);
	return 1;
}

int setData_PLD(void *object, char const *FormatedText) {
	int failure = 0;
	int nums = 0;
	char const *DataText = NULL;
	char **strarr = NULL;
	SectionSteel_PLD *obj = object;

	//跳过前导类型标识符PLD 
	//不使用字符串常量而采用此办法可以解决继承结构调用本函数的问题 
	DataText = strstr(FormatedText, obj->Type);
	if (DataText == NULL)
		DataText = FormatedText;
	else
		DataText = FormatedText + strlen(obj->Type);
		
	nums = strsplit(DataText, LINKSYM, &strarr);
	switch(nums) {
		case 2:	
			obj->D = atof(strarr[0]);
			obj->t = atof(strarr[1]);
			break;
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
//	printf("Debug: D = %.1f,  t = %.1f\n", 
//					obj->D, 	obj->t);
	return 1;
}

char *getResault_H_(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_H_(object, CtrlCode);
	else
		getWeight_H_(object, CtrlCode);
}

char *getResault_H(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_H(object, CtrlCode);
	else
		getWeight_H(object, CtrlCode);
}

char *getResault_HT(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_HT(object, CtrlCode);
	else
		getWeight_HT(object, CtrlCode);
}

char *getResault_HI(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_HI(object, CtrlCode);
	else
		getWeight_HI(object, CtrlCode);
}

char *getResault_T(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_T(object, CtrlCode);
	else
		getWeight_T(object, CtrlCode);
}

char *getResault_J(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_J(object, CtrlCode);
	else
		getWeight_J(object, CtrlCode);
}

char *getResault_D(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_D(object, CtrlCode);
	else
		getWeight_D(object, CtrlCode);
}

char *getResault_I(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_I(object, CtrlCode);
	else
		getWeight_I(object, CtrlCode);
}

char *getResault_Chan(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_Chan(object, CtrlCode);
	else
		getWeight_Chan(object, CtrlCode);
}

char *getResault_Chan_MtM(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_Chan_MtM(object, CtrlCode);
	else
		getWeight_Chan_MtM(object, CtrlCode);
}

char *getResault_Chan_BtB(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_Chan_BtB(object, CtrlCode);
	else
		getWeight_Chan_BtB(object, CtrlCode);
}

char *getResault_L(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_L(object, CtrlCode);
	else
		getWeight_L(object, CtrlCode);
}

char *getResault_2L(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_2L(object, CtrlCode);
	else
		getWeight_2L(object, CtrlCode);
}

char *getResault_C(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_C(object, CtrlCode);
	else
		getWeight_C(object, CtrlCode);
}

char *getResault_2C(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_2C(object, CtrlCode);
	else
		getWeight_2C(object, CtrlCode);
}

char *getResault_Z(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_Z(object, CtrlCode);
	else
		getWeight_Z(object, CtrlCode);
}

char *getResault_PL_(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_PL_(object, CtrlCode);
	else
		getWeight_PL_(object, CtrlCode);
}

char *getResault_PLT_(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_PLT_(object, CtrlCode);
	else
		getWeight_PLT_(object, CtrlCode);
}

char *getResault_PLD_(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_PLD_(object, CtrlCode);
	else
		getWeight_PLD_(object, CtrlCode);
}

char *getResault_PL(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_PL(object, CtrlCode);
	else
		getWeight_PL(object, CtrlCode);
}

char *getResault_PLT(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_PLT(object, CtrlCode);
	else
		getWeight_PLT(object, CtrlCode);
}

char *getResault_PLD(void *object, unsigned const CtrlCode) {
	if (CtrlCode & TYPE_AREA)
		getArea_PLD(object, CtrlCode);
	else
		getWeight_PLD(object, CtrlCode);
}

char *getArea_H_(void *object, unsigned const CtrlCode) {
	SectionSteel_H_ *obj = object;
	char *area = NULL, *temp = NULL;
	double data[] = {obj->H, obj->B, obj->tH, obj->tB};
	int multi = 4;
	double val = 0.0;
		
	if (CtrlCode & METHOD_LOOKUP) {
		val = search_AorW(obj->Type, data, sizeof(data)/sizeof(double), 0);
		if (val == 0.0)
			return NULL;
		area = dtostr(val, DATA_PRECISION);
		if (area == NULL)
			return NULL;
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE) {
			temp = area;
			area = strcatEX("%s-%f", temp, obj->B * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi--;
		area = strcatEX("%f*2+%f*%d", obj->H * 0.001, obj->B * 0.001, multi);
		if (area == NULL)
			return NULL;
		if (CtrlCode & METHOD_PRECISELY) {
			temp = area;
			area = strcatEX("%s-%f*2", temp, obj->tH * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	}
	
	return area;
}

char *getArea_H(void *object, unsigned const CtrlCode) {
	SectionSteel_H *obj = object;
	char *area = NULL, *temp = NULL;
	double data[] = {obj->H, obj->B1, obj->tH, obj->tB1};
	int multi = 4;
	double val = 0.0;
		
	if (CtrlCode & METHOD_LOOKUP) {
		if (obj->B1 != obj->B2 || obj->tB1 != obj->tB2)
			return NULL;
		val = search_AorW(obj->Type, data, sizeof(data)/sizeof(double), 0);
		if (val == 0.0)
			return NULL;
		area = dtostr(val, DATA_PRECISION);
		if (area == NULL)
			return NULL;
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE) {
			temp = area;
			area = strcatEX("%s-%f", temp, obj->B1 * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi--;
			
		if (obj->B1 == obj->B2)
			area = strcatEX("%f*2+%f*%d", obj->H * 0.001, obj->B1 * 0.001, multi);
		else {
			multi -= 2;
			if (multi == 1)
				area = strcatEX("%f*2+%f+%f*2", obj->H * 0.001, obj->B1 * 0.001, obj->B2 * 0.001);
			else
				area = strcatEX("%f*2+%f*%d+%f*2", obj->H * 0.001, obj->B1 * 0.001, multi, obj->B2 * 0.001);
		}
		if (CtrlCode & METHOD_PRECISELY) {
			temp = area;
			area = strcatEX("%s-%f*2", temp, obj->tH * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	}
	
	return area;
}

char *getArea_HT(void *object, unsigned const CtrlCode) {
	return getArea_H_(object, CtrlCode);
}

char *getArea_HI(void *object, unsigned const CtrlCode) {
	SectionSteel_HI *obj = object;
	char *area = NULL, *temp = NULL;
	double data1[] = {obj->H1, obj->B1, obj->tH1, obj->tB1};
	double data2[] = {obj->H2, obj->B2, obj->tH2, obj->tB2};
	int multi = 4;
	double val1 = 0.0;
	double val2 = 0.0;
	int same = 0;
	
	if (obj->H1 == obj->H2 && 
		obj->B1 == obj->B2 && 
		obj->tH1 == obj->tH2 && 
		obj->tB1 == obj->tB2)
		same = 1;
		
	if (CtrlCode & METHOD_LOOKUP) {
		val1 = val2 = search_AorW(obj->Type, data1, sizeof(data1)/sizeof(double), 0);
		if (!same)
			val2 = search_AorW(obj->Type, data2, sizeof(data1)/sizeof(double), 0);
		if (val1 == 0.0 || val2 == 0.0)
			return NULL;
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			if (same)
				area = strcatEX("%f*2-%f-%f*8", val1, obj->B1 * 0.001, obj->tH1 * 0.001);
			else
				area = strcatEX("%f-%f-%f*4+%f-%f*4", val1, obj->B1 * 0.001, obj->tH1 * 0.001, val2, obj->tH2 * 0.001);
		else
			if (same)
				area = strcatEX("%f*2-%f*8", val1, obj->tH1 * 0.001);
			else
				area = strcatEX("%f-%f*4+%f-%f*4", val1, obj->tH1 * 0.001, val2, obj->tH2 * 0.001);
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi--;
		if (same)
			area = strcatEX("%f*4+%f*%d", obj->H1 * 0.001, obj->B1 * 0.001, multi + 4);
		else
			area = strcatEX("%f*2+%f*%d+%f*2+%f*4", obj->H1 * 0.001, obj->B1 * 0.001, multi, obj->H2 * 0.001, obj->B2 * 0.001);
		if (CtrlCode & METHOD_PRECISELY) {
			temp = area;
			if (same)
				area = strcatEX("%s-%f*8", temp, obj->tH1 * 0.001);
			else
				area = strcatEX("%s-%f*4-%f*4", temp, obj->tH1 * 0.001, obj->tH2 * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	}
	
	return area;
}

char *getArea_T(void *object, unsigned const CtrlCode) {
	SectionSteel_T *obj = object;
	char *area = NULL, *temp = NULL;
	double data[] = {obj->H, obj->B, obj->tH, obj->tB};
	int multi = 2;
	double val = 0.0;
		
	if (CtrlCode & METHOD_LOOKUP) {
		val = search_AorW(obj->Type, data, sizeof(data)/sizeof(double), 0);
		if (val == 0.0)
			return NULL;
		area = dtostr(val, DATA_PRECISION);
		if (area == NULL)
			return NULL;
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE) {
			temp = area;
			area = strcatEX("%s-%f", temp, obj->B * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi--;
		if (multi == 1)
			area = strcatEX("%f*2+%f", obj->H * 0.001, obj->B * 0.001);
		else
			area = strcatEX("%f*2+%f*%d", obj->H * 0.001, obj->B * 0.001, multi);
	}
	
	return area;
}

char *getArea_J(void *object, unsigned const CtrlCode) {
	SectionSteel_J *obj = object;
	char *area = NULL;
	int multi = 2;
		
	if (CtrlCode & METHOD_LOOKUP) 
		return NULL;
	else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi--;
		if (multi == 1)
			area = strcatEX("%f*2+%f", obj->H * 0.001, obj->B * 0.001);
		else
			area = strcatEX("%f*2+%f*%d", obj->H * 0.001, obj->B * 0.001, multi);
	}
	
	return area;
}

char *getArea_D(void *object, unsigned const CtrlCode) {
	SectionSteel_D *obj = object;
	char *area = NULL;
		
	if (CtrlCode & METHOD_LOOKUP) 
		return NULL;
	else 
		area = strcatEX("PI()*%f", obj->D * 0.001);
	
	return area;
}

char *getArea_I(void *object, unsigned const CtrlCode) {
	SectionSteel_I *obj = object;
	char *area = NULL, *temp = NULL;
	double data[] = {obj->H, obj->B, obj->tH, obj->tB};
	int multi = 4;
	double val = 0.0;
		
	if (CtrlCode & METHOD_LOOKUP) {
		val = search_AorW(obj->Type, data, sizeof(data)/sizeof(double), 0);
		if (val == 0.0)
			return NULL;
		area = dtostr(val, DATA_PRECISION);
		if (area == NULL)
			return NULL;
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE) {
			temp =area;
			area = strcatEX("%s-%f", temp, obj->B * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi--;
		area = strcatEX("%f*2+%f*%d", obj->H * 0.001, obj->B * 0.001, multi);
		if (area == NULL)
			return NULL;
		if (CtrlCode & METHOD_PRECISELY) {
			temp = area;
			area = strcatEX("%s-%f*2", temp, obj->tH * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	}
	
	return area;
}

char *getArea_Chan(void *object, unsigned const CtrlCode) {
	return getArea_I(object, CtrlCode);
}

char *getArea_Chan_MtM(void *object, unsigned const CtrlCode) {
	SectionSteel_Chan_MtM *obj = object;
	char *area = NULL;
	double data[] = {obj->H, obj->B, obj->tH, obj->tB};
	int multi = 4;
	double val = 0.0;
		
	if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
		multi -= 2;
	area = strcatEX("%f*2+%f*%d", obj->H * 0.001, obj->B * 0.001, multi);
//	if (area == NULL)
//		return NULL;
	
	return area;
}

char *getArea_Chan_BtB(void *object, unsigned const CtrlCode) {
	SectionSteel_Chan_BtB *obj = object;
	char *area = NULL, *temp = NULL;
	double data[] = {obj->H, obj->B, obj->tH, obj->tB};
	int multi = 8;
	double val = 0.0;
		
	if (CtrlCode & METHOD_LOOKUP) {
		val = search_AorW(obj->Type, data, sizeof(data)/sizeof(double), 0);
		if (val == 0.0)
			return NULL;
		area = strcatEX("%f*2-%f*2", val, obj->H * 0.001);
		if (area == NULL)
			return NULL;
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE) {
			temp = area;
			area = strcatEX("%s-%f*2", temp, obj->B * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi -= 2;
		area = strcatEX("%f*2+%f*%d", obj->H * 0.001, obj->B * 0.001, multi);
		if (area == NULL)
			return NULL;
		if (CtrlCode & METHOD_PRECISELY) {
			temp = area;
			area = strcatEX("%s-%f*4", temp, obj->tH * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	}
	
	return area;
}

char *getArea_L(void *object, unsigned const CtrlCode) {
	SectionSteel_L *obj = object;
	char *area = NULL, *temp = NULL;
	double data[] = {obj->B1, obj->B2, obj->t};
	int multi = 2;
	double val = 0.0;
	int same = 0;
	
	if (obj->B1 == obj->B2)
		same = 1;
		
	if (CtrlCode & METHOD_LOOKUP) {
		val = search_AorW(obj->Type, data, sizeof(data)/sizeof(double), 0);
		if (val == 0.0)
			return NULL;
		area = dtostr(val, DATA_PRECISION);
		if (area == NULL)
			return NULL;
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE) {
			temp = area;
			area = strcatEX("%s-%f", temp, obj->B2 * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi--;
		if (same)
			area = strcatEX("%f*%d", obj->B1 * 0.001, multi + 2);
		else
			if (multi == 1)
				area = strcatEX("%f*2+%f", obj->B1 * 0.001, obj->B2 * 0.001);
			else
				area = strcatEX("%f*2+%f*%d", obj->B1 * 0.001, obj->B2 * 0.001, multi);
//		if (area == NULL)
//			return NULL;
	}
	
	return area;
}

char *getArea_2L(void *object, unsigned const CtrlCode) {
	SectionSteel_L *obj = object;
	char *area = NULL, *temp = NULL;
	double data[] = {obj->B1, obj->B2, obj->t};
	int multi = 4;
	double val = 0.0;
	int same = 0;
	
	if (obj->B1 == obj->B2)
		same = 1;
		
	if (CtrlCode & METHOD_LOOKUP) {
		val = search_AorW(obj->Type, data, sizeof(data)/sizeof(double), 0);
		if (val == 0.0)
			return NULL;
		area = strcatEX("%f*2-%f*2", val, obj->B1 * 0.001);
		if (area == NULL)
			return NULL;
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE) {
			temp = area;
			area = strcatEX("%s-%f*2", temp, obj->B2 * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi -= 2;
		if (same)
			area = strcatEX("%f*%d", obj->B1 * 0.001, multi + 2);
		else
			area = strcatEX("%f*2+%f*%d", obj->B1 * 0.001, obj->B2 * 0.001, multi);
//		if (area == NULL)
//			return NULL;
	}
	
	return area;
}

char *getArea_C(void *object, unsigned const CtrlCode) {
	SectionSteel_C *obj = object;
	char *area = NULL, *temp = NULL;
//	double data[] = {obj->H, obj->B, obj->C, obj->t};
	int multi = 4;
//	double val = 0.0;
		
	if (CtrlCode & METHOD_LOOKUP) {
//		val = search_AorW(obj->Type, data, sizeof(data)/sizeof(double), 0);
//		if (val == 0.0)
//			return NULL;
//		area = dtostr(val, DATA_PRECISION);
//		if (area == NULL)
//			return NULL;
//		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE) {
//			temp = area;
//			area = strcatEX("%s-%f", temp, obj->B * 0.001);
//			if (area == NULL) {
//				free(temp);
//				return NULL;
//			}
//		}
		return NULL;
	} else {
		if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
			multi--;
		area = strcatEX("%f*2+%f*%d+%f*4", obj->H * 0.001, obj->B * 0.001, multi, obj->C * 0.001);
		if (area == NULL)
			return NULL;
		if (CtrlCode & METHOD_PRECISELY) {
			temp = area;
			area = strcatEX("%s-%f*6", temp, obj->t * 0.001);
			free(temp);
			if (area == NULL) 
				return NULL;
		}
	}
	
	return area;
}

char *getArea_2C(void *object, unsigned const CtrlCode) {
	SectionSteel_2C *obj = object;
	char *area = NULL;
//	double data[] = {obj->H, obj->B, obj->C, obj->t};
	int multi = 4;
//	double val = 0.0;
		
	if (CtrlCode & METHOD_LOOKUP)
		return NULL;
	if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
		multi -= 2;
	area = strcatEX("%f*2+%f*%d", obj->H * 0.001, obj->B * 0.001, multi);
//	if (area == NULL)
//		return NULL;
	
	return area;
}

char *getArea_Z(void *object, unsigned const CtrlCode) {
	return getArea_C(object, CtrlCode);
}

char *getArea_PL_(void *object, unsigned const CtrlCode) {
	SectionSteel_PL_ *obj = object;
	char *area = NULL, *area_next = NULL, *temp = NULL;
	int multi = 2;
	
	if (CtrlCode & METHOD_LOOKUP)
		return NULL;
	
	if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
		multi--;
		
	if (multi == 1)
		area = dtostr(obj->B * 0.001, DATA_PRECISION);
	else
		area = strcatEX("%f*2", obj->B * 0.001);
	if (area == NULL)
		return NULL;
	
	if (obj->L != 0) {
		temp = area;
		area = strcatEX("%s*%f", temp, obj->L * 0.001);
		free(temp);
		if (area == NULL) 
			return NULL;
	}
	
	if (obj->pNext != NULL) {
		area_next = getArea_PL_(obj->pNext, CtrlCode);
		if (area_next == NULL) {
			free(area);
			return NULL;
		}
		temp = area;
		area = strcatEX("%s-%s", temp, area_next);
		free(temp);
		if (area == NULL) {
			free(area_next);
			return NULL;
		}
	}
	
	return area;
}

char *getArea_PLT_(void *object, unsigned const CtrlCode) {
	SectionSteel_PLT_ *obj = object;
	char *area = NULL, *area_next = NULL, *temp = NULL;
	int multi = 2;
	
	area = getArea_PLT(object, CtrlCode);
	if (area == NULL)
		return NULL;
	
	if (obj->pNext != NULL) {
		area_next = getArea_PLT_(obj->pNext, CtrlCode);
		if (area_next == NULL) {
			free(area);
			return NULL;
		}
		temp = area;
		area = strcatEX("%s-%s", temp, area_next);
		free(temp);
		if (area == NULL) {
			free(area_next);
			return NULL;
		}
	}
	
	return area;
}

char *getArea_PLD_(void *object, unsigned const CtrlCode) {
	SectionSteel_PLD_ *obj = object;
	char *area = NULL, *area_next = NULL, *temp = NULL;
	
	area = getArea_PLD(object, CtrlCode);
	if (area == NULL)
		return NULL;
	
	if (obj->pNext != NULL) {
		area_next = getArea_PLD_(obj->pNext, CtrlCode);
		if (area_next == NULL) {
			free(area);
			return NULL;
		}
		temp = area;
		area = strcatEX("%s-%s", temp, area_next);
		free(temp);
		if (area == NULL) {
			free(area_next);
			return NULL;
		}
	}
	
	return area;
}

char *getArea_PL(void *object, unsigned const CtrlCode) {
	SectionSteel_PL *obj = object;
	SectionSteel_PL_ *subPL = obj->pPL;
	SectionSteel_PLT_ *subPLT = obj->pPLT;
	SectionSteel_PLD_ *subPLD = obj->pPLD;
	char *area = NULL, *temp = NULL;
	char *area_subPL = NULL, *area_subPLT = NULL, *area_subPLD = NULL;
	int failure = 0;
	
	area_subPL = getArea_PL_(subPL, CtrlCode);
	if (area_subPL == NULL)
		failure = 1;
	if (subPLT != NULL) {
		area_subPLT = getArea_PLT_(subPLT, CtrlCode);
		if (area_subPLT == NULL)
			failure = 1;
	}
	if (subPLD != NULL) {
		area_subPLD = getArea_PLD_(subPLD, CtrlCode);
		if (area_subPLD == NULL)
			failure = 1;
	}
	
error:
	if (failure) {
		free(area_subPL);
		free(area_subPLT);
		free(area_subPLD);
		return NULL;
	}
	
	area = strcatEX("%s", area_subPL);
	if (area == NULL) {
		failure = 1;
		goto error;
	}
	if (subPLT != NULL) {
		temp = area;
		area = strcatEX("%s-%s", temp, area_subPLT);
		free(temp);
		if (area == NULL) {
			failure = 1;
			goto error;
		}
	}
	if (subPLD != NULL) {
		temp = area;
		area = strcatEX("%s-%s", temp, area_subPLD);
		free(temp);
		if (area == NULL) {
			failure = 1;
			goto error;
		}
	}
	
	free(area_subPL);
	free(area_subPLT);
	free(area_subPLD);
	return area;
}

char *getArea_PLT(void *object, unsigned const CtrlCode) {
	SectionSteel_PLT *obj = object;
	char *area = NULL, *temp = NULL;
	int multi = 2;
	
	if (CtrlCode & METHOD_LOOKUP)
		return NULL;
	
	if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
		multi--;
		
	if (multi == 2)
		area = dtostr(obj->B * 0.001, DATA_PRECISION);
	else
		area = strcatEX("%f*0.5", obj->B * 0.001);
	if (area == NULL)
		return NULL;
	
	if (obj->L != 0) {
		temp = area;
		area = strcatEX("%s*%f", temp, obj->L * 0.001);
		free(temp);
		if (area == NULL) 
			return NULL;
	}
	
	return area;
}

char *getArea_PLD(void *object, unsigned const CtrlCode) {
	SectionSteel_PLD *obj = object;
	char *area = NULL, *temp = NULL;
	
	if (CtrlCode & METHOD_LOOKUP)
		return NULL;
	
	if (CtrlCode & TYPE_EXCLUDE_TOPSURFACE)
		area = strcatEX("PI()*%f^2", obj->D * 0.001 * 0.5);
	else
		area = strcatEX("PI()*%f^2*2", obj->D * 0.001 * 0.5);
	if (area == NULL)
		return NULL;
	
	return area;
}


char *getWeight_H_(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_H(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_HT(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_HI(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_T(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_J(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_D(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_I(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_Chan(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_Chan_MtM(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_Chan_BtB(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_L(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_2L(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_C(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_2C(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_Z(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_PL_(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_PLT_(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_PLD_(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_PL(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_PLT(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getWeight_PLD(void *object, unsigned const CtrlCode) {
	return NULL;
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
	for (i = 0, lastmatchedindex = -1, nums = 0; i <= len_s - len_d; i++) {
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
		item = (void *)calloc(i - lastmatchedindex + 1, sizeof(char));
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
	if (nums <= 0)
		return 0;
	else {
		for (i = 0, value = 0; i < nums; i++) 
			value += atof(strarr[i]);
		value /= nums;
		strsplit_free(&strarr, nums);
	}
	return value;
}

char *dtostr(double const d, unsigned const pre) {
	double num = d;
	int i = 0;
	int sign = 1;//正负标记 
	int pow = 1;
	int len_i = 0, len_f = 0;
	int cor = 0;//小数部分前部需补位数 
	long num_i = 0, num_f = 0;
	char *int_part = NULL;//整数部分 
	char *float_part = NULL; //小数部分 
	char *str = NULL;

	//判断正负
	if (d < 0) 
		sign = -1, num = -num;
	while (++i <= pre)
		pow *= 10; 
	num = (num * pow + 0.5) * 1.0 / pow;
	//求出整数部分 
	num_i = num;
	//求出小数部分
	num_f = (num - num_i) * pow;
	
	//转换整数部分和小数部分 
	int_part = ltostr(num_i);
	if (int_part == NULL)
		return NULL;
	if (num_f > 0) {
		float_part = ltostr(num_f);
		if (float_part == NULL) {
			free(int_part), int_part = NULL;
			return NULL;
		}
	}
	
/*
	判断小数部分是否需要修正
	如果小数部分是例如001这样传入ltostr函数，则返回字符串将变成1。
	这种情况需要在前面添加字符0修正 
	正负符号位、小数点修正也计入cor 
*/ 	
	len_i = strlen(int_part);
	if (num_f > 0)
		len_f = strlen(float_part);
	cor = pre - len_f;
	//消除小数部分末尾的0，并得到操作之后的长度 
	for (i = len_f; i > 0;) {
		if (float_part[--i] != '0') 
			break;
		float_part[i] = '\0';
		len_f = i; 
	}

	if (num_f == 0)
		cor = 0; 
	else
		cor++;
	if (sign == -1) 
		cor++;
	//申请空间大小为：整数部分长度 + 修正部分长度（含符号位、小数点） + 小数消除末尾0后的长度 + 1 
	str = (char *)calloc(len_i + cor + len_f + 1, sizeof(char));
	if (str == NULL) {
		free(int_part), free(float_part), int_part = NULL, float_part = NULL;
		return NULL;
	}
//	str[0] = '\0';
	if (sign == -1 && (num_i != 0 || num_f != 0))
		str[0] = '-', str[1] = '\0', len_i++, cor--;
	strcat(str, int_part);
	if (num_f > 0) {
		str[len_i++] = '.';
		cor--;
		for (i = 0; i < cor; i++)
			str[len_i++] = '0';
		strcpy(&str[len_i], float_part);
	}
	free(int_part), free(float_part), int_part = NULL, float_part = NULL;
	return str;
}

char *ltostr(long const l) {
	int digits = 0;//位数 
	int sign = 1;//正负标记 
	long num, i;
	char *str = NULL;
	num = l;
	if (num < 0) {
		sign = -1;
		num = ~num + 1;
	}
	i = num, digits = 0;
/*
	统计有多少位数字，最后再加符号位 
*/
	do {
		i /= 10;
		digits++;
	} while(i != 0);
	if (sign == -1) 
		digits++;
/*
	申请存储空间 
*/
	str = (char *)calloc(digits + 1, sizeof(char));
	if (str == NULL) 
		return NULL;
/*
	辗转相除，每次的余数从后向前存入字符数组，最后有负号添负号 
*/
	for (str[digits--] = '\0'; digits >= 0; digits--) {
		str[digits] = num % 10 + '0';
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return str;
}

char *strcatEX(char const *format, ...) {
	int failure = 0; 
	va_list ap;
	char const *p = format;
	
	int aCapacity = 20;
	char *strarr[aCapacity];
	int aIndex = 0;
	
	char *str = NULL;
	char *temp = NULL;
	int sLen = 0;
	
	int i = 0, last = 0;
	
	for (i = 0; i < aCapacity; i++)
		strarr[i] = NULL;
	va_start(ap, format);
	
	for (i = 0; p[i] != '\0'; i++) {
		while (p[i] != '\0' && p[i++] != '%') 
			;
		switch (p[i]) {
			case 'c': case 'd': case 'f': case 's':
				if (last == i - 1)
					last = i + 1;
				//转义符%c、%d、%f、%s之前还有未处理的字符串 
				if ((i - last) > 1) {
					sLen = i - last - 1;
					str = strncpyEX(p + last, sLen);
					if (str == NULL) {
						failure = 1;
						break;
					}
					strarr[aIndex++] = str;
					str = NULL;
					last = i + 1;
					
					//返回到%c、%d、%f、%s进行处理 
					i -= 2;
				} else {
					switch (p[i]) {
						case 'c': 
							str = (char *)malloc(2);
							if (str == NULL) {
								failure = 1;
								break;
							}
							str[0] = va_arg(ap, int);
							str[1] = '\0';
							break;
						case 'd': 
							str = ltostr(va_arg(ap, long));
							break;
						case 'f': 
							str = dtostr(va_arg(ap, double), DATA_PRECISION);
							break;
						case 's':
							temp = va_arg(ap, char *);
							str = (char *)calloc(strlen(temp) + 1, sizeof(char));
							if (str == NULL) {
								failure = 1;
								temp = NULL;
								break;
							}
							strcpy(str, temp);
							temp = NULL;
							break;
					}					
					strarr[aIndex++] = str;
					str = NULL;
				}
				break;
			case '\0':
				sLen = i - last;
				str = strncpyEX(p + last, sLen);
				if (str == NULL) {
					failure = 1;
					break;
				}
				strarr[aIndex++] = str;
				str = NULL;
				i--;
				break;
			default:
				break;
		}
		if (failure)
			break;
		
		//如果数组存满，将所有元素组成新字符串存入第一项，释放其他项 
		if (aIndex == aCapacity) {
			str = strarrcat(strarr, aCapacity);
			if (str == NULL) {
				failure = 1;
				break;
			}
			strarr[0] = str;
			str = NULL; 
			aIndex = 1;
		}
	}
		
	if (failure) {
		for (i = 0; i < aCapacity; i++)
			free(strarr[i]), strarr[i] = NULL;
		return NULL;
	}
	
	str = strarrcat(strarr, aCapacity);
	return str;
}

char *strncpyEX(char const *source, int const len) {
	char *str = NULL;
	
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return NULL;
	*str = '\0';
	return strncat(str, source, len);
}

char *strarrcat(char *strarr[], int const capacity) {
	int i, len;
	char *NewStr = NULL;
	
	for (i = len = 0; i < capacity; i++) 
		if (strarr[i] != NULL)
			len += strlen(strarr[i]);
		
	NewStr = (char *)malloc(len + 1);
	if (NewStr == NULL)
		return NULL;
	*NewStr = '\0';
	
	for (i = 0; i < capacity; i++) {
		if (strarr[i] == NULL) 
			continue;
		NewStr = strcat(NewStr, strarr[i]);
		free(strarr[i]);
		strarr[i] = NULL;
	}
	
	return NewStr;
}

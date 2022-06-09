#include "GBData.h"
#include "SectionSteel.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
	obj->Type = "H";
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
	obj->Type = "Chan";
	obj->Name = NULL;
	obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_Chan_MtM *new_Chan_MtM (void) {
	SectionSteel_Chan_MtM *obj;
	obj = (SectionSteel_Chan_MtM *)malloc(sizeof(SectionSteel_Chan_MtM));
	if (obj == NULL)
		return NULL;
	obj->Type = "Chan";
	obj->Name = NULL;
	obj->H = obj->B = obj->tH = obj->tB = 0;
	return obj;
}

SectionSteel_Chan_BtB *new_Chan_BtB (void) {
	SectionSteel_Chan_BtB *obj;
	obj = (SectionSteel_Chan_BtB *)malloc(sizeof(SectionSteel_Chan_BtB));
	if (obj == NULL)
		return NULL;
	obj->Type = "Chan";
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
	obj->Type = "L";
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
	obj->Type = "C";
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

void free_H_(void **object) {
	free(*object);
	*object = NULL;
}

void free_H(void **object) {
	free(*object);
	*object = NULL;
}

void free_HT(void **object) {
	free(*object);
	*object = NULL;
}

void free_HI(void **object) {
	free(*object);
	*object = NULL;
}

void free_T(void **object) {
	free(*object);
	*object = NULL;
}

void free_J(void **object) {
	free(*object);
	*object = NULL;
}

void free_D(void **object) {
	free(*object);
	*object = NULL;
}

void free_I(void **object) {
	SectionSteel_I *obj;
	obj = *object;
	free(obj->Name);
	free(*object);
	*object = NULL;
}

void free_Chan(void **object) {
	SectionSteel_Chan *obj;
	obj = *object;
	free(obj->Name);
	free(*object);
	*object = NULL;
}

void free_Chan_MtM(void **object) {
	SectionSteel_Chan_MtM *obj;
	obj = *object;
	free(obj->Name);
	free(*object);
	*object = NULL;
}

void free_Chan_BtB(void **object) {
	SectionSteel_Chan_BtB *obj;
	obj = *object;
	free(obj->Name);
	free(*object);
	*object = NULL;
}

void free_L(void **object) {
	SectionSteel_L *obj;
	obj = *object;
	free(obj->Name);
	free(*object);
	*object = NULL;
}

void free_2L(void **object) {
	SectionSteel_2L *obj;
	obj = *object;
	free(obj->Name);
	free(*object);
	*object = NULL;
}

void free_C(void **object) {
	free(*object);
	*object = NULL;
}

void free_2C(void **object) {
	free(*object);
	*object = NULL;
}

void free_Z(void **object) {
	free(*object);
	*object = NULL;
}

void free_PL_(void **object) {
	SectionSteel_PL_ *obj = *object;
	if (obj->pNext != NULL)
		free_PL_((void **)&obj->pNext);
	free(*object);
	*object = NULL;
}

void free_PLT_(void **object) {
	SectionSteel_PLT_ *obj = *object;
	if (obj->pNext != NULL)
		free_PLT_((void **)&obj->pNext);
	free(*object);
	*object = NULL;
}

void free_PLD_(void **object) {
	SectionSteel_PLD_ *obj = *object;
	if (obj->pNext != NULL)
		free_PLD_((void **)&obj->pNext);
	free(*object);
	*object = NULL;
}

void free_PL(void **object) {
	SectionSteel_PL *obj = *object;
	free_PL_((void **)&obj->pPL);
	free_PLT_((void **)&obj->pPLT);
	free_PLD_((void **)&obj->pPLD);
	free(*object);
	*object = NULL;
}

void free_PLT(void **object) {
	free(*object);
	*object = NULL;
}

void free_PLD(void **object) {
	free(*object);
	*object = NULL;
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
	printf("Debug: H = %.1f,  B = %.1f,  tH = %.1f,  tB= %.1f\n", 
					obj->H, 	obj->B, 	obj->tH, 	obj->tB);
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
	printf("Debug: H = %.1f,  B1 = %.1f,  B2 = %.1f,  tH = %.1f,  tB1= %.1f,  tB2= %.1f\n", 
					obj->H, 	obj->B1, 	obj->B2, 	obj->tH, 	obj->tB1,	obj->tB2);
	return 1;
}

int expand_H(void *object) {
	SectionSteel_H_ *_obj = NULL;
	SectionSteel_H *obj = object;
	int failure = 0;
	
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
	SectionSteel_H_ *H_1 = NULL, *H_2 = NULL;
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
			H_1 = new_H_();
			if (H_1 == NULL) {
				failure = 1;
				break;
			}
			if (setData_H_(H_1, strarr[0]) == 0) {
				failure = 1;
				break;
			}
			obj->H1 = obj->H2 = H_1->H;
			obj->B1 = obj->B2 = H_1->B;
			obj->tH1 = obj->tH2 = H_1->tH;
			obj->tB1 = obj->tB2 = H_1->tB;
			free_H_((void **)&H_1);
			break;
		case 2:
			H_1 = new_H_(), H_2 = new_H_();
			if (H_1 == NULL || H_2 == NULL) {
				failure = 1;
				break;
			}
			if (setData_H_(H_1, strarr[0]) == 0 || setData_H_(H_2, strarr[1]) == 0) {
				failure = 1;
				break;
			}
			obj->H1 = H_1->H;
			obj->B1 = H_1->B;
			obj->tH1 = H_1->tH;
			obj->tB1 = H_1->tB;
			obj->H2 = H_2->H;
			obj->B2 = H_2->B;
			obj->tH2 = H_2->tH;
			obj->tB2 = H_2->tB;
			break;
		default:
			failure = 1;
			break;
	}
	
	free_H_((void **)&H_1);
	free_H_((void **)&H_2);
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
	printf(	"Debug: H1 = %.1f,  B1 = %.1f,  tH1 = %.1f,  tB1= %.1f\n"
			"       H2 = %.1f,  B2 = %.1f,  tH2 = %.1f,  tB2= %.1f\n", 
					obj->H1, 	obj->B1, 	obj->tH1,	obj->tB1,
					obj->H2, 	obj->B2, 	obj->tH2, 	obj->tB2);
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
	printf("Debug: H = %.1f,  B = %.1f,  tH = %.1f,  tB= %.1f\n", 
					obj->H,		obj->B,		obj->tH, 	obj->tB);
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
	printf("Debug: D = %.1f,  t= %.1f\n", 
					obj->D,		obj->t);
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
		default:
			failure = 1;
			break;
	}
	
	strsplit_free(&strarr, nums);
	if (failure)
		return 0;
	printf("Debug: H = %.1f,  B = %.1f,  tH = %.1f,  tB= %.1f\n", 
					obj->H,		obj->B,		obj->tH, 	obj->tB);
	return 1;
}

int expand_I(void *object) {
	
}

int setData_Chan(void *object, char const *FormatedText) {

}

int expand_Chan(void *object) {
	
}

int setData_Chan_MtM(void *object, char const *FormatedText) {

}

int expand_Chan_MtM(void *object) {
	
}

int setData_Chan_BtB(void *object, char const *FormatedText) {

}

int expand_Chan_BtB(void *object) {
	
}

int setData_L(void *object, char const *FormatedText) {

}

int expand_L(void *object) {
	
}

int setData_2L(void *object, char const *FormatedText) {

}

int expand_2L(void *object) {
	
}

int setData_C(void *object, char const *FormatedText) {

}

int expand_C(void *object) {
	
}

int setData_2C(void *object, char const *FormatedText) {

}

int expand_2C(void *object) {
	
}

int setData_Z(void *object, char const *FormatedText) {

}

int expand_Z(void *object) {
	
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
	return NULL;
}

char *getArea_H(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_HT(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_HI(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_T(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_J(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_D(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_I(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_Chan(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_Chan_MtM(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_Chan_BtB(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_L(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_2L(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_C(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_2C(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_Z(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_PL_(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_PLT_(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_PLD_(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_PL(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_PLT(void *object, unsigned const CtrlCode) {
	return NULL;
}

char *getArea_PLD(void *object, unsigned const CtrlCode) {
	return NULL;
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
	正负符号位修正也计入cor 
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
	if (sign == -1) 
		cor++;
	//申请空间大小为：整数部分长度 + 修正部分长度（含符号位） + 小数消除末尾0后的长度 + 1 
	str = (char *)calloc(len_i + cor + len_f + 1, sizeof(char));
	if (str == NULL) {
		free(int_part), free(float_part), int_part = NULL, float_part = NULL;
		return NULL;
	}
	str[0] = '\0';
	if (sign == -1 && (num_i != 0 || num_f != 0))
		str[0] = '-', str[1] = '\0', len_i++, cor--;
	str = strcat(str, int_part);
	if (num_f > 0) {
		str[len_i] = '.';
		for (i = 0; i < cor; i++)
			str[++len_i] = '0';
		strcpy(&str[++len_i], float_part);
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

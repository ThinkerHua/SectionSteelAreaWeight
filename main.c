#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GBData.h"
#include "SectionSteel.h"
#include "calculation.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[100], delim[10] = {'\0'};
	char from[5] = {'\0'}, to[5] = {'\0'};
	char *newstr = NULL, **strarr = NULL;
	char *resault = NULL;
	int i, nums;
	double d;
	printf("Now testting function \"strsplit\"\n");
	while (scanf("%s %s", str, delim) != EOF) {
		nums = strsplit(str, delim, &strarr);
		if (nums <= 0)
			continue;
		for (i = 0; i < nums; i++) {
			printf("%s\n", strarr[i]);
		}
		strsplit_free(&strarr, nums), strarr = NULL;
		i = 0;
		while(str[i] != '\0') 
			str[i] = '\0', i++;
	}
	printf("Now testting function \"replace\"\n");
	while (scanf("%s %s %s", str, from, to) != EOF) {
		newstr = (char *)malloc(strlen(str) + 1);
		if (newstr == NULL) 
			continue;
		strcpy(newstr, str);
		if (replace(&newstr, from, to) > 0) 
			printf("%s\n", newstr), free(newstr), newstr = NULL;
	}
	printf("Now testting function \"dtostr\"\n");
	while (scanf("%lf", &d) != EOF) {
		newstr = dtostr(d, 3);
		if (newstr == NULL)
			continue;
		printf("%s\n", newstr), free(newstr), newstr = NULL;
	}
	printf("Now testting struct initialization\n");
	while (scanf("%s", str) != EOF) {
//		structinitial(str);
		resault = SectionSteelAW(str, 1);
		free(resault);
	}
	return 0;
}

int structinitial(char const *RawText) {
	char *FormatedText;
	char *SecSteType;
	void *obj;
	if (formatting(RawText, &FormatedText) == 0)
		return 0;
	SecSteType = getSecSteType(FormatedText);
	if (SecSteType == NULL) 
		return 0;
	obj = new_H();
	if (obj == NULL) 
		return 0;
	if (setData_H(obj, FormatedText) == 0) {
		free_H(obj);
		return 0;
	}
	
	free_H(obj);
	return 1;
}

char *SectionSteelAW(char const *RawText, unsigned const CtrlCode) {
	char *FormatedText = NULL;
	char *SecSteType = NULL;
	char *Resault = NULL;
	void *obj = NULL;
	if (formatting(RawText, &FormatedText) == 0)
		return NULL;
	SecSteType = getSecSteType(FormatedText);
	if (SecSteType == NULL) 
		return NULL;
	obj = NewObj(SecSteType);
	if (obj == NULL) 
		return NULL;
	if (SetData(obj, SecSteType, FormatedText) == 0) {
		FreeObj(obj, SecSteType);
		return NULL;
	}
	Resault = getResault(obj, SecSteType, CtrlCode);
	FreeObj(obj, SecSteType);
	return Resault;
}

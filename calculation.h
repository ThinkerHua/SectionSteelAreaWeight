#ifndef _CALCULATION_H_
#define _CALCULATION_H_

int formatting(char const *RawText, char **const p_FormatedText);
/*
	返回值	-1	无法为格式化字符串分配空间 
			0	格式化失败。
			1	格式化成功；
*/
struct replaceinfo {
	char *from;
	char *to;
};
int replace(char **const p_str, char const *from, char const *to);
/*
	将字符串str中包含的字符串from替换成字符串to
	只能处理malloc出来的字符串str，且应当传入字符串str的地址做为参数
	返回值	-1	无法为处理后的字符串分配空间
			0	传入的字符串为空字符串（空指针或0长度）
			1	替换成功 
*/
char *getSecSteType(char const *FormatedText);
void QSortStrArr(char *strarr[], int const left, int const right, int (*compare)(char const *str1, char const *str2));
void swap(char **op1, char **op2);
int strcmp_X(char const *str1, char const *str2);
/*
	返回值	1	str1>str2;
			0	str1=str2;
			-1	str1<str2.
	说明：先比较两个字符串的长度，长度较大的字符串大于长度较小的字符串。
		长度相等时，按标准库函数strcmp的规则进行比较。 
*/
void *NewObj(char const *SecSteType);
void FreeObj(void **p_obj, char const *SecSteType);
int SetData(void *obj, char const *SecSteType, char const *FormatedText);
/*
	返回值	1	obj属性设置成功；
			0	obj属性设置失败。
*/
char *getResault(void *obj, char const *SecSteType, unsigned const CtrlCode);
/*
	参数CtrlCode，从最低位到最高位位序：
		0	=1则计算面积，与位序2互斥（互斥：不允许同时为1，否则为未定义行为，下同） 
		1	位序0的附属选项，当位序0为1时才起作用
			=1则面积扣减顶面
			=0则面积不扣减顶面
		2	=1则计算重量，与位序0互斥
		3	=1则进行粗略计算，与位序4、5互斥
		4	=1则进行精细计算，与位序3、5互斥
		5	=1则进行查表计算，与位序3、4互斥 
*/

#endif

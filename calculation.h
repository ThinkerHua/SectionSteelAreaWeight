#ifndef _CALCULATION_H_
#define _CALCULATION_H_

int formatting(char const *RawText, char **const p_FormatedText);
/*
	����ֵ	-1	�޷�Ϊ��ʽ���ַ�������ռ� 
			0	��ʽ��ʧ�ܡ�
			1	��ʽ���ɹ���
*/
struct replaceinfo {
	char *from;
	char *to;
};
char *getSecSteType(char const *FormatedText);
/*
	����ֵָ��ָ��const�ַ������飬����ʹ��ʱ��Ӧfree��ֻ�踳ֵNULL
*/
void QSortStrArr(char *strarr[], int const left, int const right, int (*compare)(char const *str1, char const *str2));
void swap(char **op1, char **op2);
int strcmp_X(char const *str1, char const *str2);
/*
	����ֵ	1	str1>str2;
			0	str1=str2;
			-1	str1<str2.
	˵�����ȱȽ������ַ����ĳ��ȣ����Ƚϴ���ַ������ڳ��Ƚ�С���ַ�����
		�������ʱ������׼�⺯��strcmp�Ĺ�����бȽϡ� 
*/
void *NewObj(char const *SecSteType);
void FreeObj(void **p_obj, char const *SecSteType);
int SetData(void *obj, char const *SecSteType, char const *FormatedText);
/*
	����ֵ	1	obj�������óɹ���
			0	obj��������ʧ�ܡ�
*/
char *getFormula(void *obj, char const *SecSteType, unsigned const CtrlCode);
/*
	����CtrlCode�������λ�����λλ��
		0	=1������������λ��2���⣨���⣺������ͬʱΪ1������Ϊδ������Ϊ����ͬ�� 
		1	λ��0�ĸ���ѡ���λ��0Ϊ1ʱ��������
			=1������ۼ�����
			=0��������ۼ�����
		2	=1�������������λ��0����
		3	=1����д��Լ��㣬��λ��4��5����
		4	=1����о�ϸ���㣬��λ��3��5����
		5	=1����в����㣬��λ��3��4���� 
	����ֵ����Ҫʹ��ʱӦfree�� 
*/
char *getStiffener(void *obj, char const *SecSteType, unsigned const CtrlCode);
/*
	����CtrlCode��
		1	��βȡ��
		0	����С��
	����ֵ����Ҫʹ��ʱӦfree�� 
*/

#endif

#ifndef _DYNAMICLY_ALLOCATED_STRING_H_ 
#define _DYNAMICLY_ALLOCATED_STRING_H_

#define DATA_PRECISION 4
#define STRARR_CAPACITY 20

int strsplit(char const *str, char const *delim, char ***const p_strarr);
/*
	���ַ���str���ַ���delim���зָ�ָ��Ķ���ַ������������ַ�������strarr��
	Ӧ�����ַ�������strarr�ĵ�ַ��Ϊ�������룬��strarrָ��Ŀռ��Ƕ�̬����� 
	����ֵ	-1	������ַ���str��delimΪ���ַ��������޷�Ϊstrarr����ռ�
			0	�ָ�����󣬲����ڿ����ַ�������ʱ����p_strarr���κβ��� 
			>0	�ָ�������ַ�������strarr�е���Ŀ��
	��strarr����Ҫʹ��ʱ������ʹ�����׵�strsplit_free�����ͷŴ洢�ռ� 
*/
void strsplit_free(char ***const p_strarr, int const nums);
/*
	��strsplit��������ʹ�ã���strsplit�����������ַ�������strarr�ͷŵ�
	Ӧ�����ַ�������strarr�ĵ�ַ��Ϊ��������
	���뱣֤nums��strsplit�����ķ���ֵһ�£�������δ֪ 
*/

double average_delim_weighted(char const *str, char const *delim);
/*
	����str����delim�ָ����ֵ��ƽ��ֵ 
*/

char *dtostr(double const d, unsigned const pre);
/*
	��֧��ʮ���Ʒ�ָ����ʽ 
	preΪС��λ����С��ĩβ��0����ʾ��С��ȫΪ0��С����Ҳ����ʾ��
	ʧ�ܷ���NULL 
	�õ��Ľ���Ƕ�̬����ģ�����Ҫʹ��ʱӦfree�� 
*/
char *ltostr(long const l);
/*
	��֧��ʮ���Ʒ�ָ����ʽ 
	ʧ�ܷ���NULL 
	�õ��Ľ���Ƕ�̬����ģ�����Ҫʹ��ʱӦfree�� 
*/

char *strcatEX(char const *format, ...);
/*
	���ݸ�ʽ�ַ���format�����ر䳤��������������ӳɵ�һ�����ַ�����ʧ�ܷ���NULL 
	֧�ֵ�ת�������Ӧ�Ĳ��������У�
		%c	char 
		%d	int
		%f	double
		%s	char*
	��֧�ֱ�׼ת�����'\n'��'\t'�ȣ� 
	�õ��Ľ���Ƕ�̬����ģ�����Ҫʹ��ʱӦfree�� 
*/
char *strncpyEX(char const *source, int const len);
/*
	�����ַ���source��ǰlen���ַ�����ʵ�������أ�ĩβ���'\0' 
	ʧ�ܷ����򷵻�NULL 
	�õ��Ľ���Ƕ�̬����ģ�����Ҫʹ��ʱӦfree�� 
*/
char *strarrcat(char *strarr[], int const capacity);
/*
	���ַ�������strarr������Ԫ����ϳ�һ���µ��ַ������������һ��Ԫ�أ�
	ͬʱ�ͷ�ԭ�еĸ�Ԫ�أ�ԭ�еĸ�Ԫ��ָ��Ŀռ�Ӧ��Ϊ��̬����ģ����ɱ�free�� 
	Ӧ��ͬʱ���������������capacity
	ʧ�ܷ���NULL�����ͷ�strarr��Ԫ��ָ����ַ�����
	�õ��Ľ���Ƕ�̬����ģ�����Ҫʹ��ʱӦfree�� 
*/
int replace(char **const p_str, char const *from, char const *to);
/*
	���ַ���str�а������ַ���from�滻���ַ���to
	�ַ���strӦ���Ƕ�̬����ģ���Ӧ�������ַ���str�ĵ�ַ��Ϊ����
	����ֵ	-1	�޷�Ϊ�������ַ�������ռ�
			0	������ַ���Ϊ���ַ�������ָ���0���ȣ�
			1	�滻�ɹ� 
	str����Ҫʹ��ʱӦfree�� 
*/
int replace_at_original_location(char *const str, char const *from, char const *to);
/*
	Ч������replace��������ֻ���ַ���ԭʼ��ַ�Ͻ��в�������������ʵ��
	��ˣ�from�ĳ��Ȳ��ö���to�ĳ���
	��replace������ͬ���ǣ�������ֻ�贫��str��������str�ĵ�ַ
	����ֵ	0	������ַ���Ϊ���ַ�������from�ĳ��ȶ���to�ĳ���
			1	�滻�ɹ� 
*/

#endif

#include "dallocstr.h"
#include <string.h>
#include <stdlib.h> 
#include <stdarg.h>

int strsplit(char const *str, char const *delim, char  ***const p_strarr) {
	int len_s, len_d;
	int i, lastmatchedindex, index;
	int nums, j;
	char *item = NULL;
/*
	����������ַ���,���򷵻�-1
*/
	if (str == NULL || delim == NULL)
		return -1;
	len_s = strlen(str), len_d = strlen(delim);
	if (len_s == 0 || len_d == 0)
		return -1;
/*
	numsΪ�ָ���ɺ��ַ���������Ŀ��
	ѭ����ͳÿ��ѭ��ͳ�Ƴ��ָ������Ӧ�ָ�������Ŀ��
	���ָ����ڿ�ͷ���֣��Լ��������ַָ������򲻼�����
	ѭ����������ж����һ���ָ����Ҳ��Ƿ���ڴ��ָ�����Ŀ
*/
	for (i = 0, lastmatchedindex = -1, nums = 0; i <= len_s - len_d; i++) {
		if (strncmp(&str[i], delim, len_d) != 0)
			continue;
		if (i == 0 || i == lastmatchedindex + len_d) {
			;//�ָ����ڿ�ͷ���֣������������ַָ���
		} else {
			nums++;
		}
		lastmatchedindex = i;
		i += (len_d - 1);
	}
	if (len_s > lastmatchedindex + len_d)
		nums++;
/*
	������Ϊ0�������ָ���û��ʣ�µ��ַ���
*/
	if (nums == 0)
		return nums;
/*
	�����ַ���ָ������洢�ռ�
*/
	*p_strarr = (char **)malloc(sizeof(char *) * nums);
	if (*p_strarr == NULL)
		return -1;
/*
	ÿ��ѭ���ҳ��ָ������ַ���������洢�ռ䣬��������
	���벻�ɹ�Ҫ��ǰ��������Ŀռ䣨����*strarr���ͷŵ���������NULL
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

double average_delim_weighted(char const *str, char const *delim) {
	int i, nums, count;
	double value;
	char **strarr;
	nums = strsplit(str, delim, &strarr);
	if (nums <= 0)
		return 0;
	else {
		count = nums;
		if (nums > 2)
			count = (nums - 2) * 2 + 2;
		for (i = 0, value = 0; i < nums; i++) 
			if (i > 0 && i < nums - 1)
				value += atof(strarr[i]) * 2;
			else
				value += atof(strarr[i]);
		strsplit_free(&strarr, nums);
		value /= count;
	}
	return value;
}

char *dtostr(double const d, unsigned const pre) {
	double num = d;
	int i = 0;
	int sign = 1;//������� 
	int pow = 1;
	int len_i = 0, len_f = 0;
	int cor = 0;//С������ǰ���貹λ�� 
	long num_i = 0, num_f = 0;
	char *int_part = NULL;//�������� 
	char *float_part = NULL; //С������ 
	char *str = NULL;

	//�ж�����
	if (d < 0) 
		sign = -1, num = -num;
	while (++i <= pre)
		pow *= 10; 
	num = (num * pow + 0.5) * 1.0 / pow;
	//����������� 
	num_i = num;
	//���С������
	num_f = (num - num_i) * pow;
	
	//ת���������ֺ�С������ 
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
	�ж�С�������Ƿ���Ҫ����
	���С������������001��������ltostr�������򷵻��ַ��������1��
	���������Ҫ��ǰ������ַ�0���� 
	��������λ��С��������Ҳ����cor 
*/ 	
	len_i = strlen(int_part);
	if (num_f > 0)
		len_f = strlen(float_part);
	cor = pre - len_f;
	//����С������ĩβ��0�����õ�����֮��ĳ��� 
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
	//����ռ��СΪ���������ֳ��� + �������ֳ��ȣ�������λ��С���㣩 + С������ĩβ0��ĳ��� + 1 
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
	int digits = 0;//λ�� 
	int sign = 1;//������� 
	long num, i;
	char *str = NULL;
	num = l;
	if (num < 0) {
		sign = -1;
		num = ~num + 1;
	}
	i = num, digits = 0;
/*
	ͳ���ж���λ���֣�����ټӷ���λ 
*/
	do {
		i /= 10;
		digits++;
	} while(i != 0);
	if (sign == -1) 
		digits++;
/*
	����洢�ռ� 
*/
	str = (char *)calloc(digits + 1, sizeof(char));
	if (str == NULL) 
		return NULL;
/*
	շת�����ÿ�ε������Ӻ���ǰ�����ַ����飬����и������� 
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
	
	//���ٸ��Ʋ������ȴ����ַ������飬�������˻��Ѵ���������ʣ���ַ������ٽ������Ӳ��� 
	char *strarr[STRARR_CAPACITY];
	int aIndex = 0;
	
	char *str = NULL;
	char *temp = NULL;
	int sLen = 0;
	
	int i = 0, last = 0;
	
	for (i = 0; i < STRARR_CAPACITY; i++)
		strarr[i] = NULL;
	va_start(ap, format);
	
	for (i = 0; p[i] != '\0'; i++) {
		while (p[i] != '\0' && p[i++] != '%') 
			;
		switch (p[i]) {
			case 'c': case 'd': case 'f': case 's':
				if (last == i - 1)
					last = i + 1;
				//ת���%c��%d��%f��%s֮ǰ����δ������ַ��� 
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
					
					//���ص�%c��%d��%f��%s���д��� 
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
		
		//������������������Ԫ��������ַ��������һ��ͷ������� 
		if (aIndex == STRARR_CAPACITY) {
			str = strarrcat(strarr, STRARR_CAPACITY);
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
		for (i = 0; i < STRARR_CAPACITY; i++)
			free(strarr[i]), strarr[i] = NULL;
		return NULL;
	}
	
	str = strarrcat(strarr, STRARR_CAPACITY);
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

int replace(char **const p_str, char const *from, char const *to) {
	int len_s, len_f, len_t, len;
	int i, j, nums, lastmatchedindex;
	char *str = *p_str, *newstr = NULL;
/*
	����������ַ��������򷵻�0
*/ 
	if (str == NULL || from == NULL || to == NULL)
		return 0;
	len_s = strlen(str), len_f = strlen(from), len_t = strlen(to);
	if (len_s == 0) 
		return 0;
/*
	���ٲ���Ҫ���ڴ������� 
*/
	if (len_f >= len_t)
		return replace_at_original_location(*p_str, from, to);
		
/*
	ͳ�Ƴ����滻����nums
*/
	if (len_f == 0) {
		nums = 0;
	} else {
		for (i = 0, nums = 0; i <= len_s - len_f; i++) {
			if (strncmp(&str[i], from, len_f) != 0)
				continue;
			nums++;
			i += (len_f - 1);
		}
	}
/*
	�����滻����ַ�����ռ�õĿռ��С���������¿ռ� 
	����ʧ�ܷ���-1
*/ 
	newstr = (char *)malloc(len_s + (len_t - len_f) * nums + 1);
	if (newstr == NULL)
		return -1;
/*
	������Ҫ�滻���ַ���Ҫ�滻�ɵ��ַ����θ��Ƶ��¿ռ� 
*/
	if (nums == 0) {
		strncpy(newstr, str, len_s + 1);
	} else {
		for (i = 0, lastmatchedindex = 0, j = 0; i < len_s;) {
			if (strncmp(&str[i], from, len_f) == 0) {
				strncpy(&newstr[j], to, len_t);
				j += len_t;
				i += len_f;
				continue;
			}
			lastmatchedindex = i;
			while (++i < len_s && strncmp(&str[i], from, len_f) != 0)
				;
			len = i - lastmatchedindex;
			strncpy(&newstr[j], &str[lastmatchedindex], len);
			j += len;
		}
		newstr[j] = '\0';
	}
	free(str);
	*p_str = newstr;
	newstr = NULL;
	return 1;
}

int replace_at_original_location(char *const str, char const *from, char const *to) {
	int i, last; 
	int len_s = 0, len_f = 0, len_t = 0;
/*
	������Ч�Լ�� 
*/
	if (str == NULL || from == NULL || to == NULL)
		return 0;
	len_s = strlen(str), len_f = strlen(from), len_t = strlen(to);
	if (len_s == 0 || len_f < len_t)
		return 0;

/*
	���μ���Ƿ�ƥ�� 
	��ƥ�����ַ��ƶ���ǰ����дλ��last, last++
	ƥ�����ַ���to���Ƶ�ǰ����дλ��last, last+=len_t
*/
	for (i = 0, last = 0; i <= len_s - len_f; i++) {
		if (strncmp(&str[i], from, len_f) == 0) {
			strncpy(&str[last], to, len_t);//strncpy������'\0' 
			last += len_t;
			i += len_f - 1;
		} else {
			str[last++] = str[i];
		}
	}
	while (i <= len_s) 
		str[last++] = str[i++];
	
	return 1;
}


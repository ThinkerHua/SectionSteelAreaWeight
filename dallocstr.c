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

int replace(char **const p_str, char const *from, char const *to) {
	int len_s, len_f, len_t, len;
	int i, j, nums, lastmatchedindex;
	char *str = *p_str, *newstr = NULL;
/*
	不允许传入空字符串，否则返回0
*/ 
	if (str == NULL || from == NULL || to == NULL)
		return 0;
	len_s = strlen(str), len_f = strlen(from), len_t = strlen(to);
	if (len_s == 0) 
		return 0;
/*
	统计出待替换数量nums
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
		strncpy(newstr, str, len_s + 1);
	} else {
		for (i = 0, lastmatchedindex = 0, j = 0; i <= len_s - len_f;) {
			if (strncmp(&str[i], from, len_f) == 0) {
				strncpy(&newstr[j], to, len_t);
				j += len_t;
				i += len_f;
				continue;
			}
			lastmatchedindex = i;
			while (i < len_s && strncmp(&str[i], from, len_f) != 0)
				i++;
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

int replace_at_original_location(char *str, char const *from, char const *to) {
	int i, last; 
	int len_s = 0, len_f = 0, len_t = 0;
/*
	参数有效性检查 
*/
	if (str == NULL || from == NULL || to == NULL)
		return 0;
	len_s = strlen(str), len_f = strlen(from), len_t = strlen(to);
	if (len_s == 0 || len_f < len_t)
		return 0;

/*
	依次检查是否匹配 
	不匹配则将字符移动到前部可写位置last, last++
	匹配则将字符串to复制到前部可写位置last, last+=len_t
*/
	for (i = 0, last = 0; i <= len_s - len_f; i++) {
		if (strncmp(&str[i], from, len_f) == 0) {
			strncpy(&str[last], to, len_t);//strncpy不复制'\0' 
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


#ifndef dallocstr
#define dallocstr

#define DATA_PRECISION 4

int strsplit(char const *str, char const *delim, char ***const p_strarr);
/*
	将字符串str用字符串delim进行分割，分割后的多个字符串，保存在字符串数组strarr中
	应当将字符串数组strarr的地址做为参数传入，且strarr指向的空间是动态分配的 
	返回值	-1	传入的字符串str或delim为空字符串，或无法为strarr分配空间
			0	分割操作后，不存在可用字符串。此时不对p_strarr做任何操作 
			>0	分割操作后，字符串数组strarr中的项目数
	当strarr不需要使用时，必须使用配套的strsplit_free函数释放存储空间 
*/
void strsplit_free(char ***const p_strarr, int const nums);
/*
	与strsplit函数配套使用，将strsplit函数创建的字符串数组strarr释放掉
	应当将字符串数组strarr的地址做为参数传入
	必须保证nums与strsplit函数的返回值一致，否则后果未知 
*/

double average_delim(char const *str, char const *delim);
/*
	返回str内由delim分割的数值的平均值 
*/

char *dtostr(double const d, unsigned const pre);
/*
	仅支持十进制非指数形式 
	pre为小数位数。小数末尾的0不显示，小数全为0则小数点也不显示。
	失败返回NULL 
	得到的结果是动态分配的，不需要使用时应free掉 
*/
char *ltostr(long const l);
/*
	仅支持十进制非指数形式 
	失败返回NULL 
	得到的结果是动态分配的，不需要使用时应free掉 
*/

char *strcatEX(char const *format, ...);
/*
	根据格式字符串format，返回变长参数表各参数连接成的一个新字符串，失败返回NULL 
	支持的转义符及对应的参数类型有：
		%c	char 
		%d	int
		%f	double
		%s	char*
	不支持标准转义符（'\n'、'\t'等） 
	得到的结果是动态分配的，不需要使用时应free掉 
*/
char *strncpyEX(char const *source, int const len);
/*
	创建字符串source的前len个字符的新实例并返回，末尾添加'\0' 
	失败返回则返回NULL 
	得到的结果是动态分配的，不需要使用时应free掉 
*/
char *strarrcat(char *strarr[], int const capacity);
/*
	将字符串数组strarr中所有元素组合成一个新的字符串，并存入第一个元素，
	同时释放原有的各元素（原有的各元素指向的空间应当为动态分配的，即可被free） 
	应当同时传入参数数组容量capacity
	失败返回NULL（不释放strarr各元素指向的字符串）
	得到的结果是动态分配的，不需要使用时应free掉 
*/
int replace(char **const p_str, char const *from, char const *to);
/*
	将字符串str中包含的字符串from替换成字符串to
	字符串str应当是动态分配的，且应当传入字符串str的地址做为参数
	返回值	-1	无法为处理后的字符串分配空间
			0	传入的字符串为空字符串（空指针或0长度）
			1	替换成功 
	str不需要使用时应free掉 
*/
int replace_at_original_location(char *str, char const *from, char const *to);
/*
	效果类似replace函数，但只在字符串原始地址上进行操作，不创建新实例
	因此，from的长度不得短于to的长度
	与replace函数不同的是，本函数只需传入str，而不是str的地址
	返回值	0	传入的字符串为空字符串，或from的长度短于to的长度
			1	替换成功 
*/

#endif

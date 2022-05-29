#ifndef _SECTION_STEEL_H_
#define _SECTION_STEEL_H_

//#define SECSTE_NAME_LENGTH 10
typedef struct {
	char *ShortH;
	char *ShortB;
	char *H;
	char *B;
	char *tH;
	char *tB;
	char *Weight;
	char *Area;
}_SectionSteel_H;
_SectionSteel_H *new_H_ (void);
void free_H_(void *obj);
int setdata_H_(void *obj, char const *Formatedtext);
char *getResault_H_(void *obj, unsigned const CtrlCode);
char *getArea_H_(void *obj, unsigned const CtrlCode);
char *getWeight_H_(void *obj, unsigned const CtrlCode);

typedef struct {
	char *ShortH;
	char *ShortB;
	char *H;
	char *B1;
	char *B2;
	char *th;
	char *tB1;
	char *tB2;
	char *Weight;
	char *Area;
}SectionSteel_H;
SectionSteel_H *new_H (void);
void free_H(void *obj);
int setdata_H(void *obj, char const *Formatedtext);
char *getResault_H(void *obj, unsigned const CtrlCode);
char *getArea_H(void *obj, unsigned const CtrlCode);
char *getWeight_H(void *obj, unsigned const CtrlCode);

typedef _SectionSteel_H SectionSteel_HT;
SectionSteel_HT *new_HT (void);
void free_HT(void *obj);
int setdata_HT(void *obj, char const *Formatedtext);
char *getResault_HT(void *obj, unsigned const CtrlCode);
char *getArea_HT(void *obj, unsigned const CtrlCode);
char *getWeight_HT(void *obj, unsigned const CtrlCode);

typedef struct {
	char *H1;
	char *B1;
	char *tH1;
	char *tB1;
	char *H2;
	char *B2;
	char *tH2;
	char *tB2;
	char *Weight;
	char *Area;
}SectionSteel_HI;
SectionSteel_HI *new_HI (void);
void free_HI(void *obj);
int setdata_HI(void *obj, char const *Formatedtext);
char *getResault_HI(void *obj, unsigned const CtrlCode);
char *getArea_HI(void *obj, unsigned const CtrlCode);
char *getWeight_HI(void *obj, unsigned const CtrlCode);

typedef _SectionSteel_H SectionSteel_T;
SectionSteel_T *new_T (void);
void free_T(void *obj);
int setdata_T(void *obj, char const *Formatedtext);
char *getResault_T(void *obj, unsigned const CtrlCode);
char *getArea_T(void *obj, unsigned const CtrlCode);
char *getWeight_T(void *obj, unsigned const CtrlCode);

typedef struct {
	char *H;
	char *B;
	char *tH;
	char *tB;
	char *Weight;
	char *Area;
}SectionSteel_J;
SectionSteel_J *new_J (void);
void free_J(void *obj);
int setdata_J(void *obj, char const *Formatedtext);
char *getResault_J(void *obj, unsigned const CtrlCode);
char *getArea_J(void *obj, unsigned const CtrlCode);
char *getWeight_J(void *obj, unsigned const CtrlCode);

typedef struct {
	char *D;
	char *t;
	char *Weight;
	char *Area;
}SectionSteel_D;
SectionSteel_D *new_D (void);
void free_D(void *obj);
int setdata_D(void *obj, char const *Formatedtext);
char *getResault_D(void *obj, unsigned const CtrlCode);
char *getArea_D(void *obj, unsigned const CtrlCode);
char *getWeight_D(void *obj, unsigned const CtrlCode);

typedef struct {
	char *Name;
	char *H;
	char *B;
	char *tH;
	char *tB;
	char *Weight;
	char *Area;
}SectionSteel_I;
SectionSteel_I *new_I (void);
void free_I(void *obj);
int setdata_I(void *obj, char const *Formatedtext);
char *getResault_I(void *obj, unsigned const CtrlCode);
char *getArea_I(void *obj, unsigned const CtrlCode);
char *getWeight_I(void *obj, unsigned const CtrlCode);

typedef struct {
	char *Name;
	char *H;
	char *B;
	char *tH;
	char *tB;
	char *Weight;
	char *Area;
}SectionSteel_Chan;
SectionSteel_Chan *new_Chan (void);
void free_Chan(void *obj);
int setdata_Chan(void *obj, char const *Formatedtext);
char *getResault_Chan(void *obj, unsigned const CtrlCode);
char *getArea_Chan(void *obj, unsigned const CtrlCode);
char *getWeight_Chan(void *obj, unsigned const CtrlCode);

typedef SectionSteel_Chan SectionSteel_Chan_MtM;
SectionSteel_Chan_MtM *new_Chan_MtM (void);
void free_Chan_MtM(void *obj);
int setdata_Chan_MtM(void *obj, char const *Formatedtext);
char *getResault_Chan_MtM(void *obj, unsigned const CtrlCode);
char *getArea_Chan_MtM(void *obj, unsigned const CtrlCode);
char *getWeight_Chan_MtM(void *obj, unsigned const CtrlCode);

typedef SectionSteel_Chan SectionSteel_Chan_BtB;
SectionSteel_Chan_BtB *new_Chan_BtB (void);
void free_Chan_BtB(void *obj);
int setdata_Chan_BtB(void *obj, char const *Formatedtext);
char *getResault_Chan_BtB(void *obj, unsigned const CtrlCode);
char *getArea_Chan_BtB(void *obj, unsigned const CtrlCode);
char *getWeight_Chan_BtB(void *obj, unsigned const CtrlCode);

typedef struct {
	char *Name;
	char *B1;
	char *B2;
	char *t;
	char *Weight;
	char *Area;
}SectionSteel_L;
SectionSteel_L *new_L (void);
void free_L(void *obj);
int setdata_L(void *obj, char const *Formatedtext);
char *getResault_L(void *obj, unsigned const CtrlCode);
char *getArea_L(void *obj, unsigned const CtrlCode);
char *getWeight_L(void *obj, unsigned const CtrlCode);

typedef SectionSteel_L SectionSteel_2L;
SectionSteel_2L *new_2L (void);
void free_2L(void *obj);
int setdata_2L(void *obj, char const *Formatedtext);
char *getResault_2L(void *obj, unsigned const CtrlCode);
char *getArea_2L(void *obj, unsigned const CtrlCode);
char *getWeight_2L(void *obj, unsigned const CtrlCode);

typedef struct {
	char *H;
	char *B;
	char *C;
	char *t;
	char *Weight;
	char *Area;
}SectionSteel_C;
SectionSteel_C *new_C (void);
void free_C(void *obj);
int setdata_C(void *obj, char const *Formatedtext);
char *getResault_C(void *obj, unsigned const CtrlCode);
char *getArea_C(void *obj, unsigned const CtrlCode);
char *getWeight_C(void *obj, unsigned const CtrlCode);

typedef SectionSteel_C SectionSteel_2C;
SectionSteel_2C *new_2C (void);
void free_2C(void *obj);
int setdata_2C(void *obj, char const *Formatedtext);
char *getResault_2C(void *obj, unsigned const CtrlCode);
char *getArea_2C(void *obj, unsigned const CtrlCode);
char *getWeight_2C(void *obj, unsigned const CtrlCode);

typedef SectionSteel_C SectionSteel_Z;
SectionSteel_Z *new_Z (void);
void free_Z(void *obj);
int setdata_Z(void *obj, char const *Formatedtext);
char *getResault_Z(void *obj, unsigned const CtrlCode);
char *getArea_Z(void *obj, unsigned const CtrlCode);
char *getWeight_Z(void *obj, unsigned const CtrlCode);

typedef struct structPL{
	char *B;
	char *L;
	char *t;
	char *Weight;
	char *Area;
	struct structPL *pNext;
}_SectionSteel_PL;
_SectionSteel_PL *new_PL_ (void);
void free_PL_(void *obj);
int setdata_PL_(void *obj, char const *Formatedtext);
char *getResault_PL_(void *obj, unsigned const CtrlCode);
char *getArea_PL_(void *obj, unsigned const CtrlCode);
char *getWeight_PL_(void *obj, unsigned const CtrlCode);

typedef struct structPLT{
	char *B;
	char *L;
	char *t;
	char *Weight;
	char *Area;
	struct structPLT *pNext;
}_SectionSteel_PLT;
_SectionSteel_PLT *new_PLT_ (void);
void free_PLT_(void *obj);
int setdata_PLT_(void *obj, char const *Formatedtext);
char *getResault_PLT_(void *obj, unsigned const CtrlCode);
char *getArea_PLT_(void *obj, unsigned const CtrlCode);
char *getWeight_PLT_(void *obj, unsigned const CtrlCode);

typedef struct structPLD{
	char *D;
	char *t;
	char *Weight;
	char *Area;
	struct structPLD *pNext;
}_SectionSteel_PLD;
_SectionSteel_PLD *new_PLD_ (void);
void free_PLD_(void *obj);
int setdata_PLD_(void *obj, char const *Formatedtext);
char *getResault_PLD_(void *obj, unsigned const CtrlCode);
char *getArea_PLD_(void *obj, unsigned const CtrlCode);
char *getWeight_PLD_(void *obj, unsigned const CtrlCode);

typedef struct {
	_SectionSteel_PL *pPL;
	_SectionSteel_PLT *pPLT;
	_SectionSteel_PLD *pPLD;
	char *Weight;
	char *Area;
}SectionSteel_PL;
SectionSteel_PL *new_PL (void);
void free_PL(void *obj);
int setdata_PL(void *obj, char const *Formatedtext);
char *getResault_PL(void *obj, unsigned const CtrlCode);
char *getArea_PL(void *obj, unsigned const CtrlCode);
char *getWeight_PL(void *obj, unsigned const CtrlCode);

typedef struct {
	char *B;
	char *L;
	char *t;
	char *Weight;
	char *Area;
}SectionSteel_PLT;
SectionSteel_PLT *new_PLT (void);
void free_PLT(void *obj);
int setdata_PLT(void *obj, char const *Formatedtext);
char *getResault_PLT(void *obj, unsigned const CtrlCode);
char *getArea_PLT(void *obj, unsigned const CtrlCode);
char *getWeight_PLT(void *obj, unsigned const CtrlCode);

typedef struct {
	char *D;
	char *t;
	char *Weight;
	char *Area;
}SectionSteel_PLD;
SectionSteel_PLD *new_PLD (void);
void free_PLD(void *obj);
int setdata_PLD(void *obj, char const *Formatedtext);
char *getResault_PLD(void *obj, unsigned const CtrlCode);
char *getArea_PLD(void *obj, unsigned const CtrlCode);
char *getWeight_PLD(void *obj, unsigned const CtrlCode);

int strsplit(char const *str, char const *delim, char ***const p_strarr);
/*
	将字符串str用字符串delim进行分割，分割后的多个字符串，保存在字符串数组strarr中
	应当将字符串数组strarr的地址做为参数传入 
	返回值	-1	传入的字符串str或delim为空字符串，或无法为strarr分配空间
			>=0	分割操作后，字符串数组strarr中的项目数
	当strarr不需要使用时，必须使用配套的strsplit_free函数释放存储空间 
*/
void strsplit_free(char ***const p_strarr, int const nums);
/*
	与strsplit函数配套使用，将strsplit函数创建的字符串数组strarr释放掉
	必须保证nums与strsplit函数的返回值一致，否则后果未知 
*/

char *dtoa(double const d, unsigned const pre);

#endif

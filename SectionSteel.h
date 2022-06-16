#ifndef _SECTION_STEEL_H_
#define _SECTION_STEEL_H_

//typedef struct {
//	/*AorW = 0 -> area
//	  AorW = 1 -> Weight*/
//	unsigned AorW : 1;
//	/*TopSurface = 0 -> Exclude TopSurface
//	  TopSurface = 1 -> Include TopSurface*/
//	unsigned TopSurface : 1;
//	/*Method = 0 -> Roughly
//	  Method = 1 -> Precisely
//	  Method = 2 -> Look up in table*/
//	unsigned Method : 2;
//}ControlCode;
#define TYPE_AREA					1
#define TYPE_EXCLUDE_TOPSURFACE		2
#define TYPE_WEIGHT					4
#define METHOD_ROUGHLY				8
#define METHOD_PRECISELY			16
#define METHOD_LOOKUP				32

#define LINKSYM "*"
#define GRADSYM "~"
#define DIVSYM "/"
#define CUTSYM "-"
#define WELDSYM "+"

#define GBSECSTE_NAME_LENGTH 15

#define STEEL_DENSITY 7850

typedef struct {
	char const *Type;
	double ShortH;
	double ShortB;
	double H;
	double B;
	double tH;
	double tB;
}SectionSteel_H_;
SectionSteel_H_ *new_H_ (void);
/*
	失败则返回NULL 
*/ 
void free_H_(void **p_object);
int setData_H_(void *object, char const *FormatedText);
/*
	失败返回0，成功返回1
	应当经由统一接口调用。非统一接口私自调用，则参数FormatedText必须符合约定规则 
*/
int expand_H_(void *object);
/*
	失败返回0，成功返回1 
*/
char *getResault_H_(void *object, unsigned const CtrlCode);
/*
	失败返回NULL
	得到的结果不需要使用时应free掉 
*/
char *getArea_H_(void *object, unsigned const CtrlCode);
/*
	一般不直接调用，而是通过getResault_H_函数调用 
	失败返回NULL
	得到的结果不需要使用时应free掉 
*/
char *getWeight_H_(void *object, unsigned const CtrlCode);
/*
	一般不直接调用，而是通过getResault_H_函数调用 
	失败返回NULL
	得到的结果不需要使用时应free掉 
*/

/*
	以下结构相关函数说明同上 
*/
typedef struct {
	char const *Type;
	double ShortH;
	double ShortB;
	double H;
	double B1;
	double B2;
	double tH;
	double tB1;
	double tB2;
}SectionSteel_H;
SectionSteel_H *new_H (void);
void free_H(void **p_object);
int setData_H(void *object, char const *FormatedText);
int expand_H(void *object);
char *getResault_H(void *object, unsigned const CtrlCode);
char *getArea_H(void *object, unsigned const CtrlCode);
char *getWeight_H(void *object, unsigned const CtrlCode);

typedef SectionSteel_H_ SectionSteel_HT;
SectionSteel_HT *new_HT (void);
void free_HT(void **p_object);
int setData_HT(void *object, char const *FormatedText);
//int expand_HT(void *object);
char *getResault_HT(void *object, unsigned const CtrlCode);
char *getArea_HT(void *object, unsigned const CtrlCode);
char *getWeight_HT(void *object, unsigned const CtrlCode);

typedef struct {
	char const *Type;
	double H1;
	double B1;
	double tH1;
	double tB1;
	double H2;
	double B2;
	double tH2;
	double tB2;
}SectionSteel_HI;
SectionSteel_HI *new_HI (void);
void free_HI(void **p_object);
int setData_HI(void *object, char const *FormatedText);
int expand_HI(void *object);
char *getResault_HI(void *object, unsigned const CtrlCode);
char *getArea_HI(void *object, unsigned const CtrlCode);
char *getWeight_HI(void *object, unsigned const CtrlCode);

typedef SectionSteel_H_ SectionSteel_T;
SectionSteel_T *new_T (void);
void free_T(void **p_object);
int setData_T(void *object, char const *FormatedText);
//int expand_T(void *object);
char *getResault_T(void *object, unsigned const CtrlCode);
char *getArea_T(void *object, unsigned const CtrlCode);
char *getWeight_T(void *object, unsigned const CtrlCode);

typedef struct {
	char const *Type;
	double H;
	double B;
	double tH;
	double tB;
}SectionSteel_J;
SectionSteel_J *new_J (void);
void free_J(void **p_object);
int setData_J(void *object, char const *FormatedText);
char *getResault_J(void *object, unsigned const CtrlCode);
char *getArea_J(void *object, unsigned const CtrlCode);
char *getWeight_J(void *object, unsigned const CtrlCode);

typedef struct {
	char const *Type;
	double D;
	double t;
}SectionSteel_D;
SectionSteel_D *new_D (void);
void free_D(void **p_object);
int setData_D(void *object, char const *FormatedText);
char *getResault_D(void *object, unsigned const CtrlCode);
char *getArea_D(void *object, unsigned const CtrlCode);
char *getWeight_D(void *object, unsigned const CtrlCode);

typedef struct {
	char const *Type;
	char *Name;
	double H;
	double B;
	double tH;
	double tB;
}SectionSteel_I;
SectionSteel_I *new_I (void);
void free_I(void **p_object);
int setData_I(void *object, char const *FormatedText);
int expand_I(void *object);
char *getResault_I(void *object, unsigned const CtrlCode);
char *getArea_I(void *object, unsigned const CtrlCode);
char *getWeight_I(void *object, unsigned const CtrlCode);

typedef SectionSteel_I SectionSteel_Chan;
SectionSteel_Chan *new_Chan (void);
void free_Chan(void **p_object);
int setData_Chan(void *object, char const *FormatedText);
//int expand_Chan(void *object);
char *getResault_Chan(void *object, unsigned const CtrlCode);
char *getArea_Chan(void *object, unsigned const CtrlCode);
char *getWeight_Chan(void *object, unsigned const CtrlCode);

typedef SectionSteel_Chan SectionSteel_Chan_MtM;
SectionSteel_Chan_MtM *new_Chan_MtM (void);
void free_Chan_MtM(void **p_object);
int setData_Chan_MtM(void *object, char const *FormatedText);
//int expand_Chan_MtM(void *object);
char *getResault_Chan_MtM(void *object, unsigned const CtrlCode);
char *getArea_Chan_MtM(void *object, unsigned const CtrlCode);
char *getWeight_Chan_MtM(void *object, unsigned const CtrlCode);

typedef SectionSteel_Chan SectionSteel_Chan_BtB;
SectionSteel_Chan_BtB *new_Chan_BtB (void);
void free_Chan_BtB(void **p_object);
int setData_Chan_BtB(void *object, char const *FormatedText);
//int expand_Chan_BtB(void *object);
char *getResault_Chan_BtB(void *object, unsigned const CtrlCode);
char *getArea_Chan_BtB(void *object, unsigned const CtrlCode);
char *getWeight_Chan_BtB(void *object, unsigned const CtrlCode);

typedef struct {
	char const *Type;
	char *Name;
	double B1;
	double B2;
	double t;
}SectionSteel_L;
SectionSteel_L *new_L (void);
void free_L(void **p_object);
int setData_L(void *object, char const *FormatedText);
int expand_L(void *object);
char *getResault_L(void *object, unsigned const CtrlCode);
char *getArea_L(void *object, unsigned const CtrlCode);
char *getWeight_L(void *object, unsigned const CtrlCode);

typedef SectionSteel_L SectionSteel_2L;
SectionSteel_2L *new_2L (void);
void free_2L(void **p_object);
int setData_2L(void *object, char const *FormatedText);
//int expand_2L(void *object);
char *getResault_2L(void *object, unsigned const CtrlCode);
char *getArea_2L(void *object, unsigned const CtrlCode);
char *getWeight_2L(void *object, unsigned const CtrlCode);

typedef struct {
	char const *Type;
	double H;
	double B;
	double C;
	double t;
}SectionSteel_C;
SectionSteel_C *new_C (void);
void free_C(void **p_object);
int setData_C(void *object, char const *FormatedText);
//int expand_C(void *object);
char *getResault_C(void *object, unsigned const CtrlCode);
char *getArea_C(void *object, unsigned const CtrlCode);
char *getWeight_C(void *object, unsigned const CtrlCode);

typedef SectionSteel_C SectionSteel_2C;
SectionSteel_2C *new_2C (void);
void free_2C(void **p_object);
int setData_2C(void *object, char const *FormatedText);
//int expand_2C(void *object);
char *getResault_2C(void *object, unsigned const CtrlCode);
char *getArea_2C(void *object, unsigned const CtrlCode);
char *getWeight_2C(void *object, unsigned const CtrlCode);

typedef SectionSteel_C SectionSteel_Z;
SectionSteel_Z *new_Z (void);
void free_Z(void **p_object);
int setData_Z(void *object, char const *FormatedText);
//int expand_Z(void *object);
char *getResault_Z(void *object, unsigned const CtrlCode);
char *getArea_Z(void *object, unsigned const CtrlCode);
char *getWeight_Z(void *object, unsigned const CtrlCode);

typedef struct subPL{
	char const *Type;
	double B;
	double L;
	double t;
	struct subPL *pNext;
}SectionSteel_PL_;
SectionSteel_PL_ *new_PL_ (void);
void free_PL_(void **p_object);
int setData_PL_(void *object, char const *FormatedText);
char *getResault_PL_(void *object, unsigned const CtrlCode);
char *getArea_PL_(void *object, unsigned const CtrlCode);
char *getWeight_PL_(void *object, unsigned const CtrlCode);

typedef SectionSteel_PL_ SectionSteel_PLT_;
SectionSteel_PLT_ *new_PLT_ (void);
void free_PLT_(void **p_object);
int setData_PLT_(void *object, char const *FormatedText);
char *getResault_PLT_(void *object, unsigned const CtrlCode);
char *getArea_PLT_(void *object, unsigned const CtrlCode);
char *getWeight_PLT_(void *object, unsigned const CtrlCode);

typedef struct subPLD{
	char const *Type;
	double D;
	double t;
	struct subPLD *pNext;
}SectionSteel_PLD_;
SectionSteel_PLD_ *new_PLD_ (void);
void free_PLD_(void **p_object);
int setData_PLD_(void *object, char const *FormatedText);
char *getResault_PLD_(void *object, unsigned const CtrlCode);
char *getArea_PLD_(void *object, unsigned const CtrlCode);
char *getWeight_PLD_(void *object, unsigned const CtrlCode);

typedef struct {
	SectionSteel_PL_ *pPL;
	SectionSteel_PLT_ *pPLT;
	SectionSteel_PLD_ *pPLD;
}SectionSteel_PL;
SectionSteel_PL *new_PL (void);
void free_PL(void **p_object);
int setData_PL(void *object, char const *FormatedText);
char *getResault_PL(void *object, unsigned const CtrlCode);
char *getArea_PL(void *object, unsigned const CtrlCode);
char *getWeight_PL(void *object, unsigned const CtrlCode);

typedef struct {
	char const *Type;
	double B;
	double L;
	double t;
}SectionSteel_PLT;
SectionSteel_PLT *new_PLT (void);
void free_PLT(void **p_object);
int setData_PLT(void *object, char const *FormatedText);
char *getResault_PLT(void *object, unsigned const CtrlCode);
char *getArea_PLT(void *object, unsigned const CtrlCode);
char *getWeight_PLT(void *object, unsigned const CtrlCode);

typedef struct {
	char const *Type;
	double D;
	double t;
}SectionSteel_PLD;
SectionSteel_PLD *new_PLD (void);
void free_PLD(void **p_object);
int setData_PLD(void *object, char const *FormatedText);
char *getResault_PLD(void *object, unsigned const CtrlCode);
char *getArea_PLD(void *object, unsigned const CtrlCode);
char *getWeight_PLD(void *object, unsigned const CtrlCode);

#endif

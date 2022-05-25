#ifndef _SECTION_STEEL_H_
#define _SECTION_STEEL_H_

//#define SECSTE_NAME_LENGTH 10
typedef struct {
	double ShortH;
	double ShortB;
	double H;
	double B;
	double tH;
	double tB;
	char *Weight;
	char *Area;
}_SectionSteel_H;

typedef struct {
	double ShortH;
	double ShortB;
	double H;
	double B1;
	double B2;
	double th;
	double tB1;
	double tB2;
	char *Weight;
	char *Area;
}SectionSteel_H;

typedef _SectionSteel_H SectionSteel_HT;

typedef struct {
	double H1;
	double B1;
	double tH1;
	double tB1;
	double H2;
	double B2;
	double tH2;
	double tB2;
	char *Weight;
	char *Area;
}SectionSteel_HI;

typedef _SectionSteel_H SectionSteel_T;

typedef struct {
	double H;
	double B;
	double tH;
	double tB;
	char *Weight;
	char *Area;
}SectionSteel_J;

typedef struct {
	double D;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_D;

typedef struct {
	char *Name;
	double H;
	double B;
	double tH;
	double tB;
	char *Weight;
	char *Area;
}SectionSteel_I;

typedef struct {
	char *Name;
	double H;
	double B;
	double tH;
	double tB;
	char *Weight;
	char *Area;
}SectionSteel_Chan;

typedef SectionSteel_Chan SectionSteel_Chan_MtM;
typedef SectionSteel_Chan SectionSteel_Chan_BtB;

typedef struct {
	char *Name;
	double B1;
	double B2;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_L;

typedef SectionSteel_L SectionSteel_2L;

typedef struct {
	double H;
	double B;
	double C;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_C;

typedef SectionSteel_C SectionSteel_2C;
typedef SectionSteel_C SectionSteel_Z;

typedef struct structPL{
	double B;
	double L;
	double t;
	char *Weight;
	char *Area;
	struct structPL *pNext;
}_SectionSteel_PL;

typedef struct structPLT{
	double B;
	double L;
	double t;
	char *Weight;
	char *Area;
	struct structPLT *pNext;
}_SectionSteel_PLT;

typedef struct structPLD{
	double D;
	double t;
	char *Weight;
	char *Area;
	struct structPLD *pNext;
}_SectionSteel_PLD;

typedef struct {
	_SectionSteel_PL *pPL;
	_SectionSteel_PLT *pPLT;
	_SectionSteel_PLD *pPLD;
	char *Weight;
	char *Area;
}SectionSteel_PL;

typedef struct {
	double B;
	double L;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_PLT;

typedef struct {
	double D;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_PLD;

SectionSteel_H *new_H (void);
SectionSteel_HT *new_HT (void);
SectionSteel_HI *new_HI (void);
SectionSteel_T *new_T (void);
SectionSteel_J *new_J (void);
SectionSteel_D *new_D (void);
SectionSteel_I *new_I (void);
SectionSteel_Chan *new_Chan (void);
SectionSteel_Chan_MtM *new_Chan_MtM (void);
SectionSteel_Chan_BtB *new_Chan_BtB (void);
SectionSteel_L *new_L (void);
SectionSteel_2L *new_2L (void);
SectionSteel_C *new_C (void);
SectionSteel_2C *new_2C (void);
SectionSteel_Z *new_Z (void);
SectionSteel_PL *new_PL (void);
SectionSteel_PLT *new_PLT (void);
SectionSteel_PLD *new_PLD (void);

int setdata_H_(void *obj, char const *Formatedtext);
int setdata_H(void *obj, char const *Formatedtext);
int setdata_HT(void *obj, char const *Formatedtext);
int setdata_HI(void *obj, char const *Formatedtext);
int setdata_T(void *obj, char const *Formatedtext);
int setdata_J(void *obj, char const *Formatedtext);
int setdata_D(void *obj, char const *Formatedtext);
int setdata_I(void *obj, char const *Formatedtext);
int setdata_Chan(void *obj, char const *Formatedtext);
int setdata_Chan_MtM(void *obj, char const *Formatedtext);
int setdata_Chan_BtB(void *obj, char const *Formatedtext);
int setdata_L(void *obj, char const *Formatedtext);
int setdata_2L(void *obj, char const *Formatedtext);
int setdata_C(void *obj, char const *Formatedtext);
int setdata_2C(void *obj, char const *Formatedtext);
int setdata_Z(void *obj, char const *Formatedtext);
int setdata_PL_(void *obj, char const *Formatedtext);
int setdata_PLT_(void *obj, char const *Formatedtext);
int setdata_PLD_(void *obj, char const *Formatedtext);
int setdata_PL(void *obj, char const *Formatedtext);
int setdata_PLT(void *obj, char const *Formatedtext);
int setdata_PLD(void *obj, char const *Formatedtext);

char *getResault_H_(void *obj, unsigned const CtrlCode);
char *getResault_H(void *obj, unsigned const CtrlCode);
char *getResault_HT(void *obj, unsigned const CtrlCode);
char *getResault_HI(void *obj, unsigned const CtrlCode);
char *getResault_T(void *obj, unsigned const CtrlCode);
char *getResault_J(void *obj, unsigned const CtrlCode);
char *getResault_D(void *obj, unsigned const CtrlCode);
char *getResault_I(void *obj, unsigned const CtrlCode);
char *getResault_Chan(void *obj, unsigned const CtrlCode);
char *getResault_Chan_MtM(void *obj, unsigned const CtrlCode);
char *getResault_Chan_BtB(void *obj, unsigned const CtrlCode);
char *getResault_L(void *obj, unsigned const CtrlCode);
char *getResault_2L(void *obj, unsigned const CtrlCode);
char *getResault_C(void *obj, unsigned const CtrlCode);
char *getResault_2C(void *obj, unsigned const CtrlCode);
char *getResault_Z(void *obj, unsigned const CtrlCode);
char *getResault_PL_(void *obj, unsigned const CtrlCode);
char *getResault_PLT_(void *obj, unsigned const CtrlCode);
char *getResault_PLD_(void *obj, unsigned const CtrlCode);
char *getResault_PL(void *obj, unsigned const CtrlCode);
char *getResault_PLT(void *obj, unsigned const CtrlCode);
char *getResault_PLD(void *obj, unsigned const CtrlCode);

char *getArea_H_(void *obj, unsigned const CtrlCode);
char *getArea_H(void *obj, unsigned const CtrlCode);
char *getArea_HT(void *obj, unsigned const CtrlCode);
char *getArea_HI(void *obj, unsigned const CtrlCode);
char *getArea_T(void *obj, unsigned const CtrlCode);
char *getArea_J(void *obj, unsigned const CtrlCode);
char *getArea_D(void *obj, unsigned const CtrlCode);
char *getArea_I(void *obj, unsigned const CtrlCode);
char *getArea_Chan(void *obj, unsigned const CtrlCode);
char *getArea_Chan_MtM(void *obj, unsigned const CtrlCode);
char *getArea_Chan_BtB(void *obj, unsigned const CtrlCode);
char *getArea_L(void *obj, unsigned const CtrlCode);
char *getArea_2L(void *obj, unsigned const CtrlCode);
char *getArea_C(void *obj, unsigned const CtrlCode);
char *getArea_2C(void *obj, unsigned const CtrlCode);
char *getArea_Z(void *obj, unsigned const CtrlCode);
char *getArea_PL_(void *obj, unsigned const CtrlCode);
char *getArea_PLT_(void *obj, unsigned const CtrlCode);
char *getArea_PLD_(void *obj, unsigned const CtrlCode);
char *getArea_PL(void *obj, unsigned const CtrlCode);
char *getArea_PLT(void *obj, unsigned const CtrlCode);
char *getArea_PLD(void *obj, unsigned const CtrlCode);

char *getWeight_H_(void *obj, unsigned const CtrlCode);
char *getWeight_H(void *obj, unsigned const CtrlCode);
char *getWeight_HT(void *obj, unsigned const CtrlCode);
char *getWeight_HI(void *obj, unsigned const CtrlCode);
char *getWeight_T(void *obj, unsigned const CtrlCode);
char *getWeight_J(void *obj, unsigned const CtrlCode);
char *getWeight_D(void *obj, unsigned const CtrlCode);
char *getWeight_I(void *obj, unsigned const CtrlCode);
char *getWeight_Chan(void *obj, unsigned const CtrlCode);
char *getWeight_Chan_MtM(void *obj, unsigned const CtrlCode);
char *getWeight_Chan_BtB(void *obj, unsigned const CtrlCode);
char *getWeight_L(void *obj, unsigned const CtrlCode);
char *getWeight_2L(void *obj, unsigned const CtrlCode);
char *getWeight_C(void *obj, unsigned const CtrlCode);
char *getWeight_2C(void *obj, unsigned const CtrlCode);
char *getWeight_Z(void *obj, unsigned const CtrlCode);
char *getWeight_PL_(void *obj, unsigned const CtrlCode);
char *getWeight_PLT_(void *obj, unsigned const CtrlCode);
char *getWeight_PLD_(void *obj, unsigned const CtrlCode);
char *getWeight_PL(void *obj, unsigned const CtrlCode);
char *getWeight_PLT(void *obj, unsigned const CtrlCode);
char *getWeight_PLD(void *obj, unsigned const CtrlCode);

char **strsplit(char const *str, char const *delim);

#endif

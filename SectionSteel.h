#ifndef _SECTION_STEEL_H_
#define _SECTION_STEEL_H_

//#define SECSTE_NAME_LENGTH 10
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
typedef struct {
	double ShortH;
	double ShortB;
	double H;
	double B;
	double tH;
	double tB;
	char *Weight;
	char *Area;
}SectionSteel_HT;
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
typedef struct {
	double ShortH;
	double ShortB;
	double H;
	double B;
	double tH;
	double tB;
	char *Weight;
	char *Area;
}SectionSteel_T;
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
typedef struct {
	char *Name;
	double H;
	double B;
	double tH;
	double tB;
	char *Weight;
	char *Area;
}SectionSteel_Chan_MtM;
typedef struct {
	char *Name;
	double H;
	double B;
	double tH;
	double tB;
	char *Weight;
	char *Area;
}SectionSteel_Chan_BtB;
typedef struct {
	char *Name;
	double B1;
	double B2;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_L;
typedef struct {
	char *Name;
	double B1;
	double B2;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_2L;
typedef struct {
	double H;
	double B;
	double C;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_C;
typedef struct {
	double H;
	double B;
	double C;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_2C;
typedef struct {
	double H;
	double B;
	double C;
	double t;
	char *Weight;
	char *Area;
}SectionSteel_Z;
typedef struct {
	double B;
	double L;
	double t;
	char *Weight;
	char *Area;
}_SectionSteel_PL;
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
typedef struct {
	_SectionSteel_PL PL[];
	SectionSteel_PLT PLT[];
	SectionSteel_PLD PLD[];
	char *Weight;
	char *Area;
}SectionSteel_PL;

#endif

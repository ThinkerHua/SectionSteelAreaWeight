#ifndef _CALCULATION_H_
#define _CALCULATION_H_

#define TYPE_AREA               0B0000
#define TYPE_WEIGHT             0B0001
#define TYPE_INCLUDE_TOPSURFACE 0B0000
#define TYPE_EXCLUDE_TOPSURFACE 0B0010
#define METHOD_ROUGHLY          0B0000
#define METHOD_PRECISELY        0B0100
#define METHOD_LOOKUP           0B1000

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

#endif

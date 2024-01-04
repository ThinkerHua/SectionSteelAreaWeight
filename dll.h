#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

int Creat_SetData_Obj(char const *RawText, char **p_SecSteType, void **p_obj);
/*
	�����͸�ʵ�����󲢸�ֵ���ɹ�����1��ʧ�ܷ���0
	���SecSteType�����͸����ͣ�ָ�����const�ַ���������Ҫʹ��ʱֻ�踳ֵNULL����Ӧfree
	���obj�����͸�ʵ������ָ��Ķ����Ƕ�̬����ģ�����Ҫʹ��ʱӦfree 
*/
DLLIMPORT char *SectionSteel_Area_Weight(char const *RawText, unsigned const CtrlCode);
/*
	�����͸ֵĵ�λ�����λ�����ļ���ʽ
	ʧ�ܷ���NULL 
	CtrlCode˵���μ�"calculation.h"�е�"getResault"���� 
*/ 
DLLIMPORT char *Stiffener_Specification(char const *RawText, unsigned const CtrlCode);
/*
	�����͸ֵļӾ��߹��
	ʧ�ܷ���NULL 
*/ 
DLLIMPORT void free_dallocstr(char *str);
/*
	������ר��VB.netʹ�� 
	C���Կ�ֱ��ʹ��free�ͷŶ�̬������ַ��� 
*/

#endif

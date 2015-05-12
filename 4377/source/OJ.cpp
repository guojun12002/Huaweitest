
#include "OJ.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
  
/*
����:	��������ѡ �ֵ�ƽ���÷֡�
    
���������ָ��ָ����ڴ�����֤��Ч����
	 	char* pInputString���ַ������飬������ĳɼ���������������0-10�����������ֵĳ��Ȳ�����30���ַ�
		int Num������������ѡ�ֵ�������2 <= Num <= 26��
���������ָ��ָ����ڴ�����֤��Ч����
	 	char* pResult��һ��buffer��������в����ߵ�������ƽ���֣�����2λС��������ʽҪ�����£�
			1��������ǰ��ƽ�����ں��м���һ���ո������
			2��ÿ�в����ߵĳɼ�ռһ�У����һ�������߳ɼ�֮��Ҫ���з�����
			3������ɼ�������˳������ 	
����ֵ��
		void

*/


void GetResult(char* pInput[], int Num, char *pResult)
{
	if(NULL == pInput || pResult == NULL) return;
	for(int i=0; i<Num; ++i)
	{
		int sc[7];
		char name[50], put[50];
		sscanf(pInput[i], "%d %d %d %d %d %d %d %s", sc, sc+1, sc+2, sc+3, sc+4, sc+5, sc+6, name);
		sort(sc, sc+7);
		double avg = 0;
		for(int i=1; i<6; ++i)
			avg += sc[i];
		avg /= 5;
		sprintf(put, "%.2f", avg);
		strcat(pResult, name);
		strcat(pResult, " ");
		strcat(pResult, put);
		if(i != Num-1) strcat(pResult, "\n");
		// printf("%d %d %d %d %d %d %d\n", sc[0],sc[1],sc[2],sc[3],sc[4],sc[5],sc[6]);
		// cout<<name<<endl;
	}
	return;
} 

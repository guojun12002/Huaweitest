
#include "OJ.h"
 
  
/*
void GetResult(int InputNum, double *NumResult);
���������
		Int  InputNum������һ�������������б��ʽ����
	 	char *NumResult��������ʽ��ֵ 	
����ֵ��
		void

*/

void GetResult(int InputNum, double *NumResult)
{
	if(NULL == NumResult) return;
	*NumResult = 0;
	if(InputNum <= 0) return;
	for(int i=1; i<=InputNum; ++i)
		*NumResult += 1.0/fact(i);
    return ;
}

double fact(int k)
{
	if(k <= 1) return 1;
	else return fact(k-1) * (double)k;
}

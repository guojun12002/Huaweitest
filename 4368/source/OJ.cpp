
#include "OJ.h"

/*
����:��������������飬�������Ԫ���е����ֵ�����ֵ�ĸ�������Сֵ����Сֵ�ĸ���
    
����:int * pInputInteger����������ָ��
	 int * InputNum������Ԫ�ظ���
    
���:int * pMaxValue�����������ֵ
  	 int * pMaxNum�����������ֵ�ĸ���
	 int * pMinValue����������Сֵ
     int * pMinNum����������Сֵ�ĸ���
     
����:void
*/
void OutputMaxAndMin(int * pInputInteger, int InputNum, int * pMaxValue, int * pMaxNum, int * pMinValue, int * pMinNum)
{
	/*������ʵ�ֹ���*/
    if(pInputInteger == NULL || InputNum == 0 || pMaxValue == NULL || NULL == pMaxNum || NULL == pMaxValue || NULL == pMinNum) return ;
    *pMaxValue = pInputInteger[0];
    *pMinValue = pInputInteger[0];
    *pMaxNum = 1;
    *pMinNum = 1;
    for(int i=1; i<InputNum; ++i)
    {
    	if(*pMaxValue < pInputInteger[i])
    	{
    		*pMaxValue = pInputInteger[i];
    		*pMaxNum = 1;
    	}
    	else if(*pMaxValue == pInputInteger[i])
    		*pMaxNum += 1;
    	if(*pMinValue > pInputInteger[i])
    	{
    		*pMinValue = pInputInteger[i];
    		*pMinNum = 1;
    	}
    	else if(*pMinValue == pInputInteger[i])
    		*pMinNum += 1;
    }
	return;
}



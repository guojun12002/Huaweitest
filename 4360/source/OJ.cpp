#include <stdlib.h>
#include <string.h>
#include "oj.h"
const float PI = 3.14;

/*
����:
    
����: 
    
���:	arrValue:�洢���صķ��Ϸ�Χ֮�ڵ�Բ������ڴ��ں������Ѿ����� 
		nValue:�������������
     
����: 
     
*/

void OutputRotundityArea(float *arrValue,int &nValue)
{
	for(int i=1; i<=10; ++i)
	{
		float area = PI * i * i;
		if(area >= 40 && area <=90) arrValue[nValue++] = area;
	}
}
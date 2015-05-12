#include <stdlib.h>
#include <string.h>
#include "oj.h"
const float PI = 3.14;

/*
功能:
    
输入: 
    
输出:	arrValue:存储返回的符合范围之内的圆面积，内存在函数外已经申请 
		nValue:返回数组的行数
     
返回: 
     
*/

void OutputRotundityArea(float *arrValue,int &nValue)
{
	for(int i=1; i<=10; ++i)
	{
		float area = PI * i * i;
		if(area >= 40 && area <=90) arrValue[nValue++] = area;
	}
}
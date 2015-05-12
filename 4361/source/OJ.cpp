#include <stdlib.h>
#include <string.h>
#include "oj.h"


/*
功能:
    
输入:pIntArray:数组,nCout:数组长度
    
输出:
     
返回:返回最大值
     
*/

int GetSubArraySum(int* pIntArray, int nCount)
{
    /*在这里实现功能*/
    if(pIntArray == NULL) return 0;
	int* maxsum = new int[nCount];
	maxsum[0] = pIntArray[0];
	for(int i=1; i<nCount; ++i)
		if(maxsum[i-1] < 0) maxsum[i] = pIntArray[i];
		else maxsum[i] = maxsum[i-1] + pIntArray[i];
	int max = maxsum[0];
	for(int i=1; i<nCount; ++i)
		if(max < maxsum[i]) max = maxsum[i];
	delete[] maxsum;
    return max;
}
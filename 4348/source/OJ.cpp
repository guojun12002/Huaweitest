#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "oj.h"

// 功能：排列一个m行n列 大小的数组
// 输入： int * pArray 指向数组第一个元素的指针,m为行数， n为列数 ，请按第i列排列
// 输出：按第i列排序完成后的数组放到入参指定的地址中	(i的取值范围 1 - n)
// 返回：
void RangeArray(int * pArray,unsigned int  m, unsigned int  n,unsigned int  i)
{
	if(NULL == pArray) return;
	if(i < 1 || i > n) return;
    if(m <= 0 || n <= 0) return;
    for(int j=0; j<m-1; ++j)
        for(int k=j+1; k<m; ++k)
            for(int l=i-1; l<n; ++l)
                if(pArray[j*n+l] < pArray[k*n+l])
                    break;
                else if(pArray[j*n+l] > pArray[k*n+l])
                {
                    swap_line(pArray, j, k, n);
                    break;
                }
    return;
}

void swap_line(int *pArray, unsigned int line1, unsigned int line2, unsigned int n)
{
    for(int i=0; i<n; ++i)
    {
        int temp = pArray[line1*n+i];
        pArray[line1*n+i] = pArray[line2*n+i];
        pArray[line2*n+i] = temp;
    }
    return;
}
void print(int *p, int m, int n)
{
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
            printf("%d ", p[i*n+j]);
        printf("\n");
    }
    printf("\n");
}




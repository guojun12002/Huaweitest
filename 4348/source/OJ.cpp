#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "oj.h"

// ���ܣ�����һ��m��n�� ��С������
// ���룺 int * pArray ָ�������һ��Ԫ�ص�ָ��,mΪ������ nΪ���� ���밴��i������
// ���������i��������ɺ������ŵ����ָ���ĵ�ַ��	(i��ȡֵ��Χ 1 - n)
// ���أ�
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




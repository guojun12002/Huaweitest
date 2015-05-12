#include "oj.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
/*
功能: 矩阵相乘
    
输入: MatrixA,MatrixB
    
输出: MatrixC

返回: 0
     
*/

int matrix(int **MatrixA, int **MatrixB, int **MatrixC, int N)
{
	if(NULL == MatrixA || NULL == MatrixB || NULL == MatrixC || N == 0) return 0;
	int *A = (int*)MatrixA;
	int *B = (int*)MatrixB;
	int *C = (int*)MatrixC;
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
		{
			C[i*N+j] = 0;
			for(int k=0; k<N; ++k)
			{
				C[i*N+j] += A[i*N+k] * B[k*N+j];
			}
		}
	return 0;
}

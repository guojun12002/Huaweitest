#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#include "source/sqlist.cpp"
void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}

int main()
{
int j = 0;
	int k = 0;
	struct strmatrix mul = {0};
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  0,  0,
                                4,  5,  6,  0,  0,
                                7,  8,  9,  0,  0,
                               10, 11, 12,  0,  0,
                                0,  0,  0,  0,  0};
	int b[MAXSIZE][MAXSIZE] = { 1,  2,  3,  4,  0,
                                5,  6,  7,  8,  0,
                                9, 10, 11, 12,  0,
                                0,  0,  0,  0,  0,
                                0,  0,  0,  0,  0};

	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 3;

	struct strmatrix q = {0};
	q.rownum = 3;
	q.columnnum = 4;

	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
			q.matrix[j][k] = b[j][k];
		}
	}

	matrixmultiply(&mul, &p, &q);

	int c[MAXSIZE][MAXSIZE] =   {  38,  44,  50,  56,  0,
                                   83,  98, 113, 128,  0,
                                  128, 152, 176, 200,  0,
                                  173, 206, 239, 272,  0,
                                    0,   0,   0,   0,  0};

	CPPUNIT_ASSERT(mul.rownum == 4);
	CPPUNIT_ASSERT(mul.columnnum == 4);
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			CPPUNIT_ASSERT(mul.matrix[j][k] == c[j][k]);
			// printf("%3d ", mul.matrix[j][k]);
		}
		// printf("\n");
	}
	return 0;
}
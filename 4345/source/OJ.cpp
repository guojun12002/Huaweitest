
#include "OJ.h"

/*
����:�ҳ�1��n֮��ͬ�����ĸ���
���룺
    int n������1��n֮���ȫ��ͬ����
���أ�
    int��1��n֮��ͬ�����ĸ���
*/
bool isSCN(int n)
{
	int num = n * n;
	int x = 10;
	while(n / x != 0) x *= 10;
	if(num % x == n) return true;
	return false;
}
int SearchSameConstructNum(int n)
{
    /*������ʵ�ֹ���*/
	if(n < 1) return 0;
	int sum = 0;
	for(int i=1; i<=n; ++i)
	{
		if(isSCN(i))
			++sum;
	}
    return sum;
}

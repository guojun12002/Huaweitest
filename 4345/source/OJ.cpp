
#include "OJ.h"

/*
功能:找出1至n之间同构数的个数
输入：
    int n：查找1至n之间的全部同构数
返回：
    int：1至n之间同构数的个数
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
    /*在这里实现功能*/
	if(n < 1) return 0;
	int sum = 0;
	for(int i=1; i<=n; ++i)
	{
		if(isSCN(i))
			++sum;
	}
    return sum;
}

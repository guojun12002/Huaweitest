
#include "OJ.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;


/*
功能:

输入参数：int*p 指向二维数组的首地址，该二维数组第0行的两个数分别表示：总钱数<30000，和希望购买物品的个数<25;
          该数组从第1行到第m行(1<=j<=m)中给出了编号为j的物品的基本数据，每行有2个非负整数，
		  表示该物品的价格(<=10000)和该物品的重要度(1~5)。

		  GetResult表示不超过总钱数的物品的价格与重要度乘积的总和的最大值(<100000000)。

		  不需做入参检查，测试用例可以保证～

    例如：4000 8（第0行）
		  821 3  （第1行）
		  422 5
		  458 5
		  500 3
		  200 2
		  430 4
		  530 3
		  239 3

		  则表示 总钱数为4000，希望购买物品个数为8个，因此从第1行到第8行表示编号为j的物品的价格及物品的重要度。




返回值：无

温馨提示：根据题意可知，该二维数组只有两列，且行数为第0行的第二个元素数值+1;入参p不能按照二维数组的方法来取值，要将
          二维的转换成一维的哦～

*/

void GetResult(int*p,int& Get_Result)
{
    //	在这里实现功能
    if(NULL == p) return;
    int money[30000] = {};
    for(int i=1; i<=p[1]; ++i)
    	for(int j=p[0]; j>=p[i*2+0]; --j)
    	{
    		int temp = money[j-p[i*2+0]] + p[i*2+0]*p[i*2+1];
    		if(money[j] < temp)
    			money[j] = temp;
    	}
    Get_Result = money[p[0]];
}


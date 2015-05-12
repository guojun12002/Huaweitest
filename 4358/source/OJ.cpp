
#include "OJ.h"

/*
功能: 根据里程计算车速
原型：
    int CalcSpeedOfCar(int iCurrentMileage, int * piCarSpeed);

输入参数：
    int pcCurrentMileage:当前里程数(为对称数)(pcCurrentMileage ≤ 999999)

返回值：
    汽车速度(公里/小时)
*/

int CalcSpeedOfCar(int iCurrentMileage, int * piCarSpeed)
{
    /*在这里实现功能*/
	if(NULL == piCarSpeed) return 1;
	for(int i=iCurrentMileage+1; i<1000000; ++i)
		if(isH(i))
		{
			*piCarSpeed = (i - iCurrentMileage) / 2;
			return 0;
		}
    return 1;
}
bool isH(int n)
{
	char str[10];
	int l = 0;
	while(n > 0)
	{
		str[l] = n % 10;
		++l;
		n /= 10;
	}
	str[l] = '\0';
	for(int i=0; i<=l/2; ++i)
		if(str[i] != str[l-i-1]) return false;
	return true;
}

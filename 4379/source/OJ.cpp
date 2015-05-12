
#include "OJ.h"
#include <algorithm>
  
/*
功能:判断yuanzi 的马是否会赢？yuanzi 的马赢了，返回 YES. 否则返回 NO
    
输入参数：
unsigned int num: 赛马的数量；   (1<= num <=1000)
unsigned int * speed_yz: yuanzi 的马的速度；
unsigned int * speed_op: 对手的马的速度；
输出参数：
	 	无 	
返回值：
		char * 型 的字符串，yuanzi 的马赢了，返回 YES. 否则返回 NO；

*/
unsigned int p = 0;
bool faster(unsigned int* speed_yz, unsigned int speed, unsigned int num)
{
	while(p < num)
		if(speed_yz[p++] > speed)
			return true;
	return false;
}
void print(unsigned int num, unsigned int *a)
{
	for(int i=0; i<num; ++i)
		cout<<a[i]<<' ';
	cout<<endl;
}
char * IsYuanziWin(unsigned int num, unsigned int * speed_yz, unsigned int * speed_op)
{
	if(num == 0 || NULL == speed_yz || NULL == speed_op) return NULL;
	sort(speed_op, speed_op+num);
	sort(speed_yz, speed_yz+num);
	print(num,speed_yz);
	print(num,speed_op);

	unsigned int sum = 0;
	for(unsigned int i=0; i<num; ++i)
		if(faster(speed_yz, speed_op[i], num)) ++sum;
		else break;
	if(sum > num/2) return "YES";
	else return "NO";
}



#include <stdlib.h>
#include "oj.h"
// 功能：获取第nValue1个月出生多少对兔子
// 输入： nValue1为正整数
// 输出：无
// 返回：第nValue1个月出生多少对兔子


unsigned int GetBirthRabbitNum(unsigned int  nValue1)
{
	if(nValue1 == 1 || nValue1 == 2) return 1;
	else return GetBirthRabbitNum(nValue1-2)+GetBirthRabbitNum(nValue1-1);
}
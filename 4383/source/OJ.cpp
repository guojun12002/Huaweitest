
#include "OJ.h"

/*
功能: 找出字符串中第一个出现次数最多的字符
    
输入: char* pInputString：字符串
    
输出: char* pChar：出现次数最多的字符
     
返回: false 异常失败
	  true  输出成功
*/

bool FindChar(char* pInputString, char* pChar)
{
	//在这里实现功能

	if(pInputString == NULL || pChar == NULL) return false;
	if(strlen(pInputString) == 0) return false;
	int c[256] = {};
	char* str = pInputString;
	while(*str != '\0')
	{
		++c[*str];
		++str;
	}
	int max = 0;
	for(int i=0; i<256; ++i)
		if(max < c[i])
		{
			max = c[i];
			*pChar = i;
		}
	return true;
}

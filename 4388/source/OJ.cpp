#include "oj.h"
/*
功能: 字符串中删除指定字符
    
输入: in, c
    
输出: out

返回: 0
     
*/

int removechars(char *in, char c, char *out)
{
	if(in == NULL || out == NULL) return 0;
	char* s = in;
	while(*s != '\0')
	{
		if(*s != c)
		{
			*out = *s;
			++out;
		}
		++s;
	}
	*out = '\0';

	return 0;
}

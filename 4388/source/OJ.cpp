#include "oj.h"
/*
����: �ַ�����ɾ��ָ���ַ�
    
����: in, c
    
���: out

����: 0
     
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

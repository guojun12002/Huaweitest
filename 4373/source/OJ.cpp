#include <stdlib.h>
#include <string.h>
#include "oj.h"

int ChangeString(char *pInStr,char *pOutStr)
{
	if(NULL == pInStr || NULL == pOutStr)
		return -1;
	int len = strlen(pInStr);
	char* s = strcpy(pOutStr, pInStr);
	if(len < 3) return 0;
	s += 2;
	while(*s != '\0')
	{
		if(*(s-2) == *s && *(s-1) == *s && islower(*s))
		{
			char* pre_s = s - 2;
			*pre_s = (*s)=='z'?'a':(*s)+1;
			do
			{
				++s;
				++pre_s;
				*pre_s = *s;
			}while(*s != '\0');
			s = pOutStr;
			if(strlen(s) < 3) return 0;
			else ++s;
		}
		++s;
	}
	return 0;
}
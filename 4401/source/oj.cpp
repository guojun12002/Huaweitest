#include "oj.h"

int GetMinPeriod(char *inputstring)
{
	if(NULL == inputstring || inputstring[0] == '\0') return 0;
	int len = strlen(inputstring);
	char* str = inputstring;
	for(int k=1; k<=len; ++k)	//长度
	{
		if(len % k != 0) continue;
		int i = len / k;		//周期
		bool flag = true;
		for(int j=0; j<i-1; ++j)
			if(strncmp(str+j*k, str+(j+1)*k, k) != 0)
			{
				flag = false;
				break;
			}
		if(flag) return k;
	}
}
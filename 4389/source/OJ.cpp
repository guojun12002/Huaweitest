#include <stdlib.h>
#include <string.h>
#include "oj.h"


/*
功能:
    
输入:
    
输出:
     
返回:success :0,fail:-1
     
*/

int ProcessString(char * strInput,char * strOutput)
{
	if(strInput == NULL || strOutput == NULL) return -1;
	int l = strlen(strInput);
	for(int i=0; i<l; ++i)
		strOutput[i] = strInput[l-i-1];
	strOutput[l] = '\0';
	return 0;
}
#include <stdlib.h>
#include <string.h>
#include "oj.h"


/*
����:
    
����:
    
���:
     
����:�ɹ�0,����-1
     
*/

int ProcessString( char * strInput,char chSrc,char chDes ,char * strOutput)
{
	if(NULL == strInput || NULL == strOutput) return -1;
	int len = strlen(strInput);
	if(len < 1) return -1;
	for(int i=0; i<len; ++i)
		if(strInput[i] == chSrc) strOutput[i] = chDes;
		else strOutput[i] = strInput[i];
	strOutput[len] = '\0';
	return 0;
}
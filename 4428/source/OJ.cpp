#include <stdlib.h>
#include "oj.h"
/* 功能：在字符串中找出连续最长的数字串，并把这个串的长度返回
函数原型：
   unsigned int Continumax(char** pOutputstr,  char* intputstr)
输入参数：
   char* intputstr  输入字符串
输出参数：
   char** pOutputstr: 连续最长的数字串，如果连续最长的数字串的长度为0，应该返回空字符串
   pOutputstr 指向的内存应该在函数内用malloc函数申请，由调用处负责释放

返回值：
  连续最长的数字串的长度

 */
unsigned int Continumax(char** pOutputstr,  char* intputstr)
{
	unsigned int len=strlen(intputstr);
	*pOutputstr=(char*)malloc(sizeof(char)*(len+1));
	char* output=*pOutputstr;
	output[0]='\0';
	unsigned int count=0;
	unsigned int maxcout=0;
	for(int i=0;i<=len;i++)
	{
		if(isdigit(intputstr[i]))
			++count;
		else
		{
			if(maxcout <= count)
			{
				int j;
				for(j=0; j<count; j++)
					output[count-1-j] = intputstr[i-1-j];
				output[j]='\0';
				maxcout = count;
			}
			count=0;
		}
	}
	return maxcout;
}
#include <stdlib.h>
#include "oj.h"
/* ���ܣ����ַ������ҳ�����������ִ�������������ĳ��ȷ���
����ԭ�ͣ�
   unsigned int Continumax(char** pOutputstr,  char* intputstr)
���������
   char* intputstr  �����ַ���
���������
   char** pOutputstr: ����������ִ����������������ִ��ĳ���Ϊ0��Ӧ�÷��ؿ��ַ���
   pOutputstr ָ����ڴ�Ӧ���ں�������malloc�������룬�ɵ��ô������ͷ�

����ֵ��
  ����������ִ��ĳ���

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

#include "OJ.h"

/*
Description  
         ����һ���ַ��������ַ��������к�ǰ���ظ�������ַ�ɾ���������ַ�����������������ַ�������Ҫ��֤�ַ����ֵ��Ⱥ�˳��
Prototype
         int GetResult(const char *input, char *output)
Input Param 
         input     ������ַ���
Output Param 
         output    ������ַ���
Return Value
         0         �ɹ�
         -1        ʧ�ܼ��쳣
*/
int GetResult(const char *input, char *output)
{
	if(NULL == input || NULL == output) return -1;
	bool ch[255]={};
	int len= strlen(input);
	output[0]='\0';
	char* str=output;
	for(int i=0;i<len;i++)
		if(!ch[input[i]])
		{
			*str= input[i];
			ch[input[i]]=true;
			str++;
		}
	*str='\0';
	if(strlen(output)>0) return 0;
    return -1;
}

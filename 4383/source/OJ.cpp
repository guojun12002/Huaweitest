
#include "OJ.h"

/*
����: �ҳ��ַ����е�һ�����ִ��������ַ�
    
����: char* pInputString���ַ���
    
���: char* pChar�����ִ��������ַ�
     
����: false �쳣ʧ��
	  true  ����ɹ�
*/

bool FindChar(char* pInputString, char* pChar)
{
	//������ʵ�ֹ���

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

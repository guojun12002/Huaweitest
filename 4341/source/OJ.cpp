
#include "OJ.h"

#include "OJ.h"
#include <stdio.h>
#include <string.h>

/*
����:��������ַ������д����������Jam���������ַ���

���������
	 	Char InMinSeq��������С����ĸ�����
		char InMaxSeq: ����������ĸ�����
		int InNumbLen�� �����ַ���λ��
        char InChaStr: �������InNumbLen���ַ����ַ���
���������ָ��ָ����ڴ�����֤��Ч����
	 	char* pBufOutData�����ת������ַ��б��ԡ�\n������
����ֵ
		void

*/


void GetResult(int InMinSeq, int InMaxSeq, int InNumbLen, char *InChaStr, char *pBufOutData)
{
	if(InChaStr == NULL || pBufOutData == NULL) return;
	int i, j, k;
	char *str = InChaStr;
    char c[30];
    int Len = InNumbLen - 1;
    int count = 0;
	string s = "";
    for(i=InMinSeq; i<=InMaxSeq; i++)
        c[i] = 'a'+i-1;
    c[i] = '\0';
    bool flag;
    i = Len;
    j = InMaxSeq;
    while(count<=4 && str[0]!=c[InMaxSeq-Len])
    {
        flag = false;
        if(str[i] != c[j])
        {
            flag = true;
            str[i] = str[i]+1;
            for(k=i+1; k<=Len; k++)
                str[k] = str[k-1] + 1;
			str[Len+1]='\n',str[Len+2]='\0';
			s.append(str);
            ++count;
        }
        --i;
        --j;
        if(flag)
        {
        	i = Len;
            j = InMaxSeq;
        }
    }
    if(s.length() == 0)
		pBufOutData[0] = '\0';
	else
	{
		s[s.length()-1] = '\0';
	    int z = 0;
	    while(s[z] != '\0')
		{
			pBufOutData[z] = s[z];
			z++;
		}
		pBufOutData[z] = '\0';
	}
}

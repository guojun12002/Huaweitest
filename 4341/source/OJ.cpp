
#include "OJ.h"

#include "OJ.h"
#include <stdio.h>
#include <string.h>

/*
功能:对输入的字符串进行处理，输出符合Jam记数法的字符串

输入参数：
	 	Char InMinSeq：输入最小的字母的序号
		char InMaxSeq: 输入最大的字母的序号
		int InNumbLen： 输入字符的位数
        char InChaStr: 输入具有InNumbLen个字符的字符串
输出参数（指针指向的内存区域保证有效）：
	 	char* pBufOutData：输出转换后的字符列表，以‘\n’区分
返回值
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

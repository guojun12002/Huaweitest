#include "IPAddressValid.h"


bool isIPAddressValid(const char* pszIPAddr)
{
    // 请在此处实现
    if(NULL == pszIPAddr) return false;
    int len=strlen(pszIPAddr);
    if(len<7 || len>15) return false;
	char s[100];
	strcpy(s, pszIPAddr);
	// 消除两端空格
	int sl=0,sr=len-1;
	while(s[sl]==' ') ++sl;
	while(s[sr]==' ') --sr;
	s[sr+1]='.';
	s[sr+2]='\0';

	char* str=s+sl;
	// 中间含有空格
	if(strchr(str, ' ') != NULL) return false;
	char substr[100];
	int ss;
	while(*str != '\0')
	{
		ss=0;
		while(*str != '.') substr[ss++]=*(str++);
		substr[ss]='\0';
		// printf("%s ", substr);
		++str;

		if(strlen(substr)>1 && substr[0]=='0') return false;
		if(strlen(substr)<1) return false;
		int num=0;
		for(int i=0;i<ss;i++)
		{
			if(isdigit(substr[i])) num=num*10+substr[i]-'0';
			else return false;
		}
		// printf("%d ", num);
		if(num>255 || num<0) return false;
	}
    return true;
}
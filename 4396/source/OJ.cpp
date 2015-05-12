
#include "OJ.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
/*
����: ������ֵռ��BIT������˳��������ֽ����н�������Ӧ��ֵ������˳����������astElement��������
    
����:unsigned int uiIutputLen���ֽ����飨��������
	 unsigned char aInputByte���ֽ����飨����
     unsigned int uiElementNum��������ֵ����
	 ELEMENT_STRU astElement[]����ֵ�Ľṹ����ָ�룬��������
	 Struct
	 {
	 	unsigned int uiElementLength;	//��ʾuiElementValueռ��BIT������Χ1~32
		unsigned int uiElementValue;	//���ֽ����а�˳���������ֵ���������
	 }ELEMENT_STRU;
    
���:�μ�����ELEMENT_STRU��uiElementValue����
     
����:void
*/
void Decode(unsigned int uiIutputLen, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[])
{
	/*������ʵ�ֹ���*/
    if(NULL == aInputByte || NULL == astElement) return;
    string str;
    for(int i=uiIutputLen-1; i>=0; --i)
    {
    	int num = (int) aInputByte[i];
    	for(int j=0; j<8; ++j)
    	{
    		str.insert(str.begin(), '0'+num%2);
    		num /= 2;
    	}
    }
    int n = 0;
    for(int i=0; i<uiElementNum; ++i)
    {
    	astElement[i].uiElementValue = 0;
    	for(int j=0; j<astElement[i].uiElementLength; ++j)
    		astElement[i].uiElementValue = astElement[i].uiElementValue * 2 + str[n++]-'0';
    }
	return;
}



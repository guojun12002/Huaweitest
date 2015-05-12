
#include "OJ.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
/*
功能: 根据数值占用BIT数，按顺序从输入字节流中解析出对应数值，解析顺序按输入数组astElement索引升序
    
输入:unsigned int uiIutputLen：字节数组（流）长度
	 unsigned char aInputByte：字节数组（流）
     unsigned int uiElementNum：解析数值个数
	 ELEMENT_STRU astElement[]：数值的结构数组指针，含义如下
	 Struct
	 {
	 	unsigned int uiElementLength;	//表示uiElementValue占用BIT数，范围1~32
		unsigned int uiElementValue;	//从字节流中按顺序解析的数值，用于输出
	 }ELEMENT_STRU;
    
输出:参见上述ELEMENT_STRU中uiElementValue描述
     
返回:void
*/
void Decode(unsigned int uiIutputLen, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[])
{
	/*在这里实现功能*/
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



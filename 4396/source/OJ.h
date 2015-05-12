#ifndef __OJ_H__
#define __OJ_H__

typedef struct
{
    unsigned int uiElementLength;	//表示数值uiElementValue占用BIT数，范围1~32
    unsigned int uiElementValue;	//表示编码的数值
}ELEMENT_STRU;

void Decode(unsigned int uiIutputLen, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[]);


#endif

#ifndef __OJ_H__
#define __OJ_H__

typedef struct
{
    unsigned int uiElementLength;	//��ʾ��ֵuiElementValueռ��BIT������Χ1~32
    unsigned int uiElementValue;	//��ʾ�������ֵ
}ELEMENT_STRU;

void Decode(unsigned int uiIutputLen, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[]);


#endif

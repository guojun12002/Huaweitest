#include <stdlib.h>
#include "oj.h"
// ���ܣ���ȡ��nValue1���³������ٶ�����
// ���룺 nValue1Ϊ������
// �������
// ���أ���nValue1���³������ٶ�����


unsigned int GetBirthRabbitNum(unsigned int  nValue1)
{
	if(nValue1 == 1 || nValue1 == 2) return 1;
	else return GetBirthRabbitNum(nValue1-2)+GetBirthRabbitNum(nValue1-1);
}
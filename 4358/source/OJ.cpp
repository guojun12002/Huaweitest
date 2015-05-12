
#include "OJ.h"

/*
����: ������̼��㳵��
ԭ�ͣ�
    int CalcSpeedOfCar(int iCurrentMileage, int * piCarSpeed);

���������
    int pcCurrentMileage:��ǰ�����(Ϊ�Գ���)(pcCurrentMileage �� 999999)

����ֵ��
    �����ٶ�(����/Сʱ)
*/

int CalcSpeedOfCar(int iCurrentMileage, int * piCarSpeed)
{
    /*������ʵ�ֹ���*/
	if(NULL == piCarSpeed) return 1;
	for(int i=iCurrentMileage+1; i<1000000; ++i)
		if(isH(i))
		{
			*piCarSpeed = (i - iCurrentMileage) / 2;
			return 0;
		}
    return 1;
}
bool isH(int n)
{
	char str[10];
	int l = 0;
	while(n > 0)
	{
		str[l] = n % 10;
		++l;
		n /= 10;
	}
	str[l] = '\0';
	for(int i=0; i<=l/2; ++i)
		if(str[i] != str[l-i-1]) return false;
	return true;
}

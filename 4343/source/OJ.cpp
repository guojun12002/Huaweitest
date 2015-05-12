
#include "OJ.h"

/*
����: ��n(n �� 65536)���ڵ����а�ķ˹������
ԭ�ͣ�
    int CalcArmstrongNumber(int n);

���������
    int n: n �� 65536

����ֵ��
    n���ڵİ�ķ˹��������������
*/

int CalcArmstrongNumber(int n)
{
    /*������ʵ�ֹ���*/
	int sum = 0;
	for(int i=2; i<=n; ++i)
	{
		int num = i;
		int s[10];
		int l = 0;
		int x = 0;
		while(num > 0)
		{
			s[l++] = num % 10;
			num /= 10;
		}
		for(int j=0; j<l; ++j)
			x += s[j] * s[j] * s[j];
		if(x == i) ++sum;
	}
    return sum;
}

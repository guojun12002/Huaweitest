
#include "OJ.h"
#include <algorithm>
  
/*
����:�ж�yuanzi �����Ƿ��Ӯ��yuanzi ����Ӯ�ˣ����� YES. ���򷵻� NO
    
���������
unsigned int num: �����������   (1<= num <=1000)
unsigned int * speed_yz: yuanzi ������ٶȣ�
unsigned int * speed_op: ���ֵ�����ٶȣ�
���������
	 	�� 	
����ֵ��
		char * �� ���ַ�����yuanzi ����Ӯ�ˣ����� YES. ���򷵻� NO��

*/
unsigned int p = 0;
bool faster(unsigned int* speed_yz, unsigned int speed, unsigned int num)
{
	while(p < num)
		if(speed_yz[p++] > speed)
			return true;
	return false;
}
void print(unsigned int num, unsigned int *a)
{
	for(int i=0; i<num; ++i)
		cout<<a[i]<<' ';
	cout<<endl;
}
char * IsYuanziWin(unsigned int num, unsigned int * speed_yz, unsigned int * speed_op)
{
	if(num == 0 || NULL == speed_yz || NULL == speed_op) return NULL;
	sort(speed_op, speed_op+num);
	sort(speed_yz, speed_yz+num);
	print(num,speed_yz);
	print(num,speed_op);

	unsigned int sum = 0;
	for(unsigned int i=0; i<num; ++i)
		if(faster(speed_yz, speed_op[i], num)) ++sum;
		else break;
	if(sum > num/2) return "YES";
	else return "NO";
}



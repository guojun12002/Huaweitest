
#include "OJ.h"
 
  
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
void print(unsigned int num, unsigned int *a)
{
	for(int i=0; i<num; ++i)
		cout<<a[i]<<' ';
	cout<<endl;
}
void sort(unsigned int *a,int n)
{
    int i,j;
	unsigned int num;
    for (i=0;i<n;i++)
        for (j=0;j<n-i;j++)
        {
            if (a[j]>a[j+1])
            {
                num=a[j];
                a[j]=a[j+1];
                a[j+1]=num;
            }
    print(n,a);
        }
}





char * IsYuanziWin(unsigned int num, unsigned int * speed_yz, unsigned int * speed_op)
{
   for(int i=0;i<num;i++)
	   int t=speed_yz[i];


    sort(speed_yz,num);
	sort(speed_op,num);
	int count=0;
	int j,start=0;

    for(int i=0;i<num;i++)
	{
	  for(j=start;j<num;j++)
	  {
	   if(speed_yz[i]>speed_op[j])
	   {
	      count++;
		  start=j+1;
		  break;
	   }
	  }
	}


	if(count>num/2)
	return "YES";
	else
  	return "NO";



	
}



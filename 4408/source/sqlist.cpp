/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2013/08/10
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2013/08/10
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
/*
��ϸ������   
int JudgeTrainSequence (int maxNum, char *pOutSeq);
���������
	 	int maxNum����վ�Ļ������
	 	char* pOutSeq��ʹ���ַ�����ʾ�𳵳�վ����
���������ָ��ָ����ڴ�����֤��Ч����
	 	�ޡ�
����ֵ��
		Int: ��������Ľ�վ�����жϣ��������ĳ�ս�����ǿ��ܵģ�����1�����򷵻�0��

*/
int data[10];
int *t;
int m;
int top()
{
  if(t==data) return 0;
  return *(t-1);
}
bool pop()
{
  if(t>data) t--;
  else return false;
  return true;
}
bool push(int no)
{
  if(t-data<m) *t++=no;
  else return false;
  return true;
}
int JudgeTrainSequence (int maxNum, char *pOutSeq)
{
  if(maxNum < 1 || maxNum > 9 || pOutSeq == NULL)
    return 0;
  t = data;
  m = maxNum;
  int train=0, i;
  for(i=0;i<m;i++)
  {
    bool flag=true;
    if(top() > pOutSeq[i]-'0') break;
    else
    {
      while(top()< pOutSeq[i]-'0')
        flag = flag & push(++train);
      if(!flag) break;
      if(top()==pOutSeq[i]-'0') pop();
    }
  }
  if(i<m)
    return 0;
  else
    return 1;
}



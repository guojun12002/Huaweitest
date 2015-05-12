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
详细描述：   
int JudgeTrainSequence (int maxNum, char *pOutSeq);
输入参数：
	 	int maxNum：进站的火车最大编号
	 	char* pOutSeq：使用字符串表示火车出站序列
输出参数（指针指向的内存区域保证有效）：
	 	无。
返回值：
		Int: 根据输入的进站序列判断，如果输入的出战序列是可能的，返回1，否则返回0；

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



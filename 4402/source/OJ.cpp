/******************************************************************************

  Copyright (C), 2001-2013, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2013/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2013/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
const double LING = 1E-6;
double number[4];
bool m_judge; //判断是否有解。
int count = 0;
void Find(int n)
{
  if (n == 1)
  {
    if ( fabs(number[0] -24) <= LING )
      m_judge = true;
  }
  for(int i=0; i < n; i++)//查找
  {
    for (int j = i + 1; j < n; j++)//与其后面的查找进行计算
    {
      double a, b;
      string expressiona, expressionb;
      a = number[i];
      b = number[j];
      number[j] = number[n - 1];
      number[i] = a + b;
      Find(n-1);
      number[i] = a - b;
      Find(n-1);
      number[i] = b -a;
      Find(n-1);
      number[i]=a*b;
      Find(n-1);
      if (b != 0)
      {
        number[i] = a / b;
        Find(n-1);
      }
      if (a != 0)
      {
        number[i] = b / a;
        Find(n-1);
      }
      number[i] =a;
      number[j]=b;
    }
  }
}
bool Game24Points(int a, int b, int c, int d)
{
	//TODO: Add codes here ...
  number[0] = a;
  number[1] = b;
  number[2] = c;
  number[3] = d;
  m_judge = false;
  Find(4);
	return m_judge;
}


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
#define MAXNUM 1000
#define MAXWIGHT 3000

int *pw, *pm;
int dp[1005];
// int sq[1005];
int num[1005];
void DP(int i, int n)
{
  for(int j=i+1; j<n; ++j)
    if(num[i] <= num[j] && pm[i] >= dp[j])
    {
      // sq[i] = j;
      num[i] = num[j] + 1;
      dp[i] = pw[i] + dp[j];
    }
    else
    {
      // sq[i] = i;
      if(num[i] == 0)
        dp[i] = pw[i];
    }
  return;
}
int CalcMaxNum(int n, int * pW, int * pM)
{
  if(n < 1  || n > 1000 || pW == NULL || pM == NULL) return 0;
  memset(dp, 0, sizeof(dp));
  // memset(sq, 0, sizeof(sq));
  memset(num, 0, sizeof(num));
  pw = pW;
  pm = pM;
  dp[n-1] = pW[n-1];
  // sq[n-1] = n-1;
  for(int i=n-2; i>=0; --i)
      DP(i , n);
  int maxnum = 0;
  for(int i=0; i<n; ++i)
    if(maxnum < num[i]) maxnum = num[i];

  // for(int i=0; i<n; ++i)
  //   cout<<num[i]<<' ';
  // cout<<endl;
  // for(int i=0; i<n; ++i)
  //   cout<<dp[i]<<' ';
  // cout<<endl;

  return maxnum+1;
}
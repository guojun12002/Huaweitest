/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2009/10/10
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2009/10/10
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int MAX = 1000;

/*****************************************************************************
Description  : 两个任意长度的正数相减
Prototype    : int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult)
Input Param  : const char *pMinuend     被减数，以\0表示字符串结束
               const char *pSubtrahend  减数，以\0表示字符串结束
Output       : char **ppResult          减法结果，必须以\0表示字符串结束
Return Value : 成功返回0   失败返回-1
*****************************************************************************/

void re(char* s)
{
  int l = strlen(s);
  for(int i=0; i<l/2; ++i)
  {
    char c = s[i];
    s[i] = s[l-1-i];
    s[l-1-i] = c;
  }
}
void cpy(char* s1, char* s2, const char* str)
{
  while(*str != '.' && *str != '\0')
  {
    *s1 = *str;
    ++s1;
    ++str;
  }
  *s1 = '\0';
  if(*str == '.')
  {
    ++str;
    while(*str != '\0')
    {
      *s2 = *str;
      ++s2;
      ++str;
    }
  }
  *s2 = '\0';
}
void push0(char* s, int n)
{
  for(int i=strlen(s); i<n; ++i)
    s[i] = '0';
  s[n] = '\0';
}
int comp(char *a1, char* a2, char* b1, char* b2)
{
  int l1, l2;
  l1 = strlen(b1);
  l2 = strlen(b2);
  if(l1 > l2) push0(b2, l1);
  else if(l1 < l2) push0(b1, l2);

  l1 = strlen(a1);
  l2 = strlen(a2);
  if(l1 > l2) return 1;
  else if(l1 < l2) return -1;
  else
    while(*a1 != '\0')
    {
      if(*a1 > *a2) return 1;
      else if(*a1 < *a2) return -1;
      ++a1;
      ++a2;
    }
  while(*b1 != '\0')
  {
    if(*b1 > *b2) return 1;
    else if(*b1 < *b2) return -1;
    ++b1;
    ++b2;
  }
  return 0;
}
int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult)
{

    /* 在这里实现功能 */
  if(NULL == pMinuend || NULL == pSubtrahend || pMinuend[0] == '\0' || pSubtrahend[0] == '\0' || pMinuend[0] == '.' || pSubtrahend[0] == '.') return -1;
  *ppResult = (char*)malloc(sizeof(char)*MAX);
  char* res = *ppResult;
  char a1[MAX], a2[MAX], b1[MAX], b2[MAX];
  cpy(a1, a2, pMinuend);  //a1.a2
  cpy(b1, b2, pSubtrahend); //b1.b2
  // cout << a1 << '.' << a2 << ' '<< b1 << '.' << b2 << endl;
  int positive = comp(a1, b1, a2, b2);
  // cout << a1 << '.' << a2 << ' '<< b1 << '.' << b2 << endl;
  // cout<<positive<<endl;
  if(positive == 0)
    strcpy(res, "0");
  else
  {
    if(positive < 0)
    {
      char tmp[MAX];
      strcpy(tmp, a1);
      strcpy(a1, b1);
      strcpy(b1, tmp);
      strcpy(tmp, a2);
      strcpy(a2, b2);
      strcpy(b2, tmp);
    }
    re(a1);
    re(a2);
    re(b1);
    re(b2);
    int i;
    int c = 0; //借位
    for(i=0; i<strlen(b2); ++i)
    {
      res[i] = a2[i] - b2[i] + '0' - c;
      if(res[i] < '0')
      {
        res[i] += 10;
        c = 1;
      }
      else
        c = 0;
    }
    res[i++] = '.';
    int j;
    for(j=0; j<strlen(b1); ++j)
    {
      res[i] = a1[j] - b1[j] - c + '0';
      if(res[i] < '0')
      {
        res[i] += 10;
        c = 1;
      }
      else
        c = 0;
      ++i;
    }
    for(; j<strlen(a1); ++j)
    {
      res[i] = a1[j] - c;
      if(res[i] < '0')
      {
        res[i] += 10;
        c = 1;
      }
      else
        c = 0;
      ++i;
    }
    res[i] = '\0';
    char* s = res;
    while(*s == '0')
      ++s;
    if(*s == '.')
      ++s;
    strcpy(res, s);
    re(res);
    s = res;
    while(*s == '0')
      ++s;
    if(*s == '.')
      --s;
    strcpy(res, s);
  // cout << a1 << '.' << a2 << ' '<< b1 << '.' << b2 << endl;
  // cout<<positive<<endl;
  // cout<<res<<endl;
  }
  if(positive < 0)
  {
    re(res);
    int lr = strlen(res);
    res[lr++] = '-';
    res[lr] = '\0';
    re(res);
  }
  return 0;
}


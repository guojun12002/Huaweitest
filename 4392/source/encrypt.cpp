/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2012/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2012/03/12
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
//1、对输入的字符串进行加解密，并输出。
//
//2加密方法为：
//当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
//当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
//其他字符不做变化。
//
//3、解密方法为加密的逆过程。


int Encrypt (char result[], char password[])
{
	/* 代码在这里实现 */
  if(password == NULL || result == NULL) return 0;
  int len = strlen(result);
  for(int i=0; i<len; ++i)
    if(isdigit(result[i]))
    {
      int num = result[i] - '0';
      num = (num + 1) % 10;
      password[i] = num + '0';
    }
    else if(isalpha(result[i]))
    {
      if(result[i] >= 'a' && result[i] < 'z')
        password[i] = toupper(result[i]) + 1;
      else if(result[i] == 'z')
        password[i] = 'A';
      else if(result[i] >= 'A' && result[i] < 'Z')
        password[i] = tolower(result[i]) + 1;
      else if(result[i] == 'Z')
        password[i] = 'a';
    }
    else
      password[i] = result[i];
  password[len] = '\0';
	return 0;
}

int unEncrypt (char password[],char result[])
{
	/* 代码在这里实现 */
  if(result == NULL || NULL == password) return 0;
  int len = strlen(password);
  for(int i=0; i<len; ++i)
    if(isdigit(password[i]))
    {
      int num = password[i] - '0';
      num = (num + 10 - 1) % 10;
      result[i] = num + '0';
    }
    else if(isalpha(password[i]))
    {
      if(password[i] > 'a' && password[i] <= 'z')
        result[i] = toupper(password[i]) - 1;
      else if(password[i] == 'a')
        result[i] = 'Z';
      else if(password[i] > 'A' && password[i] <= 'Z')
        result[i] = tolower(password[i]) - 1;
      else if(password[i] == 'A')
        result[i] = 'z';
    }
    else
      result[i] = password[i];
  result[len] = '\0';
	return 0;
}



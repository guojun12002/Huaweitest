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
//1����������ַ������мӽ��ܣ��������
//
//2���ܷ���Ϊ��
//��������Ӣ����ĸʱ���ø�Ӣ����ĸ�ĺ�һ����ĸ�滻��ͬʱ��ĸ�任��Сд,����ĸaʱ���滻ΪB����ĸZʱ���滻Ϊa��
//������������ʱ��Ѹ����ּ�1����0�滻1��1�滻2��9�滻0��
//�����ַ������仯��
//
//3�����ܷ���Ϊ���ܵ�����̡�


int Encrypt (char result[], char password[])
{
	/* ����������ʵ�� */
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
	/* ����������ʵ�� */
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



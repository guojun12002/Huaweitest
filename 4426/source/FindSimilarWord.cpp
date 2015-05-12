/******************************************************************************

  Copyright (C), 2001-2012, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : FindSimilarWord.cpp
  Version       :
  Author        :
  Created       : 2012/09
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2012/09
    Author      :
    Modification: Created file

******************************************************************************/

/******************************************************************************
ԭ    �ͣ�int AddOneWord (char* Word);
��    �ܣ����ֵ�������һ������
��������� 
          Word �����ַ����������߱�֤Wordָ�벻Ϊ�գ�ָ����ǺϷ�����
���������
          ��
����ֵ��
        -1 ʧ�ܣ��������ֵ����Ѵ��ڵ������
        0  �ɹ�
********************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

set<string> brother;
vector<string> dic;
int AddOneWord (char* Word)
{
    /* ������ʵ�ֹ��� */
  if(NULL == Word || Word[0] == '\0') return -1;
  string word = Word;
  for(int i=0; i<dic.size(); ++i)
    if(dic[i] == word) return -1;
  dic.push_back(word);
  return 0;
}
bool isSimlar(string s1, string s2)
{
  if(s1 == s2 || s1.length() != s2.length()) return false;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  return s1 == s2;
}
/******************************************************************************
ԭ    �ͣ�int FindSimilarWordNum (char* Word);
��    �ܣ�����ָ���������ֵ��е��ֵܵ��ʸ���
���������
          Word ָ�������ַ����������߱�֤Wordָ�벻Ϊ�գ�ָ����ǺϷ�����
���������
          ��
����ֵ��
          ����ָ���������ֵ��е��ֵܵ����ܸ���������������ֵܵ��ʣ�����0
*******************************************************************************/
int FindSimilarWordNum (char* Word)
{
  if(NULL == Word || Word[0] == '\0') return 0;
  string word = Word;
  brother.clear();
    /* ������ʵ�ֹ��� */
  int num = 0;
  for(int i=0; i<dic.size(); ++i)
    if(isSimlar(word, dic[i]))
    {
      ++num;
      brother.insert(dic[i]);
    }
    return num;
}

/******************************************************************************
ԭ    �ͣ�int FindOneSimilarWord (char* Word, int Seq, char* SimilarWord);
��    �ܣ�����ָ�����ʵ�ָ����ŵ��ֵܵ��ʣ�ָ�����ָ�ֵ����ֵܵ��ʰ��ֵ�˳��
          ��������ţ���1��ʼ��
���������
          Word ָ�������ַ����������߱�֤Wordָ�벻Ϊ�գ�ָ����ǺϷ�����
          Seq ָ����ţ����ڵ���1��
���������
          SimilarWord �����ֵܵ����ַ�����ָ�벻Ϊ�գ�ָ����ڴ��ɵ�����Ԥ�ȷ��䣬
          ռ51���ֽڳ��ȣ�������ֵܵ��ʱ��������\0�����������������ָ����ŵ�
          �ֵܵ��ʣ�����մ���
����ֵ��
          -1 ʧ�ܣ����������ָ����ŵ��ֵܵ��ʣ�����ʧ�ܣ�
          0  �ɹ�
*******************************************************************************/
int FindOneSimilarWord (char* Word, int Seq, char* SimilarWord)
{
    /* ������ʵ�ֹ��� */
  SimilarWord[0] = '\0';
  if(NULL == Word || Word[0] == '\0' || NULL == SimilarWord || Seq == 0) return -1;
  int num = FindSimilarWordNum(Word);
  if(Seq > num) return -1;
  set<string>::iterator it = brother.begin();
  while(--Seq > 0) ++it;
  strcpy(SimilarWord, it->c_str());
  return 0;
}

/******************************************************************************
ԭ    �ͣ�void ClearAllWords(void);
��    �ܣ�����ֵ������е���
��������� 
          ��
���������
          ��
����ֵ��
          ��

*******************************************************************************/
void ClearAllWords(void)
{
    /* ������ʵ�ֹ��� */
  dic.clear();
  brother.clear();
  return;
}

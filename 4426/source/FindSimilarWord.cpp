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
原    型：int AddOneWord (char* Word);
功    能：在字典中增加一个单词
输入参数： 
          Word 单词字符串，调用者保证Word指针不为空，指向的是合法单词
输出参数：
          无
返回值：
        -1 失败（单词在字典中已存在等情况）
        0  成功
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
    /* 在这里实现功能 */
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
原    型：int FindSimilarWordNum (char* Word);
功    能：查找指定单词在字典中的兄弟单词个数
输入参数：
          Word 指定单词字符串，调用者保证Word指针不为空，指向的是合法单词
输出参数：
          无
返回值：
          返回指定单词在字典中的兄弟单词总个数。如果不存在兄弟单词，返回0
*******************************************************************************/
int FindSimilarWordNum (char* Word)
{
  if(NULL == Word || Word[0] == '\0') return 0;
  string word = Word;
  brother.clear();
    /* 在这里实现功能 */
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
原    型：int FindOneSimilarWord (char* Word, int Seq, char* SimilarWord);
功    能：查找指定单词的指定序号的兄弟单词，指定序号指字典中兄弟单词按字典顺序
          排序后的序号（从1开始）
输入参数：
          Word 指定单词字符串，调用者保证Word指针不为空，指向的是合法单词
          Seq 指定序号（大于等于1）
输出参数：
          SimilarWord 返回兄弟单词字符串，指针不为空，指向的内存由调用者预先分配，
          占51个字节长度，输出的兄弟单词必须紧跟’\0’结束。如果不存在指定序号的
          兄弟单词，输出空串。
返回值：
          -1 失败（如果不存在指定序号的兄弟单词，返回失败）
          0  成功
*******************************************************************************/
int FindOneSimilarWord (char* Word, int Seq, char* SimilarWord)
{
    /* 在这里实现功能 */
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
原    型：void ClearAllWords(void);
功    能：清空字典中所有单词
输入参数： 
          无
输出参数：
          无
返回值：
          无

*******************************************************************************/
void ClearAllWords(void)
{
    /* 在这里实现功能 */
  dic.clear();
  brother.clear();
  return;
}

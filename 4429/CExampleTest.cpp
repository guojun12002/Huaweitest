/******************************************************************************

  Copyright (C), 2001-2012, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
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
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>

extern int AddOneWord (char* Word);
extern int FindSimilarWordNum (char* Word);
extern int FindOneSimilarWord (char* Word, int Seq, char* SimilarWord);
extern void ClearAllWords(void);

// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// 测试用例实现示例
char *Test_Word[7] = {
    "mock",
    "aabc",
    "abc",
    "ckom",
    "bcaa",
    "abca",};

// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{
}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{
    ClearAllWords();
}

void CExampleTest::TestCase01()
{
    AddOneWord(Test_Word[0]);
    AddOneWord(Test_Word[1]);
    AddOneWord(Test_Word[2]);
    AddOneWord(Test_Word[3]);
    AddOneWord(Test_Word[4]);
    AddOneWord(Test_Word[5]);

    int Expectnumber = 1;
    int ActualNumber;
    int Ret;

    ActualNumber = FindSimilarWordNum (Test_Word[0]);
    CPPUNIT_ASSERT(Expectnumber == ActualNumber);

    char *ExpectWord = {"bcaa"};
    char SimilarWord[51] = {'\0'};
    int Seq = 2;
    Ret = FindOneSimilarWord (Test_Word[1], Seq, SimilarWord);
    CPPUNIT_ASSERT(0 == Ret);
    CPPUNIT_ASSERT(!memcmp(ExpectWord, SimilarWord, strlen(ExpectWord) + 1));
}

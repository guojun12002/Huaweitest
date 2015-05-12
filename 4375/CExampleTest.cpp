/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2010/9/1
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2010/9/1
    Author      :
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>

extern void PolynomialMultiple (char* InputString1, char* InputString2, char* OutputString);

// ע������׵�CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// ��������ʵ��ʾ��

// SetUp: ��ÿ������ǰִ��һ��
void CExampleTest::setUp()
{

}

// tearDown: ��ÿ��������ִ��һ��
void CExampleTest::tearDown()
{

}

void CExampleTest::TestCase01()
{
    char *InputString1 = "7X^4";
    char *InputString2 = "-7X^4";
    char *OutputString = NULL;

    OutputString = (char*)malloc(40000);
    memset(OutputString,0,40000);

    PolynomialMultiple(InputString1,InputString2,OutputString);
    
    CPPUNIT_ASSERT(strcmp(OutputString, "-49X^8") == 0);

    free(OutputString);
}



// ��������Ӳ�������ʵ��
// void CExampleTest::TestCasexx()
// {
//
// }

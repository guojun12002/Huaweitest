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

extern void OrderPolynomial (char* InputString, char* OutputString);

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
    char *InputString = "7X^4-5X^6+3X^3";
    char *OutputString = NULL;

    OutputString = (char*)malloc(strlen(InputString)+2);
    memset(OutputString,0,strlen(InputString)+2);

    OrderPolynomial(InputString,OutputString);
    
    CPPUNIT_ASSERT(strcmp(OutputString, "-5X^6+7X^4+3X^3") == 0);

    free(OutputString);
}



// ��������Ӳ�������ʵ��
// void CExampleTest::TestCasexx()
// {
//
// }

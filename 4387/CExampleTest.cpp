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
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"

int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult);


 //ע������׵�CppUnit
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


// ����1:
void CExampleTest::TestCase01()
{
    const char * pMinuend = "85";
    const char * pSubtrahend = "79";
    char * pResult = NULL;
    Decrease(pMinuend, pSubtrahend, &pResult);
    CPPUNIT_ASSERT(pResult != NULL);
    CPPUNIT_ASSERT(strcmp(pResult, "6") == 0);
    free(pResult);
}


// ����2:
void CExampleTest::TestCase02()
{
    const char * pMinuend = "8.5";
    const char * pSubtrahend = "0.91";
    char * pResult = NULL;
    Decrease(pMinuend, pSubtrahend, &pResult);
    CPPUNIT_ASSERT(pResult != NULL);
    CPPUNIT_ASSERT(strcmp(pResult, "7.59") == 0);
    free(pResult);
}

// ����3:
void CExampleTest::TestCase03()
{
    const char * pMinuend = "8.5";
    const char * pSubtrahend = "7.5";
    char * pResult = NULL;
    Decrease(pMinuend, pSubtrahend, &pResult);
    CPPUNIT_ASSERT(pResult != NULL);
    CPPUNIT_ASSERT(strcmp(pResult, "1") == 0);
    free(pResult);
}

// ����4:
void CExampleTest::TestCase04()
{
    const char * pMinuend = "12.34";
    const char * pSubtrahend = "17.24";
    char * pResult = NULL;
    Decrease(pMinuend, pSubtrahend, &pResult);
    CPPUNIT_ASSERT(pResult != NULL);
    CPPUNIT_ASSERT(strcmp(pResult, "-4.9") == 0);
    free(pResult);
}





// ��������Ӳ�������ʵ��
// void CExampleTest::TestCasexx()
// {
//
// }


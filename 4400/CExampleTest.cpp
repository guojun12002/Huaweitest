/******************************************************************************

  Copyright (C), 2001-2012, Huawei Tech. Co., Ltd.

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
#include <string.h>
#include "OJ.h"

extern void addStr(char *str1, char *str2, char *result);
extern void multiStr(char *str1, char *str2, char *result);
extern void CalcNN(int n, char *pOut);


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
    char *p;

    p = (char *)malloc(1000);
    CalcNN(13, p);
    CPPUNIT_ASSERT(0 == strcmp(p, "6227020800"));
    free(p);
}


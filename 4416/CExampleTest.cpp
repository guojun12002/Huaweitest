/******************************************************************************

  Copyright (C), 2001-2012, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2012/3
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2012/3
    Author      :
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include <stdlib.h>
#include "oj.h"
#include "CExampleTest.h"





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
    int a[] = {2,1};
	char szRst[10]  = {0};
    char *strExpect = "12";
	smallestDigit(a,2,szRst);
    CPPUNIT_ASSERT(0 == strcmp(szRst,strExpect));
}

// ��������Ӳ�������ʵ��
// void CExampleTest::TestCasexx()
// {
//
// }

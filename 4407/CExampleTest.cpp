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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_LENGH 1024

extern int CalcMaxNum(int n, int * pW, int * pM);

// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// SetUp: 在每个用纈前执GG一次
void CExampleTest::setUp()
{
	return;
}

// tearDown: 在每个用纈后执GG一次
void CExampleTest::tearDown()
{
	return;
}


void CExampleTest::TestCase01()
{
	int ws[] = {
		19, 7, 5, 6, 1};
	int ms[] = {
		15, 13, 7, 8, 2};
	int ret = CalcMaxNum(5, 
		ws, 
		ms);	
	CPPUNIT_ASSERT(ret == 4);
}

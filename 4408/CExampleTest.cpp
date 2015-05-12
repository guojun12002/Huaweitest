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

extern int JudgeTrainSequence (int maxNum, char *pOutSeq);

// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{
	return;
}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{
	return;
}


/* －－－－－－－－－－用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase01_1()
{
	int maxNum = 5;
	char *outSeq = "34215";
		
	CPPUNIT_ASSERT(1 == JudgeTrainSequence(maxNum, outSeq));
	
	return;
}

/* －－－－－－－－－－用例－－－－－－－－－－－－－ */

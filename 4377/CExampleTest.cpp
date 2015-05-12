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
#include "OJ.h"

// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// 测试用例实现示例

// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{

}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{

}


void CExampleTest::TestCase01()
{
	char *input[] = {"10 10 10 10 10 10 9 xiaoyuanwang"};
	char result[100] = {0};
	GetResult(input, 1, result);	
	CPPUNIT_ASSERT(0 == strcmp(result, "xiaoyuanwang 10.00") );
}



void CExampleTest::TestCase02()
{
	char *input[] = {"10 10 10 10 10 10 9 xiaoyuanwang","0 0 0 0 0 0 0 beast"};
	char result[100] = {0};
	GetResult(input, 2, result);
	CPPUNIT_ASSERT(0 == strcmp(result, "xiaoyuanwang 10.00\nbeast 0.00") );
}


// 在这里添加测试用例实现
// void CExampleTest::TestCasexx()
// {
//
// }

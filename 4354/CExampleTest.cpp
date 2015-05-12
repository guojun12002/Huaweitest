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
	int a[6][2] = {{1000,5},{800,2},{400,5},{300,5},{400,3},{200,2}} ;
	int *p = &a[0][0];
	int GetNumber = 0;
	GetResult(p,GetNumber);
	CPPUNIT_ASSERT(3900 == GetNumber);
}
void CExampleTest::TestCase02()
{
	int a[16][2] = {{4000,15},{821,3},{422,5},{458,5},{500,3},{200,2},{430,4},{530,3},{239,3},{630,4},{500,2},{220,3},{430,3},{400,5},{400,5},{500,3}};
	int *p = &a[0][0];
	int GetNumber = 0;
	GetResult(p,GetNumber);
	CPPUNIT_ASSERT(16393 == GetNumber);
}

// 在这里添加测试用例实现
// void CExampleTest::TestCasexx()
// {
//
// }

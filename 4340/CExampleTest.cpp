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
#include <math.h>
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
	double Ret;
	int M = 4;
	int N = 20;
	int paper_type_value[][2] = {{4,10},{5,22},{10,3},{1,2}};
	GetMaxValue(M, N,paper_type_value, &Ret);

	CPPUNIT_ASSERT(abs(37.00 - Ret) <= 0.01);
}


// 在这里添加测试用例实现
// void CExampleTest::TestCasexx()
// {
//
// }

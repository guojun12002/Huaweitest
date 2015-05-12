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
	int iRet = 0;
	std::string  sExpectedResult("30");
	std::string strResult = "";

    iRet = multiply("5", "6", strResult);
    CPPUNIT_ASSERT_EQUAL(0, iRet);
	CPPUNIT_ASSERT_EQUAL(sExpectedResult,strResult);
}
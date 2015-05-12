/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech  Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       :
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 
    Author      :
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>

#include "Degressive.h"


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
	CPPUNIT_ASSERT(getMaxDegressiveNum(95345323)==953);

}



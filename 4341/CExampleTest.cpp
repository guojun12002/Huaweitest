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
	int InMinSeq = 2;
    int InMaxSeq = 10;
    int InNumbLen = 5;
	char InChaStr[30] = "bdfij";

	char pBufOutData[1024] = {0};

    GetResult(InMinSeq, InMaxSeq, InNumbLen, InChaStr, pBufOutData);

	CPPUNIT_ASSERT(0 == strcmp( pBufOutData,"bdghi\nbdghj\nbdgij\nbdhij\nbefgh"));
}


// 在这里添加测试用例实现
// void CExampleTest::TestCasexx()
// {
//
// }

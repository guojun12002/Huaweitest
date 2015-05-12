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
	ELEMENT_STRU  astElement[2];
	unsigned int  uiIutputLen;
	unsigned char aucIutput[2];
	
	uiIutputLen = 2;
	aucIutput[0] = 0x62;
	aucIutput[1] = 0x80;

	astElement[0].uiElementLength = 4;
	astElement[1].uiElementLength = 5;

	Decode(uiIutputLen, aucIutput, 2, astElement);

	CPPUNIT_ASSERT(astElement[0].uiElementValue == 6);
	CPPUNIT_ASSERT(astElement[1].uiElementValue == 5);
}

// 在这里添加测试用例实现
// void CExampleTest::TestCasexx()
// {
//
// }

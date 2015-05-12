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
#include <string.h>
#include "OJ.h"

using namespace std;


// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// 测试用例实现示例

// SetUp: 在每个用例前执行一次

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
	SetPlayerNum(4);
	unsigned int nResult = GetPlayerOut(1);
	CPPUNIT_ASSERT(3 == nResult);

	nResult = GetPlayerOut(4);
	CPPUNIT_ASSERT(4 == nResult);

	nResult = GetPlayerOut(16);
	CPPUNIT_ASSERT(2 == nResult);

	nResult = GetPlayerOut(6);
	CPPUNIT_ASSERT(1 == nResult);


	GameOver();
}
void CExampleTest::TestCase02()
{
	SetPlayerNum(1);
	unsigned int nResult = GetPlayerOut(9999);
	CPPUNIT_ASSERT(1 == nResult);


	GameOver();
}
void CExampleTest::TestCase03()
{
	SetPlayerNum(4);
	CPPUNIT_ASSERT (3 == GetPlayerOut (8)); 
	CPPUNIT_ASSERT (4 == GetPlayerOut (4)); 
	CPPUNIT_ASSERT (2 == GetPlayerOut (16)); 
	CPPUNIT_ASSERT (1 == GetPlayerOut (2)); 

	GameOver();
}

void CExampleTest::TestCase04()
{
	SetPlayerNum(30);
	CPPUNIT_ASSERT (2 == GetPlayerOut (69)); 
	CPPUNIT_ASSERT (4 == GetPlayerOut (699)); 
	CPPUNIT_ASSERT (6 == GetPlayerOut (1399)); 
	GameOver();
}
void CExampleTest::TestCase05()
{
	SetPlayerNum(8);
	CPPUNIT_ASSERT (7 == GetPlayerOut (1)); 
	CPPUNIT_ASSERT (1 == GetPlayerOut (16)); 
	GameOver();
}

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
	unsigned horse_num=5;
	unsigned int speed_yanzi[]={2,3,3,4,5};
	unsigned int speed_opp[]={1,2,3,4,5};
	char* aResult=IsYuanziWin(horse_num,speed_yanzi,speed_opp);

	CPPUNIT_ASSERT(strcmp(aResult,"YES")==0);
}


// 在这里添加测试用例实现
 void CExampleTest::TestCase02()
 {
	 unsigned horse_num=4;
	 unsigned int speed_yanzi[]={2,2,1,2};
	 unsigned int speed_opp[]={2,2,3,1};
	 char * aResult=IsYuanziWin(horse_num,speed_yanzi,speed_opp);

	 CPPUNIT_ASSERT(strcmp(aResult,"NO")==0);


 }













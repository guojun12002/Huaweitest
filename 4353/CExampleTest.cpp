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

extern int matrix(int **MatrixA, int **MatrixB, int **MatrixC, int N);


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
	int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int C[3][3], ExpectC[3][3] = {{30, 36, 42}, {66, 81, 96}, {102, 126, 150}};

	matrix((int**)A, (int**)A, (int**)C, 3);

	CPPUNIT_ASSERT(0 == memcmp(C, ExpectC, sizeof(C)));
}


void CExampleTest::TestCase02()
{	
	
}


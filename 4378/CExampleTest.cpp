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

// ע������׵�CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// ��������ʵ��ʾ��

// SetUp: ��ÿ������ǰִ��һ��
void CExampleTest::setUp()
{

}

// tearDown: ��ÿ��������ִ��һ��
void CExampleTest::tearDown()
{

}


void CExampleTest::TestCase01()
{
	int N = 4;
	int M = 4; 
	int T = 10;
	char a[4][4] = {'.', '.', '.','.', '.', '.', '.', '.', '.', '.', '.', '.','S', '*', '*','P'};
    char *p = &a[0][0];
	int  Ret;

	Ret = SSavep(p, T, N, M);

	CPPUNIT_ASSERT(Ret == 0);
}

// ��������Ӳ�������ʵ��
// void CExampleTest::TestCasexx()
// {
//
// }

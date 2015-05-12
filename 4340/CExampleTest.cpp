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
	double Ret;
	int M = 4;
	int N = 20;
	int paper_type_value[][2] = {{4,10},{5,22},{10,3},{1,2}};
	GetMaxValue(M, N,paper_type_value, &Ret);

	CPPUNIT_ASSERT(abs(37.00 - Ret) <= 0.01);
}


// ��������Ӳ�������ʵ��
// void CExampleTest::TestCasexx()
// {
//
// }

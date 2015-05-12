/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2013/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2003/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern bool Game24Points(int, int, int, int);

// ע������׵�CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// SetUp: ��ÿ������ǰִ��һ��
void CExampleTest::setUp()
{
	return;
}

// tearDown: ��ÿ��������ִ��һ��
void CExampleTest::tearDown()
{
	return;
}

/* �������������������������������������������������� */
void CExampleTest::TestCase01_1()
{
	return CPPUNIT_ASSERT(Game24Points(7, 2, 1, 10) == true);
}

void CExampleTest::TestCase01_2()
{
	return CPPUNIT_ASSERT(Game24Points(1, 2, 3, 4) == true);
}

void CExampleTest::TestCase01_3()
{
	return CPPUNIT_ASSERT(Game24Points(7, 7, 7, 7) == false);
}

/* �������������������������������������������������� */
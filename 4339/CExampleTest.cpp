/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2009/10/10
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2009/10/10
    Author      : 
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include "OJ.h"

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
    int result = 0;

    result = GetExtFibonacci(-1,1,1);
	CPPUNIT_ASSERT(-1 == result);

}
/* �������������������������������������������������� */
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
	CPPUNIT_ASSERT(getMaxDegressiveNum(95345323)==953);

}



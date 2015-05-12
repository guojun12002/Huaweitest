/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2011/3
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2011/3
    Author      :
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>

#include "..\source\CellularDistrict.h"


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
	Clear();
}

void CExampleTest::TestCase01()
{
    InitCellularDistrict(60);
 	CPPUNIT_ASSERT(GetShortestPathLength(19, 30) == 5);
}

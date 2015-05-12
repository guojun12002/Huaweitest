/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2013/03
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2013/03
    Author      :
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>

#include "SliceIterator.h"

// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );


// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{
}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{
    
}

//以下用例仅供参考
void CExampleTest::TestCase01()
{
	int A[10][10][3];
	int total = 0;
	int new_total = 0;

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<3;k++)
	{
		A[i][j][k] = i*j*k;
		total += A[i][j][k];
	}

	SliceIterator slice_iterator;
	SliceDesc slice_desc = {&A[0][0][0],3,{9,9,2},{{2,4},{0,6},{1,2}}};

	for(SliceIteratorInit(&slice_desc,&slice_iterator);1!=SliceIteratorEnd(&slice_iterator);SliceIteratorNext(&slice_iterator) )
	{
		*SliceIteratorGetCurr(&slice_iterator) += 1;
	}


	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<3;k++)
	{
		new_total += A[i][j][k];
	}

	CPPUNIT_ASSERT(new_total > total);

}

void CExampleTest::TestCase02()
{
	int A[10][10][3];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<3;k++)
	{
		A[i][j][k] = 1;
	}

	SliceDesc slice_desc = {&A[0][0][0],3,{9,9,2},{{2,4},{0,6},{1,2}}};
	int* first_element_of_slice_array = NULL;
	unsigned long slice_element_num = 0;

	int ret = CopySlice(&slice_desc,&first_element_of_slice_array,&slice_element_num);

	CPPUNIT_ASSERT(0 == ret);
	for(int i=0;i<slice_element_num; i++)
	{
		CPPUNIT_ASSERT(1 == first_element_of_slice_array[i]);
	}
	free(first_element_of_slice_array);
}

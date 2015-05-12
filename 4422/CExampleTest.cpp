/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2010/03/12
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2010/03/12
    Author      :
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>

extern void AddLine(unsigned int LineNo, unsigned int StationNum ,unsigned  int *pStationArray);
extern int CalcMinPathLen(unsigned int SrcStation, unsigned int DesStation);
extern int SearchMinPathes(unsigned int SrcStation,
                           unsigned int DesStation,
                           unsigned int* pPathNum,
                           unsigned int* pPathLen,
                           unsigned int **ppPathes);
extern int SearchBestPathes(unsigned int SrcStation,
                            unsigned int DesStation,
                            unsigned int *pPathNum,
                            unsigned int* pPathLen,
                            unsigned int** ppPathes);
extern void Clear();


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
    unsigned int Line1[] = {1,2,3,4,5};
    int Ret;

    AddLine(1,5,&Line1[0]);

    Ret = CalcMinPathLen(2,4);
    CPPUNIT_ASSERT(2 == Ret);

    Clear();
}



// 在这里添加测试用例实现
// void CExampleTest::TestCasexx()
// {
//
// }

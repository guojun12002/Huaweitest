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
    unsigned int Line1[] = {1,2,3,4,5};
    int Ret;

    AddLine(1,5,&Line1[0]);

    Ret = CalcMinPathLen(2,4);
    CPPUNIT_ASSERT(2 == Ret);

    Clear();
}



// ��������Ӳ�������ʵ��
// void CExampleTest::TestCasexx()
// {
//
// }

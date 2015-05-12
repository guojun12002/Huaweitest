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
    char result[128] = {0};
    BiNode dataa = {'a', NULL, NULL};
    BiNode datab = {'b', NULL, NULL};
    BiNode datac = {'c', NULL, NULL};
    BiNode datad = {'d', NULL, NULL};
    BiNode datae = {'e', NULL, NULL};
    BiNode dataf = {'f', NULL, NULL};
    BiNode datag = {'g', NULL, NULL};
    BiNode datah = {'h', NULL, NULL};
    BiNode datai = {'i', NULL, NULL};
    BiNode dataj = {'j', NULL, NULL};
    BiNode datak = {'k', NULL, NULL};
    BiNode datal = {'l', NULL, NULL};
    BiNode datam = {'m', NULL, NULL};
    BiNode datan = {'n', NULL, NULL};
    BiNode datao = {'o', NULL, NULL};
    BiNode datap = {'p', NULL, NULL};

    dataa.left = &datab;
    dataa.right = &datac;
    datab.left = &datad;
    datab.right = &datae;
    datac.left = &dataf;
    datac.right = &datag;
    datad.left = &datah;
    datad.right = &datai;
    datae.left = &dataj;
    datae.right = &datak;
    dataf.left = &datal;
    dataf.right = &datam;
    datag.left = &datan;
    datag.right = &datao;
    datah.left = &datap;

    unsigned int ulWidth = 0;
    unsigned int ulHeight = 0;
    CPPUNIT_ASSERT(GetBiNodeInfo(dataa, &ulWidth, &ulHeight) == 0);
    CPPUNIT_ASSERT(ulWidth == 8);
    CPPUNIT_ASSERT(ulHeight == 5);
}

void CExampleTest::TestCase02()
{
}

void CExampleTest::TestCase03()
{
}


// 在这里添加测试用例实现
// void CExampleTest::TestCasexx()
// {
//
// }

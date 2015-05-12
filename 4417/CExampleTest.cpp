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
#include <string.h>

extern int Calculate(const int iNumerator, const int iDenominator ,char *pucOut);


// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );


strNode *vCreatChan(int * piData, int iNum)
{
    int       iLoop         = 0;
    strNode * pstrChanHead  = NULL;
    strNode * pstrChanEnd   = NULL;
    strNode * pstTemp       = NULL;

    if ((NULL == piData) || (iNum < 1))
    {
        return NULL;
    }

    pstrChanHead = (strNode *)malloc(sizeof(strNode));
    pstrChanHead->data     = *piData;
    pstrChanHead->pstrNext = NULL;

    pstrChanEnd = pstrChanHead;

    for (iLoop = 1; iLoop < iNum; iLoop++)
    {
        pstTemp = (strNode *)malloc(sizeof(strNode));
        pstTemp->data = piData[iLoop];
        pstTemp->pstrNext = NULL;

        pstrChanEnd->pstrNext = pstTemp;
        pstrChanEnd = pstrChanEnd->pstrNext;
    }

    return pstrChanHead;
}

int iChanToArray(strNode *pstrChan, int * piData, int * piLenth)
{
    int      iLoop    = 0;
    strNode *pstrTemp = pstrChan;

    if ((NULL == pstrChan) || (NULL == piData) || (NULL == piLenth))
    {
        return -1;
    }

    while(NULL != pstrTemp)
    {
        *(piData + iLoop) = pstrTemp->data;
        pstrTemp = pstrTemp->pstrNext;
        iLoop++;
    }

    *piLenth = iLoop;

    return 0;
}

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
    /* TODO: 请测试时改变改用例 */
    strNode * pstrIn  = NULL;
    strNode * pstrOut = NULL;
    int  iLenth  = 0;
    int  iaDataIn[7]    = {6, 7, 8, 8 ,9, 10, 6};
    int  iaDataOut[7]   = {10,9,7};
    int  iaDataMyOut[7] = {0};

    pstrIn = vCreatChan(iaDataIn, 7);
    pstrOut = (strNode *)malloc(sizeof(strNode));
    pstrOut->pstrNext = NULL;
    /* TODO: 调用被测函数 */
	//请考生自己构造单向链表进行测试
    iChanProcess(pstrIn,pstrOut);

    /* TODO: 执行完成后可比较是否是你认为正确的值 */
    iChanToArray(pstrOut, iaDataMyOut, &iLenth);
    //printf("%d\n",pstrOut->data);
    CPPUNIT_ASSERT(3 == iLenth);
    CPPUNIT_ASSERT(0 == memcmp((char *)iaDataOut, (char *)iaDataMyOut, sizeof(int) * iLenth));

    /* 释放内存*/
    vFreeChan(pstrIn);
    vFreeChan(pstrOut);
}


// void CExampleTest::TestCase02()
// {
// 
// }



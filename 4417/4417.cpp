#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#include "source/oj.cpp"
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
void print(strNode* p)
{
	while(p !=NULL)
	{
		cout<<p->data<<' ';
		p = p->pstrNext;
	}
	cout<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	strNode * pstrIn  = NULL;
    strNode * pstrOut = NULL;
    int  iaDataIn[7]    = {6, 7, 8, 8 ,9, 10, 6};
    int  iaDataOut[7]   = {10,9,7};

    pstrIn = vCreatChan(iaDataIn, 7);
    print(pstrIn);
    pstrOut = (strNode *)malloc(sizeof(strNode));
    pstrOut->pstrNext = NULL;

    iChanProcess(pstrIn,pstrOut);
    print(pstrOut);
	return 0;
}
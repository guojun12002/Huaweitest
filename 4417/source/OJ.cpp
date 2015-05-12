#include <stdlib.h>
#include "oj.h"


/*
功能:  输入一个不带头节点的单向链表(链表的节点数小于100),删除链表中内容重复的节点（重复的节点全部删除），剩余的节点逆序倒排。
    
输入:   pstrIn： 输入一个不带头节点的单向链表
    
输出:   pstrOut：删除内容重复的节点后，逆序排列的链表(不带头节点,链表第一个节点的内存已经申请)。
     
返回:

示例:
输入链表的内容依次为 6,7,8,8,9,10,6
则输出链表的内容依次应该是 10,9,7
     
*/


int iChanProcess(strNode * pstrIn,strNode * pstrOut)
{
	if(NULL == pstrIn || NULL == pstrOut) return 0;
	int num[10000] = {};
	int fn[10000] = {};
	int n = 0;
	strNode* p = pstrIn;
	strNode* q = pstrOut;
	while(p != NULL)
	{
		num[n++] = p->data;
		++fn[p->data];
		p = p->pstrNext;
	}
	bool flag = false;
	for(int i=n-1; i>=0; --i)
		if(fn[num[i]] == 1)
		{
			if(flag)
			{
				q->pstrNext = (strNode*)malloc(sizeof(strNode));
				q = q->pstrNext;
				q->pstrNext = NULL;
			}
			q->data = num[i];
			flag = true;
		}
	return 1;
}

/* 释放链表 */
void vFreeChan(strNode * pstrChan)
{
    while(pstrChan != NULL)
    {
    	strNode* p = pstrChan;
    	pstrChan = pstrChan->pstrNext;
    	free(p);
    }
    return;
}

#include "OJ.h"

/*
功能: 输入一个升序单向链表和一个链表节点，向单向链表中按升序插入这个节点。
	  输入为空指针的情况视为异常，另外不考虑节点值相等的情况。

输入: ListNode* pListHead  单向链表
      ListNode* pInsertNode 新插入节点
      
输出: ListNode* pListHead  单向链表

返回: 正常插入节点返回链表头指针，其它异常返回空指针
*/
ListNode* InsertNodeToList(ListNode* pListHead, ListNode* pInsertNode)
{
	/*在这里实现功能*/
    if(NULL == pListHead || NULL == pInsertNode) return NULL;
    ListNode* p = pListHead;
    while(p != NULL)
    	if(p->m_nKey < pInsertNode->m_nKey)
    		if(p->m_pNext == NULL || p->m_pNext->m_nKey >= pInsertNode->m_nKey)
    		{
    			pInsertNode->m_pNext = p->m_pNext;
    			p->m_pNext = pInsertNode;
    			break;
    		}
    		else
    			p = p->m_pNext;
    	else
    	{
    		pInsertNode->m_pNext = pListHead;
    		pListHead = pInsertNode;
    		break;
    	}
    return pListHead;
}


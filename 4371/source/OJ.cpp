
#include "OJ.h"

/*
����: ����һ�������������һ������ڵ㣬���������а������������ڵ㡣
	  ����Ϊ��ָ��������Ϊ�쳣�����ⲻ���ǽڵ�ֵ��ȵ������

����: ListNode* pListHead  ��������
      ListNode* pInsertNode �²���ڵ�
      
���: ListNode* pListHead  ��������

����: ��������ڵ㷵������ͷָ�룬�����쳣���ؿ�ָ��
*/
ListNode* InsertNodeToList(ListNode* pListHead, ListNode* pInsertNode)
{
	/*������ʵ�ֹ���*/
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


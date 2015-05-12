
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	ListNode astListNode[2];
	ListNode stInsertNode;
	ListNode *pListHead;

	astListNode[0].m_nKey = 1;
	astListNode[0].m_pNext = &astListNode[1];

	astListNode[1].m_nKey = 3;
	astListNode[1].m_pNext = NULL;

	stInsertNode.m_nKey = 0;
	stInsertNode.m_pNext = NULL;
	
	pListHead = InsertNodeToList(astListNode, &stInsertNode);
	ListNode* p = pListHead;
	while(p != NULL)
	{
		printf("%d ", p->m_nKey);
		p = p->m_pNext;
	}
	printf("\n");
	return 0;
}
#include <stdlib.h>
#include "oj.h"


/*
����:  ����һ������ͷ�ڵ�ĵ�������(����Ľڵ���С��100),ɾ�������������ظ��Ľڵ㣨�ظ��Ľڵ�ȫ��ɾ������ʣ��Ľڵ������š�
    
����:   pstrIn�� ����һ������ͷ�ڵ�ĵ�������
    
���:   pstrOut��ɾ�������ظ��Ľڵ���������е�����(����ͷ�ڵ�,�����һ���ڵ���ڴ��Ѿ�����)��
     
����:

ʾ��:
�����������������Ϊ 6,7,8,8,9,10,6
������������������Ӧ���� 10,9,7
     
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

/* �ͷ����� */
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
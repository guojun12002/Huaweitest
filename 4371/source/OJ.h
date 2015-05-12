#ifndef __OJ_H__
#define __OJ_H__
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
struct ListNode
{
      int       m_nKey;
      ListNode* m_pNext;
};

ListNode* InsertNodeToList(ListNode* pListHead, ListNode* pInsertNode);

#endif

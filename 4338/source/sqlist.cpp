/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2012/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2012/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#define null 0
#define MAXSIZE 50

struct strlnode
{
	int data;
	struct strlnode *plast;
	struct strlnode *pnext;
};

void create(struct strlnode **p, int x)  /*创建双链表(表头节点)*/
{
	struct strlnode *q;

	q = (struct strlnode *)malloc(sizeof(struct strlnode));
	q->data = x;
	q->plast = null;
	q->pnext = null;

	*p = q;

	return;
}

void insertnode(struct strlnode **p, int i, int x) /* 在链表第i个位置插入数据等于x的节点 */
{
	/* 代码在这里实现 */
	if(NULL == *p) return;
	strlnode* s = *p;
	if(i == 0)
	{
		create(&(s->plast), x);
		s->plast->pnext = s;
		*p = s->plast;
	}
	else
	{
		for(int j=1; j<i; ++j)
			if(s != NULL) s = s->pnext;
			else return;
		strlnode* q = s->pnext;
		create(&(s->pnext), x);
		s->pnext->plast = s;
		s->pnext->pnext = q;
		if(q != NULL) q->plast = s->pnext;
	}
	return;
}

void deletenode(struct strlnode **p, int i) /* 删除链表中第i个节点 */
{
	/* 代码在这里实现 */
	if(NULL == *p) return;
	strlnode* s = *p;
	if(i == 0)
	{
		*p = s->pnext;
		(*p)->plast = NULL;
		free(s);
	}
	else
	{
		for(int j=0; j<i; ++j)
			if(s != NULL) s = s->pnext;
			else return;
		strlnode* pre = s->plast;
		pre->pnext = s->pnext;
		if(s->pnext != NULL) s->pnext->plast = pre;
		free(s);
	}
	return;
}

int getnodenum(struct strlnode **p)  /*获取链表中节点个数*/
{
	int nodenum = 0;
	/* 代码在这里实现 */
	strlnode* s = *p;
	while(s != NULL)
	{
		++nodenum;
		s = s->pnext;
	}
	return nodenum;
}

void bignumberplus(struct strlnode **plus, struct strlnode **p, struct strlnode **q) /* 使用链表实现大整数相加 */
{
	/* 代码在这里实现 */
	if(NULL == *plus || NULL == *p || NULL == *q) return;
	strlnode* a1 = *p;
	strlnode* a2 = *q;
	while(a1->pnext != NULL) a1 = a1->pnext;
	while(a2->pnext != NULL) a2 = a2->pnext;
	(*plus)->data = (a1->data + a2->data) % 10;
	int c = (a1->data + a2->data) / 10;
	a1 = a1->plast;
	a2 = a2->plast;
	while(a1 !=NULL && a2 != NULL)
	{
		int n = a1->data + a2->data + c;
		c = n / 10;
		insertnode(plus, 0, n%10);
		a1 = a1->plast;
		a2 = a2->plast;
	}
	strlnode* a = (a1 ==NULL) ? a2 : a1;
	while(a != NULL)
	{
		int n = a->data + c;
		c = n / 10;
		insertnode(plus, 0, n%10);
		a = a->plast;
	}
	if(c > 0) insertnode(plus, 0, c);
	return;
}


void readtolnode(struct strlnode **p, int *a, int size)  /* 将数组写入链表中，链表中的数据的先后顺序和数组中的顺序要保持一致 */
{
	int j = 0;
	int data = 0;
	struct strlnode *s = *p;

	s->data = *(a + (size-1));

	for(j = 2; j < (size+1); j++)
	{
		data = *(a + (size-j));
		insertnode(p, 0, data);
	}

	return;
}


void writetosqlist(int *a, struct strlnode *p)  /* 将链表写入数组中，数组中的数据的先后顺序和链表中的顺序要保持一致 */
{
	int j = 0;
	struct strlnode *s = p;

	while(s != null)
	{
		*(a + j) = s->data;
		s = s->pnext;
		j++;
	}

	return;
}







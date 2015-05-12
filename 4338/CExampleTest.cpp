/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2009/10/10
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2009/10/10
    Author      : 
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>

#define null 0
#define MAXSIZE 50

struct strlnode
{
	int data;
	struct strlnode *plast;
	struct strlnode *pnext;
};

extern void create(struct strlnode **p, int x);
extern void insertnode(struct strlnode **p, int i, int x);
extern void deletenode(struct strlnode **p, int i);
extern int getnodenum(struct strlnode **p);
extern void bignumberplus(struct strlnode **plus, struct strlnode **p, struct strlnode **q);
extern void readtolnode(struct strlnode **p, int *a, int size);
extern void writetosqlist(int *a, struct strlnode *p);

// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{
	return;
}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{
	return;
}


/* －－－－－－－－－－链表创建类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase01_1()
{
	struct strlnode *p;

	create(&p, 1);

	CPPUNIT_ASSERT(p != null);
	CPPUNIT_ASSERT(p->data == 1);
	CPPUNIT_ASSERT(p->plast == null);
	CPPUNIT_ASSERT(p->pnext == null);
}
/* －－－－－－－－－－链表创建类用例－－－－－－－－－－－－－ */


/* －－－－－－－－－－在链表第i个位置插入数据等于x的节点类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase02_1()
{
	struct strlnode *p;

	create(&p, 1);
	insertnode(&p, 1, 2);
	insertnode(&p, 2, 3);
	insertnode(&p, 3, 4);

	insertnode(&p, 2, 5);

	CPPUNIT_ASSERT(p->data == 1);
	p = p->pnext;
	CPPUNIT_ASSERT(p->data == 2);
	p = p->pnext;
	CPPUNIT_ASSERT(p->data == 5);
	p = p->pnext;
	CPPUNIT_ASSERT(p->data == 3);
	p = p->pnext;
	CPPUNIT_ASSERT(p->data == 4);
	CPPUNIT_ASSERT(p->pnext == null);

	p = p->plast;
	CPPUNIT_ASSERT(p->data == 3);
	p = p->plast;
	CPPUNIT_ASSERT(p->data == 5);
	p = p->plast;
	CPPUNIT_ASSERT(p->data == 2);
	p = p->plast;
	CPPUNIT_ASSERT(p->data == 1);
	CPPUNIT_ASSERT(p->plast == null);

}
/* －－－－－－－－－－在链表第i个位置插入数据等于x的节点类用例－－－－－－－－－－－－－ */


/* －－－－－－－－－－删除链表中第i个节点类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase03_1()
{
	struct strlnode *p;

	create(&p, 1);
	insertnode(&p, 1, 2);
	insertnode(&p, 2, 3);
	insertnode(&p, 3, 4);

	deletenode(&p, 2);

	CPPUNIT_ASSERT(p->data == 1);
	p = p->pnext;
	CPPUNIT_ASSERT(p->data == 2);
	p = p->pnext;
	CPPUNIT_ASSERT(p->data == 4);
	CPPUNIT_ASSERT(p->pnext == null);

	p = p->plast;
	CPPUNIT_ASSERT(p->data == 2);
	p = p->plast;
	CPPUNIT_ASSERT(p->data == 1);
	CPPUNIT_ASSERT(p->plast == null);
}
/* －－－－－－－－－－删除链表中第i个节点类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－获取链表中节点个数类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase04_1()
{
	struct strlnode *p;
	int num = 0;

	create(&p, 1);
	insertnode(&p, 1, 2);
	insertnode(&p, 2, 3);
	insertnode(&p, 3, 4);

	num = getnodenum(&p);

	CPPUNIT_ASSERT(num == 4);
}
/* －－－－－－－－－－获取链表中节点个数类用例－－－－－－－－－－－－－ */


/* －－－－－－－－－－大整数相加类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase05_1()
{
	struct strlnode *plus;
	struct strlnode *p;
	struct strlnode *q;
	int a[] = {4,8,6,3,0,2,7,9,3,1,0,4,2,1,3,5,2,6};
	int b[] = {9,2,0,8,6,7,8,3,1,0,3,6,9,2,0,1,6,8};
	int j = 0;

	create(&plus, 0);
	create(&p, 0);
	create(&q, 0);

	readtolnode(&p, a, 18);
	readtolnode(&q, b, 18);

	bignumberplus(&plus, &p, &q);

	int result[19];
	writetosqlist(result, plus);
	int c[] = {1,4,0,7,1,7,0,6,2,4,1,4,1,1,3,3,6,9,4};

	for(j = 0; j < 19; j++)
	{
		CPPUNIT_ASSERT(result[j] == c[j]);
	}
}

void CExampleTest::TestCase05_2()
{
	struct strlnode *plus;
	struct strlnode *p;
	struct strlnode *q;
	int a[] = {4,8,6,3,0,2,7,9,3,1,0,4,2,1,3,5,2,6};
	int b[] = {7,6,0,9,3,4,0,1,9,2,0,8,6,7,8,3,1,0,3,6,9,2,0,1,6,8};
	int j = 0;

	create(&plus, 0);
	create(&p, 0);
	create(&q, 0);

	readtolnode(&p, a, 18);
	readtolnode(&q, b, 26);

	bignumberplus(&plus, &p, &q);

	int result[26];
	writetosqlist(result, plus);
	int c[] = {7,6,0,9,3,4,0,2,4,0,7,1,7,0,6,2,4,1,4,1,1,3,3,6,9,4};

	for(j = 0; j < 26; j++)
	{
		CPPUNIT_ASSERT(result[j] == c[j]);
	}
}

void CExampleTest::TestCase05_3()
{
	struct strlnode *plus;
	struct strlnode *p;
	struct strlnode *q;
	int a[] = {7,6,0,9,3,4,0,1,9,2,0,8,6,7,8,3,1,0,3,6,9,2,0,1,6,8};
	int b[] = {4,8,6,3,0,2,7,9,3,1,0,4,2,1,3,5,2,6};
	int j = 0;

	create(&plus, 0);
	create(&p, 0);
	create(&q, 0);

	readtolnode(&p, a, 26);
	readtolnode(&q, b, 18);

	bignumberplus(&plus, &p, &q);

	int result[26];
	writetosqlist(result, plus);
	int c[] = {7,6,0,9,3,4,0,2,4,0,7,1,7,0,6,2,4,1,4,1,1,3,3,6,9,4};

	for(j = 0; j < 26; j++)
	{
		CPPUNIT_ASSERT(result[j] == c[j]);
	}
}

/* －－－－－－－－－－大整数相加类用例－－－－－－－－－－－－－ */



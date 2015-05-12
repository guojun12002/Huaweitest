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

#define MAXSIZE 50

struct strqueue
{
	int queue[MAXSIZE];
	int head; /* 队头 */
	int tail; /* 队尾 */
	int num;  /* 队元素个数 */
};

bool initqueue(struct strqueue *s)  /* 初始化队列，返回0表示失败，返回1表示成功 */
{
	if(NULL == s) return 0;
	s->head = -1;
	s->tail = -1;
	s->num = 0;
	for(int i=0; i<MAXSIZE; ++i)
		s->queue[i] = 0;
	/* 代码在这里实现 */

	return 1;
}

bool enqueue(struct strqueue *s, int x) /* 进队列，返回0表示失败，返回1表示成功 */
{
	if(NULL == s) return 0;
	if(s->num == 50) return 0;
	/* 代码在这里实现 */
	if(s->head == -1) s->head = 0;
	s->tail = (s->tail + 1) % MAXSIZE;
	s->queue[s->tail] = x;
	++(s->num);
	return 1;
}

bool dequeue(struct strqueue *s, int *x) /* 出队列，返回0表示失败，返回1表示成功 */
{
	if(NULL == s) return 0;
	if(s->num == 0) return 0;
	/* 代码在这里实现 */
	*x = s->queue[s->head];
	s->queue[s->head] = 0;
	s->head = (s->head + 1) % MAXSIZE;
	--(s->num);
	if(s->num == 0)
	{
		s->head = -1;
		s->tail = -1;
	}
	return 1;
}

int gethead(struct strqueue *s)  /* 获得队列头数值 */
{
	if(NULL == s) return -1;
	if(s->num == 0) return -1;
	/* 代码在这里实现 */
	return s->queue[s->head];
}


int gettail(struct strqueue *s)  /* 获得队列尾数值 */
{
	if(NULL == s) return -1;
	if(s->num == 0) return -1;
	/* 代码在这里实现 */
	return s->queue[s->tail];
}

int getqueuelenth(struct strqueue *s)  /* 获得队列长度 */
{
	/* 代码在这里实现 */
	if(NULL == s) return -1;
	return s->num;
}

bool search(struct strqueue *s, int x)  /* 在队列中查找x是否存在，如果存在返回1，否则返回0 */
{
	if(NULL == s) return 0;
	if(s->num == 0) return 0;
	/* 代码在这里实现 */
	for(int i=s->head; i<s->head+s->num; ++i)
		if(s->queue[i%MAXSIZE] == x) return 1;
	return 0;
}






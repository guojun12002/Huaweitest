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
	int head; /* ��ͷ */
	int tail; /* ��β */
	int num;  /* ��Ԫ�ظ��� */
};

bool initqueue(struct strqueue *s)  /* ��ʼ�����У�����0��ʾʧ�ܣ�����1��ʾ�ɹ� */
{
	if(NULL == s) return 0;
	s->head = -1;
	s->tail = -1;
	s->num = 0;
	for(int i=0; i<MAXSIZE; ++i)
		s->queue[i] = 0;
	/* ����������ʵ�� */

	return 1;
}

bool enqueue(struct strqueue *s, int x) /* �����У�����0��ʾʧ�ܣ�����1��ʾ�ɹ� */
{
	if(NULL == s) return 0;
	if(s->num == 50) return 0;
	/* ����������ʵ�� */
	if(s->head == -1) s->head = 0;
	s->tail = (s->tail + 1) % MAXSIZE;
	s->queue[s->tail] = x;
	++(s->num);
	return 1;
}

bool dequeue(struct strqueue *s, int *x) /* �����У�����0��ʾʧ�ܣ�����1��ʾ�ɹ� */
{
	if(NULL == s) return 0;
	if(s->num == 0) return 0;
	/* ����������ʵ�� */
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

int gethead(struct strqueue *s)  /* ��ö���ͷ��ֵ */
{
	if(NULL == s) return -1;
	if(s->num == 0) return -1;
	/* ����������ʵ�� */
	return s->queue[s->head];
}


int gettail(struct strqueue *s)  /* ��ö���β��ֵ */
{
	if(NULL == s) return -1;
	if(s->num == 0) return -1;
	/* ����������ʵ�� */
	return s->queue[s->tail];
}

int getqueuelenth(struct strqueue *s)  /* ��ö��г��� */
{
	/* ����������ʵ�� */
	if(NULL == s) return -1;
	return s->num;
}

bool search(struct strqueue *s, int x)  /* �ڶ����в���x�Ƿ���ڣ�������ڷ���1�����򷵻�0 */
{
	if(NULL == s) return 0;
	if(s->num == 0) return 0;
	/* ����������ʵ�� */
	for(int i=s->head; i<s->head+s->num; ++i)
		if(s->queue[i%MAXSIZE] == x) return 1;
	return 0;
}






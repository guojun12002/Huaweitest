#include <stdlib.h>
#include "oj.h"
// ���ܣ�������ҵĸ���
// ���룺 unsigned int  nPlayNum   ��ҵĸ��� 0 < nPlayNum < 10000;
// �������
// ���أ���
struct player
{
	int No;
	player* next;
	player* pre;
	player(int n):No(n),next(NULL),pre(NULL){};
};
player* PLAYER;
void print(player* p)
{
	player* q = p->next;
	printf("%d ", p->No);
	while(q != p)
	{
		printf("%d ", q->No);
		q = q->next;
	}
	printf("\n");
	q = p->pre;
	while(q != p)
	{
		printf("%d ", q->No);
		q = q->pre;
	}
	printf("%d\n", p->No);
}
bool pick7(unsigned int num)
{
	unsigned int m = num;
    if(m%7 == 0)
    	return true;
    else
        while(m > 0)
            if(m%10 == 7) return true;
            else m /= 10;
    return false;
}
void SetPlayerNum (unsigned int  nPlayNum)
{
	if(nPlayNum == 0) return;
	PLAYER = new player(1);
	player* p = PLAYER;
	p->next = PLAYER;
	p->pre = PLAYER;
	for(unsigned int i=2; i<=nPlayNum; ++i)
	{
		p->next = new player(i);
		p->next->pre = p;
		p = p->next;
		p->next = PLAYER;
		PLAYER->pre = p;
	}
	// print(PLAYER);
}
// ���ܣ�����nInitialNum��ֵ����ȡ�����ݹ����������˵ı��
// ���룺unsigned int  nInitialNum  ���ֵĳ�ʼֵ 0 < nInitialNum < 10000��
// �������
// ���أ������˳�Բ�����˵ı��
unsigned int GetPlayerOut (unsigned int  nInitialNum)
{
	player* start = PLAYER;
	while(!pick7(nInitialNum))
	{
		start = start->next;
		++nInitialNum;
	}
	int n = start->No;
	if(start->next == start)
		PLAYER = NULL;
	else
	{
		player* pre = start->pre;
		pre->next = start->next;
		start->next->pre = pre;
		PLAYER = pre->next;
	}
	free(start);
	return n;
}
// ���ܣ���Ϸ����,�ͷ���Դ
// ���룺��
// �������
// ���أ���
void GameOver()
{
	if(PLAYER == NULL) return;
	player* p = PLAYER->next;
	while(p != NULL && p != PLAYER)
	{
		player* q = p;
		p = p->next;
		free(q);
	}
	free(PLAYER);
	PLAYER = NULL;
}



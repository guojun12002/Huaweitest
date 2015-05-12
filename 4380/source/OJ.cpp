#include <stdlib.h>
#include "oj.h"
// 功能：设置玩家的个数
// 输入： unsigned int  nPlayNum   玩家的个数 0 < nPlayNum < 10000;
// 输出：无
// 返回：无
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
// 功能：根据nInitialNum的值，获取到根据规则下桌的人的编号
// 输入：unsigned int  nInitialNum  本轮的初始值 0 < nInitialNum < 10000；
// 输出：无
// 返回：本轮退出圆桌的人的编号
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
// 功能：游戏结束,释放资源
// 输入：无
// 输出：无
// 返回：无
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



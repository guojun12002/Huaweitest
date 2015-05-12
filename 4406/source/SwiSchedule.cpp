#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
typedef long long LL;
/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 2010/3
Last Modified :
Description   :
Function List :

History       :
1.Date        : 2010/3
Author      :
Modification: Created file

******************************************************************************/
struct PROCESS
{
	int swiId;
	int prio;
	void (*proc)(void);
	PROCESS(){};
	PROCESS(int s, int p, void (*pro)()):swiId(s), prio(p), proc(pro){}
	friend bool operator<(const PROCESS&, const PROCESS&);
};
bool operator<(const PROCESS& p1, const PROCESS& p2)
{
	return p1.prio > p2.prio;
}
map<int, PROCESS> pm;
priority_queue<PROCESS> pq;
/*************************************************************************************************
函数说明：创建软中断
输入参数：
      swiId： 创建软中断ID；
	  prio：  创建软中断优先级；
      proc：  创建软中断处理函数。
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/

int SwiCreate(unsigned int swiId, unsigned int prio, void (* proc)(void))
{
	//TODO: 添加代码...
	if(swiId>99 || swiId<0 || prio>31 || prio<0 || NULL==proc)
		return -1;
	if(pm.count(swiId) == 0)
		pm[swiId] = PROCESS(swiId, prio, proc);
	else
		return -1;
	return 0;
}

/*************************************************************************************************
函数说明：软中断激活
输入参数：swiId： 待激活软中断ID
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int ID = -1;
int SwiActivate(unsigned int swiId)
{
	//TODO: 添加代码...
	if(pm.count(swiId) == 0)
		return -1;
	pq.push(pm[swiId]);
	while(!pq.empty())
	{
		PROCESS tmp = pq.top();
		if(ID != tmp.swiId)
		{
			int id = ID;
			ID = tmp.swiId;
			tmp.proc();
			ID = id;
			pq.pop();
		}
		else
			break;
	}
	return 0;
}

/*************************************************************************************************
函数说明：清空所有的信息
输入参数：无
输出参数：无
返回值  ：无
**************************************************************************************************/
void Clear(void)
{
	//TODO: 添加代码...
	ID = -1;
	pm.clear();
	while(!pq.empty())
		pq.pop();
	return;
}

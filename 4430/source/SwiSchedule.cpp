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
����˵�����������ж�
���������
      swiId�� �������ж�ID��
	  prio��  �������ж����ȼ���
      proc��  �������жϴ�������
�����������
����ֵ  ���ɹ�����0�� �����������-1
**************************************************************************************************/

int SwiCreate(unsigned int swiId, unsigned int prio, void (* proc)(void))
{
	//TODO: ��Ӵ���...
	if(swiId>99 || swiId<0 || prio>31 || prio<0 || NULL==proc)
		return -1;
	if(pm.count(swiId) == 0)
		pm[swiId] = PROCESS(swiId, prio, proc);
	else
		return -1;
	return 0;
}

/*************************************************************************************************
����˵�������жϼ���
���������swiId�� ���������ж�ID
�����������
����ֵ  ���ɹ�����0�� �����������-1
**************************************************************************************************/
int ID = -1;
int SwiActivate(unsigned int swiId)
{
	//TODO: ��Ӵ���...
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
����˵����������е���Ϣ
�����������
�����������
����ֵ  ����
**************************************************************************************************/
void Clear(void)
{
	//TODO: ��Ӵ���...
	ID = -1;
	pm.clear();
	while(!pq.empty())
		pq.pop();
	return;
}

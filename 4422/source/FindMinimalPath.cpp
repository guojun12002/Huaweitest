#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
const int LINE = 50;
const int STATION = 200;
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
struct station
{
  unsigned int pos;
  vector<UI> path;
  station(){};
  station(int p, vector<UI>& v):pos(p), path(v){};
};
bool visited[STATION]={};
queue<station> que;
vector<vector<UI> > paths;
bool reached[STATION][STATION]={};
UI pl[STATION][STATION];
vector<vector<UI> > line;
UI maxstation = 0;
UI src=0,des=0;
int mmins=-1;
/*******************************************************************************************************************
����˵���� ����ĳ��������·
����ԭ�ͣ� void AddLine(unsigned int LineNo, unsigned int StationNum ,unsigned  int *pStationArray)��
���������
           LineNo        ������·�ţ�
           StationNum    �����������е�վ����Ŀ���ɵ����߱�֤��С��2��
           pStationArray ���������ߵ�����վ����Ϣ��pStationArrayָ��Ĵ洢�ռ��ں�����ᱻ�ͷţ�����������洢�ռ䣻
��������� ��
����ֵ  �� ��
********************************************************************************************************************/
void AddLine(unsigned int LineNo, unsigned int StationNum ,unsigned  int *pStationArray)
{
    /* ������ʵ�ֹ��� */
  if(StationNum < 2 || pStationArray == NULL) return;
  vector<UI> v(pStationArray, pStationArray+StationNum);
  line.push_back(v);
  for(unsigned int i=0; i<StationNum-1; ++i)
  {
    reached[pStationArray[i]][pStationArray[i]] = true;
    reached[pStationArray[i]][pStationArray[i+1]] = true;
    reached[pStationArray[i+1]][pStationArray[i]] = true;
    pl[pStationArray[i]][pStationArray[i+1]] = LineNo;
    pl[pStationArray[i+1]][pStationArray[i]] = LineNo;
    if(maxstation < pStationArray[i]) maxstation = pStationArray[i];
  }
  reached[pStationArray[StationNum-1]][pStationArray[StationNum-1]] = true;
  if(maxstation < pStationArray[StationNum-1]) maxstation = pStationArray[StationNum-1];
  return;
}

/*********************************************************************************************************************
����˵������������վ���յ�վ�����·�߳���
����ԭ�ͣ�int CalcMinPathLen(unsigned int SrcStation, unsigned int DesStation)��
���������
          SrcStation  ���վ��
          DesStation �յ�վ��
�����������
����ֵ  ��
          ���վ���յ�վ�����·�߳���
          -1���κγ������������·�߲����ڡ�վ�㲻���ڡ������յ��ص��ȵȣ�
**********************************************************************************************************************/
void record(station& now, UI& mins)
{
  if(mins > now.path.size()) mins = now.path.size();
  station pos = now;
  pos.path.push_back(pos.pos);
  // for(int i=0; i<pos.path.size(); ++i)
  //   cout<<pos.path[i]<< ' ';
  // cout<<endl;
  paths.push_back(pos.path);
}
int CalcMinPathLen(unsigned int SrcStation, unsigned int DesStation)
{

    /* ������ʵ�ֹ��� */
  memset(visited, 0, sizeof(visited));
  paths.clear();
  while(!que.empty()) que.pop();

  if(SrcStation == DesStation) return -1;
  if(!reached[SrcStation][SrcStation] || !reached[DesStation][DesStation]) return -1;
  unsigned int mins = STATION;
  vector<UI> v;
  que.push(station(SrcStation, v));
  while(!que.empty())
  {
    station now = que.front();
    if(now.path.size() > mins)
      break;
    visited[now.pos] = true;
    if(now.pos == DesStation)
    {
      record(now, mins);
      que.pop();
      continue;
    }
    for(int i=0; i<=maxstation; ++i)
      if(reached[now.pos][i] && now.pos != i && !visited[i])
      {
        vector<UI> tmp = now.path;
        tmp.push_back(now.pos);
        que.push(station(i, tmp));
      }
    que.pop();
  }
  src = SrcStation;
  des = DesStation;
  mmins = mins;
  return mins;
};

/**********************************************************************************************************
����˵������������վ���յ�վ�����·��
����ԭ�ͣ�int SearchMinPathes(unsigned int SrcStation,
                              unsigned int DesStation,
                              unsigned int* pPathNum,
                              unsigned int* pPathLen,
                              unsigned int **ppPathes);
���������
          SrcStation ���վ��
          DesStation �յ�վ��
          Output Param
          pPathNum ���·������;
          pPathLen  ���·�߳���;
          ppPathes �洢���·�ߵ��ڴ��ַ���ڴ�ռ��ڱ����������룬�������ͷţ��ڴ�ռ�Ĵ洢��ʽ���PPTҪ��
����ֵ  ��
          0 ���ɹ�
          -1���κγ������������·�߲����ڡ�վ�㲻���ڡ������յ��ص��ȵȣ�

************************************************************************************************************/
int SearchMinPathes(unsigned int SrcStation,
                    unsigned int DesStation,
                    unsigned int* pPathNum,
                    unsigned int* pPathLen,
                    unsigned int **ppPathes)
{
    /* ������ʵ�ֹ��� */
    int mins;
    if(SrcStation == src && des == DesStation)
      mins = mmins;
    else
      mins = CalcMinPathLen(SrcStation, DesStation);
    if(mins == -1 || mins == STATION) return -1;
    int pathnum = paths.size();
    int stationnum = mins + 1;
    *ppPathes = (UI*)malloc(sizeof(UI)*pathnum*(stationnum));
    for(int i=0; i<pathnum; ++i)
      for(int j=0; j<stationnum; ++j)
        (*ppPathes)[i*stationnum+j] = paths[i][j];
    *pPathLen = mins;
    *pPathNum = pathnum;
    return 0;
}

/*************************************************************************************************
����˵������������վ���յ�վ������·��
����ԭ�ͣ�int SearchBestPathes(unsigned int SrcStation,
                               unsigned int DesStation,
                               unsigned int *pPathNum,
                               unsigned int* pPathLen,
                               unsigned int** ppPathes);
���������
         SrcStation ���վ��
         DesStation �յ�վ��
         Output Param
         pPathNum ����·������;
         pPathLen  ���·�߳���;
         ppPathes �洢���·�ߵ��ڴ��ַ���ڴ��ʽ����ͼ,�ڴ�ռ��ڱ����������룬�������ͷţ�
����ֵ ��
         0���ɹ�
         -1���κγ������������·�߲����ڡ�վ�㲻���ڡ������յ��ص��ȵȣ�
**************************************************************************************************/
int SearchBestPathes(unsigned int SrcStation,
                     unsigned int DesStation,
                     unsigned int *pPathNum,
                     unsigned int* pPathLen,
                     unsigned int** ppPathes)
{
    /* ������ʵ�ֹ��� */
  int mins;
  if(SrcStation == src && des == DesStation)
    mins = mmins;
  else
    mins = CalcMinPathLen(SrcStation, DesStation);
  if(mins == -1 || mins == STATION) return -1;
  int pathnum = paths.size();
  int stationnum = mins + 1;
  *ppPathes = (UI*)malloc(sizeof(UI)*pathnum*(stationnum));

  int minc = STATION;
  UI ChangeStation[LINE];
  for(int i=0; i<pathnum; ++i)
  {
    bool flag[LINE]={};
    for(int j=0; j<paths[i].size()-1; ++j)
      flag[pl[paths[i][j]][paths[i][j+1]]] = true;
    int sum = 0;
    for(int j=0; j<LINE; ++j)
      if(flag[j]) ++sum;
    ChangeStation[i] = sum;
    if(minc > sum) minc = sum;
  }
  int pi = 0;
  for(int i=0; i<pathnum; ++i)
    if(ChangeStation[i] == minc)
    {
      for(int j=0; j<stationnum; ++j)
        (*ppPathes)[pi*stationnum+j] = paths[i][j];
      ++pi;
    }
  *pPathNum = pi;
  *pPathLen = mins;
  return 0;
  // return SearchMinPathes(SrcStation, DesStation, pPathNum, pPathLen, ppPathes);
}

/*************************************************************************************************
����˵����������е���·��Ϣ
����ԭ�ͣ�void Clear();
�����������
�����������
����ֵ  ����
**************************************************************************************************/
void Clear()
{

    /* ������ʵ�ֹ��� */
  memset(visited, 0, sizeof(visited));
  paths.clear();
  while(!que.empty()) que.pop();
  for(int i=0; i<STATION; ++i)
    for(int j=0; j<STATION; ++j)
      reached[i][j] = false;
  line.clear();
  src = 0;
  des = 0;
  mmins = -1;
  return ;

};

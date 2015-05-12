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
函数说明： 增加某条地铁线路
函数原型： void AddLine(unsigned int LineNo, unsigned int StationNum ,unsigned  int *pStationArray)；
输入参数：
           LineNo        地铁线路号；
           StationNum    该条地铁线中的站点数目，由调用者保证不小于2；
           pStationArray 该条地铁线的所有站点信息，pStationArray指向的存储空间在函数外会被释放，请自行申请存储空间；
输出参数： 无
返回值  ： 无
********************************************************************************************************************/
void AddLine(unsigned int LineNo, unsigned int StationNum ,unsigned  int *pStationArray)
{
    /* 在这里实现功能 */
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
函数说明：计算从起点站到终点站的最短路线长度
函数原型：int CalcMinPathLen(unsigned int SrcStation, unsigned int DesStation)；
输入参数：
          SrcStation  起点站；
          DesStation 终点站；
输出参数：无
返回值  ：
          起点站到终点站的最短路线长度
          -1：任何出错情况（包括路线不存在、站点不存在、起点和终点重叠等等）
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

    /* 在这里实现功能 */
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
函数说明：输出从起点站到终点站的最短路线
函数原型：int SearchMinPathes(unsigned int SrcStation,
                              unsigned int DesStation,
                              unsigned int* pPathNum,
                              unsigned int* pPathLen,
                              unsigned int **ppPathes);
输入参数：
          SrcStation 起点站；
          DesStation 终点站；
          Output Param
          pPathNum 最短路线条数;
          pPathLen  最短路线长度;
          ppPathes 存储最短路线的内存地址，内存空间在本函数内申请，调用者释放，内存空间的存储格式请见PPT要求；
返回值  ：
          0 ：成功
          -1：任何出错情况（包括路线不存在、站点不存在、起点和终点重叠等等）

************************************************************************************************************/
int SearchMinPathes(unsigned int SrcStation,
                    unsigned int DesStation,
                    unsigned int* pPathNum,
                    unsigned int* pPathLen,
                    unsigned int **ppPathes)
{
    /* 在这里实现功能 */
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
函数说明：输出从起点站到终点站的最优路线
函数原型：int SearchBestPathes(unsigned int SrcStation,
                               unsigned int DesStation,
                               unsigned int *pPathNum,
                               unsigned int* pPathLen,
                               unsigned int** ppPathes);
输入参数：
         SrcStation 起点站；
         DesStation 终点站；
         Output Param
         pPathNum 最优路线条数;
         pPathLen  最短路线长度;
         ppPathes 存储最短路线的内存地址，内存格式见下图,内存空间在本函数内申请，调用者释放；
返回值 ：
         0：成功
         -1：任何出错情况（包括路线不存在、站点不存在、起点和终点重叠等等）
**************************************************************************************************/
int SearchBestPathes(unsigned int SrcStation,
                     unsigned int DesStation,
                     unsigned int *pPathNum,
                     unsigned int* pPathLen,
                     unsigned int** ppPathes)
{
    /* 在这里实现功能 */
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
函数说明：清空所有的线路信息
函数原型：void Clear();
输入参数：无
输出参数：无
返回值  ：无
**************************************************************************************************/
void Clear()
{

    /* 在这里实现功能 */
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

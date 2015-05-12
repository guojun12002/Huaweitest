#include "CellularDistrict.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
struct Position
{
  int iCircle;//Ȧ�ţ��ӣ���ʼ
  int iInnerNo;//Ȧ�ڱ�ţ��ӣ���ʼ
};

struct Coordinate
{
  int x;
  int y;
};

int GetMinOfRealNumInCycle(int cycleNo)  
{  
    return 2 + 3 * cycleNo * (cycleNo - 1);  
}  

int GetMaxColumnNumInCycle(int cycleNo)  
{  
    return 6 * cycleNo;  
}

int GetMaxOfRealNumInCycle(int cycleNo)  
{  
    return GetMinOfRealNumInCycle(cycleNo) + GetMaxColumnNumInCycle(cycleNo) - 1;  
}  

void GetPosition(int iCellularNo, Position *pstPosition)
{
  int cycle;
  int minCellularNoInCycle;
  int columnNo;

  if( iCellularNo == 1 )
  {
    pstPosition->iCircle = 0;
    pstPosition->iInnerNo = 1;
  }
  else
  {
    cycle = 1;
    while (GetMaxOfRealNumInCycle(cycle) < iCellularNo)
        {
            cycle++;
        }

        // ������ʵ��Ŷ�ӦȦ�еı��
        minCellularNoInCycle = GetMinOfRealNumInCycle(cycle);
        columnNo = iCellularNo - minCellularNoInCycle + 1;

    pstPosition->iCircle = cycle;
    pstPosition->iInnerNo = columnNo;
  }

  return;
}

void GetCoordinate(int iCellularNo, Coordinate *pstCoordinate)
{
  Position stPosition;

  if( iCellularNo == 1 )
  {
    pstCoordinate->x = 0;
    pstCoordinate->y = 0;

    return;
  }

  GetPosition(iCellularNo, &stPosition);

  if( stPosition.iInnerNo <= stPosition.iCircle )
  {
    pstCoordinate->x = stPosition.iCircle - stPosition.iInnerNo;
    pstCoordinate->y = -stPosition.iInnerNo;
  }
  else if( stPosition.iInnerNo <= stPosition.iCircle * 2)
  {
    pstCoordinate->x = stPosition.iCircle - stPosition.iInnerNo;
    pstCoordinate->y = -stPosition.iCircle;
  }
  else if(stPosition.iInnerNo <= stPosition.iCircle * 3)
  {
    pstCoordinate->x = -stPosition.iCircle;
    pstCoordinate->y = stPosition.iInnerNo - stPosition.iCircle * 3;
  }
  else if(stPosition.iInnerNo <= stPosition.iCircle * 4)
  {
    pstCoordinate->x = stPosition.iInnerNo - stPosition.iCircle * 4;
    pstCoordinate->y = stPosition.iInnerNo - stPosition.iCircle * 3;
  }
  else if(stPosition.iInnerNo <= stPosition.iCircle * 5)
  {
    pstCoordinate->x = stPosition.iInnerNo - stPosition.iCircle * 4;
    pstCoordinate->y = stPosition.iCircle;
  }
  else//stPosition.iInnerNo <= stPosition.iCircle * 6
  {
    pstCoordinate->x = stPosition.iCircle;
    pstCoordinate->y = stPosition.iCircle * 6 - stPosition.iInnerNo;
  }

  return;
}

/************************************************************************
Description  : ��ʼ������С����Ϣ
Prototype    : void InitCellularDistrict(int iMaxSeqValue)
               Input Param  : iMaxSeqValue ����С�������ֵ��ţ�ע����Ŵ�1��ʼ
               Output Param : ��
               Return Value : �ɹ�����0��ʧ�ܷ���-1
/************************************************************************/
int imax;
int InitCellularDistrict(int iMaxSeqValue)
{
    if( iMaxSeqValue < 1 || iMaxSeqValue > 100000 )
  {
    return -1;
  }
  else
  {
    imax = iMaxSeqValue;
    return 0;
  }
}

/************************************************************************
Description  : ���������С��ָ�����㣨���ֵ��֮�����̾���
Prototype    : int GetShortestPathLength(int iFirstValue, int iSecondValue)
               Input Param  : iFirstValue �����ֵ�� iSecondValue �յ���ֵ
               Output Param : ��
               Return Value : ����ɹ�������̾��룬ʧ�ܷ���-1
/************************************************************************/
int GetShortestPathLength(int iFirstValue, int iSecondValue)
{
    int iXDistance;
  int iYDistance;

  Coordinate coordinate1st;
  Coordinate coordinate2nd;

  if( iFirstValue < 1 || iFirstValue > imax || iSecondValue < 1 || iSecondValue > imax)
  {
    return -1;
  }

  GetCoordinate(iFirstValue, &coordinate1st);
  GetCoordinate(iSecondValue, &coordinate2nd);

  iXDistance = coordinate2nd.x - coordinate1st.x;
  iYDistance = coordinate2nd.y - coordinate1st.y;

  if( iXDistance == iYDistance )
  {
    return abs(iXDistance);
  }
  else if(coordinate2nd.x == coordinate1st.x)
  {
    return abs(iYDistance);
  }
  else if(coordinate2nd.y == coordinate1st.y)
  {
    return abs(iXDistance);
  }
  else if(iXDistance * iYDistance < 0)//���ޣ��ͣ�
  {
    return (abs(iXDistance) + abs(iYDistance));
  }
  else
  {
    if(abs(iXDistance) > abs(iYDistance))
      return abs(iXDistance);
    else
      return abs(iYDistance);
  }
}

/************************************************************************
Description  : ��������Ϣ
Prototype    : void Clear()
               Input Param  : ��
               Output Param : ��
               Return Value : ��
/************************************************************************/
void Clear()
{

}
#include "ObjMgt.h"
struct
{
  unsigned int key1;
  unsigned int key2;
  unsigned int key3;
}OB[10005];
int nOB = 0;
void printall()
{
  for(int i=0; i<nOB; ++i)
    printf("%d %d %d\n", OB[i].key1, OB[i].key2, OB[i].key3);
}
/*************************************************************************
功能：增加单个对象
输入：
key1  外部关键字 KEY1 
key2  外部关键字KEY2
key3  外部关键字KEY3
输出：无
返回： 
      -1 :失败(对象已经存在或者其它异常)
       0 :成功
***************************************************************************/
int AddObject (unsigned int key1, unsigned int key2, unsigned int key3)
{
    /*请实现*/
    if(key1 > 65535 || key2 > 65535 || key3 > 65535) return -1;
    if(IsObjectExist(key1, key2, key3) == 1) return -1;
    if(nOB > 10000) return -1;
    OB[nOB].key1 = key1;
    OB[nOB].key2 = key2;
    OB[nOB].key3 = key3;
    ++nOB;
    return 0;
}

/********************************************************************************
功能：删除一个或多个对象
输入：
      key1 外部关键字 KEY1 
      key2 外部关键字 KEY2
      key3 外部关键字 KEY3
输出：无
返回：无

说明：用例保证参数取值为合法值和通配符0xFFFFFFFF, 通配符表示0~65535范围内的任意值; 
      举例:key1=1,key2=2,key3= 0xFFFFFFFF，表示删除key1=1,key2=2的所有对象;
           key1,key2,key3取值全为0xFFFFFFFF时,表示删除所有对象。
*********************************************************************************/
void DeleteObject (unsigned int key1, unsigned int key2, unsigned int key3)
{
    /*请实现*/
    if(key1 != 0xffffffff && key1 > 65535) return;
    if(key2 != 0xffffffff && key2 > 65535) return;
    if(key3 != 0xffffffff && key3 > 65535) return;
    int i = 0;
    while(i < nOB)
    {
      bool flag = true;
      if(flag && key1 != 0xffffffff) flag = flag && (OB[i].key1 == key1);
      if(flag && key2 != 0xffffffff) flag = flag && (OB[i].key2 == key2);
      if(flag && key3 != 0xffffffff) flag = flag && (OB[i].key3 == key3);
      if(flag)
      {
        for(int j=i; j<nOB-1; ++j)
          OB[j] = OB[j+1];
        --nOB;
      }
      else
        ++i;
    }
    return ;
}

/********************************************************************************
功能：查询单个对象是否存在
输入：
      key1 外部关键字 KEY1 
      key2 外部关键字 KEY2
      key3 外部关键字 KEY3
输出：无
返回：
      0：不存在
      1：存在
**********************************************************************************/
int IsObjectExist (unsigned int key1, unsigned int key2, unsigned int key3)
{
    /*请实现*/
    if(key1 > 65535 || key2 > 65536 || key3 > 65535) return 0;
    for(int i=0; i<nOB; ++i)
      if(OB[i].key1 == key1 && OB[i].key2 == key2 && OB[i].key3 == key3) return 1;
    return 0;
}

/******************************************************************************************************
Description     清空所有对象
Prototype       void Clear();
Input Param     无
Output Param    无
Return Value    无

********************************************************************************************************/
void Clear(void)
{
    /*在这里实现功能*/
    nOB = 0;
    return;
}
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
���ܣ����ӵ�������
���룺
key1  �ⲿ�ؼ��� KEY1 
key2  �ⲿ�ؼ���KEY2
key3  �ⲿ�ؼ���KEY3
�������
���أ� 
      -1 :ʧ��(�����Ѿ����ڻ��������쳣)
       0 :�ɹ�
***************************************************************************/
int AddObject (unsigned int key1, unsigned int key2, unsigned int key3)
{
    /*��ʵ��*/
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
���ܣ�ɾ��һ����������
���룺
      key1 �ⲿ�ؼ��� KEY1 
      key2 �ⲿ�ؼ��� KEY2
      key3 �ⲿ�ؼ��� KEY3
�������
���أ���

˵����������֤����ȡֵΪ�Ϸ�ֵ��ͨ���0xFFFFFFFF, ͨ�����ʾ0~65535��Χ�ڵ�����ֵ; 
      ����:key1=1,key2=2,key3= 0xFFFFFFFF����ʾɾ��key1=1,key2=2�����ж���;
           key1,key2,key3ȡֵȫΪ0xFFFFFFFFʱ,��ʾɾ�����ж���
*********************************************************************************/
void DeleteObject (unsigned int key1, unsigned int key2, unsigned int key3)
{
    /*��ʵ��*/
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
���ܣ���ѯ���������Ƿ����
���룺
      key1 �ⲿ�ؼ��� KEY1 
      key2 �ⲿ�ؼ��� KEY2
      key3 �ⲿ�ؼ��� KEY3
�������
���أ�
      0��������
      1������
**********************************************************************************/
int IsObjectExist (unsigned int key1, unsigned int key2, unsigned int key3)
{
    /*��ʵ��*/
    if(key1 > 65535 || key2 > 65536 || key3 > 65535) return 0;
    for(int i=0; i<nOB; ++i)
      if(OB[i].key1 == key1 && OB[i].key2 == key2 && OB[i].key3 == key3) return 1;
    return 0;
}

/******************************************************************************************************
Description     ������ж���
Prototype       void Clear();
Input Param     ��
Output Param    ��
Return Value    ��

********************************************************************************************************/
void Clear(void)
{
    /*������ʵ�ֹ���*/
    nOB = 0;
    return;
}
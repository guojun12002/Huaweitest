
#include "OJ.h"

/*
����: ����һ���Ѿ�������������������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֡�����ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�

����: int aData[]           // ��������
      unsigned int uiLength // ����Ԫ�ظ���
      int sum,              // ������������ĺ�
      
���: int *pNum1            // ��һ�����֣���Ӧ��������С��
      int *pNum2            // �ڶ������֣���Ӧ�����������

����: �ҵ�����true���쳣����false
*/
bool FindTwoNumbersWithSum(int aData[], unsigned int uiLength, int sum, int *pNum1, int *pNum2)
{
	/*������ʵ�ֹ���*/
	if(aData == NULL || pNum1 == NULL || NULL == pNum2) return false;
	for(int i=0; i<uiLength-1; ++i)
		for(int j=i+1; j<uiLength; ++j)
			if(aData[i] + aData[j] == sum)
			{
				*pNum1 = aData[i];
				*pNum2 = aData[j];
				return true;
			}

	return false;
}

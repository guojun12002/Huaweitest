
#include "OJ.h"
#include <string.h>
#include <stdio.h>

/*
Description  
         ����һ������������ȡ�ö������Ŀ����ȡ�
Prototype
         int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight)
Input Param 
         head   ��Ҫ��ȡ��ȵĶ�����ͷ���
Output Param 
         pulWidth   ���
         pulHeight  �߶�
Return Value
         0          �ɹ�
         1          ʧ�ܻ������쳣
*/
int runH(BiNode* root)
{
	if(NULL == root) return 0;
	int h1 = runH(root->left);
	int h2 = runH(root->right);
	return 1 + (h1 > h2 ? h1 : h2);
}
int runW(BiNode* root)
{
	if(NULL == root) return 0;
	int w1 = runW(root->left);
	int w2 = runW(root->right);
	return w1+w2==0 ? 1 : w1+w2;
}
int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight)
{
	/*������ʵ�ֹ���*/
	if(NULL == pulWidth || NULL == pulHeight) return 1;
    BiNode* root = &head;
    *pulHeight = runH(root);
    *pulWidth = runW(root);
    return 0;
}

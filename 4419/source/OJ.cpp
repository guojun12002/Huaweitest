
#include "OJ.h"
#include <string.h>
#include <stdio.h>

/*
Description  
         给定一个二叉树，获取该二叉树的宽度深度。
Prototype
         int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight)
Input Param 
         head   需要获取深度的二叉树头结点
Output Param 
         pulWidth   宽度
         pulHeight  高度
Return Value
         0          成功
         1          失败或其他异常
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
	/*在这里实现功能*/
	if(NULL == pulWidth || NULL == pulHeight) return 1;
    BiNode* root = &head;
    *pulHeight = runH(root);
    *pulWidth = runW(root);
    return 0;
}

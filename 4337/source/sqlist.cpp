/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2012/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2012/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>

#define MAXSIZE 5

struct strmatrix
{
	int rownum; /* 二维数组行数 */
	int columnnum; /* 二维数组行数 */
	int matrix[MAXSIZE][MAXSIZE];
};

void setnull(struct strmatrix *p)  /*表置空*/
{
	if(NULL == p) return;
	/* 代码在这里实现 */
	for(int i=0; i<p->rownum; ++i)
		for(int j=0; j<p->columnnum; ++j)
			p->matrix[i][j] = 0;
	p->columnnum = 0;
	p->rownum = 0;
}

int getelementnum(struct strmatrix *p)  /*获取表中元素个数*/
{
	if(p == NULL) return 0;
	int elementnum = p->columnnum * p->rownum;

	/* 代码在这里实现 */

	return elementnum;
}


int getxnum(struct strmatrix *p, int x) /*获得数组中等于某个值的元素的个数*/
{
	int num = 0;
	if(p == NULL) return num;
	/* 代码在这里实现 */
	for(int i=0; i<p->rownum; ++i)
		for(int j=0; j<p->columnnum; ++j)
			if(p->matrix[i][j] == x) ++num;

	return num;
}

void insertrow(struct strmatrix *p,int i,int *x) /* 插入1行 */
{
	/* 代码在这里实现 */
	if(i > p->rownum || i >= MAXSIZE || NULL == p || p->rownum == MAXSIZE || x == NULL) return;
	if(i == p->rownum)
	{
		for(int j=0; j<p->columnnum; ++j)
			p->matrix[i][j] = x[j];
		p->rownum += 1;
	}
	else
	{
		for(int l=p->rownum; l>i; --l)
			for(int j=0; j<p->columnnum; ++j)
				p->matrix[l][j] = p->matrix[l-1][j];
		for(int j=0; j<p->columnnum; ++j)
			p->matrix[i][j] = x[j];
		p->rownum += 1;
	}

}

void insertcolumn(struct strmatrix *p,int i,int *x) /* 插入1列 */
{
	/* 代码在这里实现 */
	if(i > p->columnnum || i >= MAXSIZE || NULL == p || x == NULL || p->columnnum == MAXSIZE) return;
	if(i == p->columnnum)
	{
		for(int j=0; j<p->rownum; ++j)
			p->matrix[j][i] = x[j];
		p->columnnum += 1;
	}
	else
	{
		for(int c=p->columnnum; c>i; --c)
			for(int j=0; j<p->rownum; ++j)
				p->matrix[j][c] = p->matrix[j][c-1];
		for(int j=0; j<p->rownum; ++j)
			p->matrix[j][i] = x[j];
		p->columnnum += 1;
	}
}


void matrixtrans(struct strmatrix *p) /* 方矩阵置换 */
{
	/* 代码在这里实现 */
	if(NULL == p) return;
	for(int i = 0; i<p->rownum; ++i)
		for(int j=0; j<i; ++j)
		{
			int t = p->matrix[i][j];
			p->matrix[i][j] = p->matrix[j][i];
			p->matrix[j][i] = t;
		}
}

void matrixwhirl(struct strmatrix *p) /* 方矩阵顺时针旋转90度 */
{
	/* 代码在这里实现 */
	if(NULL == p) return;
	int t[MAXSIZE][MAXSIZE] = {};
	for(int i=0; i<p->rownum; ++i)
		for(int j=0; j<p->columnnum; ++j)
			t[i][j] = p->matrix[i][j];
	for(int i=0; i<p->columnnum; ++i)
		for(int j=0; j<p->rownum; ++j)
			p->matrix[i][j] = t[p->rownum-j-1][i];
	int tem = p->columnnum;
	p->columnnum = p->rownum;
	p->rownum = tem;
}

void matrixplus(struct strmatrix *plu, struct strmatrix *p, struct strmatrix *q) /* 两个矩阵相加 */
{
	/* 代码在这里实现 */
	if(NULL == plu || NULL == p || NULL == q) return;
	if(p->columnnum != q->columnnum || p->rownum != q->rownum) return;
	for(int i=0; i<p->rownum; ++i)
		for(int j=0; j<p->columnnum; ++j)
			plu->matrix[i][j] = p->matrix[i][j] + q->matrix[i][j];
	plu->rownum = p->rownum;
	plu->columnnum = p->columnnum;
}

void matrixmultiply(struct strmatrix *mul, struct strmatrix *p, struct strmatrix *q) /* 两个矩阵相乘 */
{
	/* 代码在这里实现 */
	if(mul == NULL || NULL == p || NULL == q) return;
	if(p->columnnum != q->rownum) return;
	mul->rownum = p->rownum;
	mul->columnnum = q->columnnum;
	for(int i=0; i<mul->rownum; ++i)
		for(int j=0; j<mul->columnnum; ++j)
		{
			mul->matrix[i][j] = 0;
			for(int pi = 0; pi<p->columnnum; ++pi)
				mul->matrix[i][j] += p->matrix[i][pi] * q->matrix[pi][j];
		}
}
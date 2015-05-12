
#include "OJ.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
  
/*
功能:	计算所有选 手的平均得分。
    
输入参数（指针指向的内存区域保证有效）：
	 	char* pInputString：字符串数组，是输入的成绩和姓名。分数是0-10的整数，名字的长度不超过30个字符
		int Num：整数，参赛选手的数量，2 <= Num <= 26。
输出参数（指针指向的内存区域保证有效）：
	 	char* pResult：一块buffer，输出所有参赛者的姓名和平均分（保留2位小数）。格式要求如下：
			1、姓名在前，平均分在后，中间由一个空格隔开；
			2、每行参赛者的成绩占一行（最后一个参赛者成绩之后不要换行符）；
			3、输出成绩按输入顺序排序。 	
返回值：
		void

*/


void GetResult(char* pInput[], int Num, char *pResult)
{
	if(NULL == pInput || pResult == NULL) return;
	for(int i=0; i<Num; ++i)
	{
		int sc[7];
		char name[50], put[50];
		sscanf(pInput[i], "%d %d %d %d %d %d %d %s", sc, sc+1, sc+2, sc+3, sc+4, sc+5, sc+6, name);
		sort(sc, sc+7);
		double avg = 0;
		for(int i=1; i<6; ++i)
			avg += sc[i];
		avg /= 5;
		sprintf(put, "%.2f", avg);
		strcat(pResult, name);
		strcat(pResult, " ");
		strcat(pResult, put);
		if(i != Num-1) strcat(pResult, "\n");
		// printf("%d %d %d %d %d %d %d\n", sc[0],sc[1],sc[2],sc[3],sc[4],sc[5],sc[6]);
		// cout<<name<<endl;
	}
	return;
} 

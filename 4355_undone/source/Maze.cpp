#include "Maze.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int MAX = 55;
int maze[MAX][MAX];
int reached[MAX][MAX]; // -1: left reached; 1: right reached; 2: all reached; 
int height = 0, weight = 0;
int start_i, start_j;
int length;
void print()
{
	for(int i=0; i<height; ++i)
	{
		for(int j=0; j<weight; ++j)
			printf("%d", maze[i][j]);
		printf("\n");
	}
}
// void unreached()
// {
// 	for(int i=0; i<MAX; ++i)
// 		for(int j=0; j<MAX; ++j)
// 			reached[i][j] = 0;
// }
bool findcycle(int last_i, int last_j, int LorR)
{
	if(last_i < 0 || last_i >= height || last_j < 0 || last_j >= weight) return false;


}
/* 功能：找出一个迷宫中的最长环路以及环路个数
 * 输入：存放迷宫信息的记事本文件路径，该程序从文件中读取迷宫信息。
 * 输出：CycleCount，环路个数
 * 返回：最长环路长度,如果没有环路，返回-1.
 */
int FindLongestCycle(const char* mazefile, int *CycleCount)
{
	if(NULL == mazefile || NULL == CycleCount || mazefile[0] == '\0') return -1;
	for(int i=0; i<MAX; ++i)
		for(int j=0; j<MAX; ++j)
			maze[i][j] = reached[i][j] = 0;
	freopen(mazefile, "r", stdin);
	char str[MAX];
	while(cin >> str)
	{
		for(int i=0; i<strlen(str); ++i)
			if(str[i] == '/') maze[height][i] = -1;
			else maze[height][i] = 1;
		++height;
	}
	weight = strlen(str);
	if(height <= 1 || height > 50 || weight <= 1 || weight > 50) return -1;
	int maxlength = -1;
	for(int i=0; i<height; ++i)
		for(int j=0; j<weight; ++j)
		{
			start_i = i;
			start_j = j;
			length = 0;
			if(findcycle(i, j, -1))
				if(maxlength < length) maxlength = length;
			length = 0;
			if(findcycle(i, j, 1))
				if(maxlength < length) maxlength = length;
		}
	// print();
	return maxlength;
}


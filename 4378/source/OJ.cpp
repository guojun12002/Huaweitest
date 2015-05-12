#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#include "OJ.h"
#include <queue>
/*
Description
     每组测试数据以三个整数N,M,T(0<n, m≤20, t>0)开头，分别代表迷宫的长和高，以及公主能坚持的天数。
	 紧接着有M行，N列字符，由"."，"*"，"P"，"S"组成。其中 "." 代表能够行走的空地。 "*" 代表墙壁，Jesse不能从此通过。
	 "P" 是公主所在的位置。 "S" 是Jesse的起始位置。 每个时间段里Jesse只能选择“上、下、左、右”任意一方向走一步。
Prototype
     int SSaveP (int *maze[], int M, int n, int t)
Input Param
     maze            迷宫布局（这里用二维数组实现布局）
	 M               迷宫（数组）行数
     N               迷宫（数组）列数
	 T               公主能坚持的天数
Output Param
                     无
Return Value
     0         可以救出公主
     -1        不可以救出公主

*/
struct POSITION
{
    int pi, pj, day;
    POSITION(){};
    POSITION(int i, int j, int d):pi(i), pj(j), day(d){};
};
bool operator==(POSITION& p1, POSITION& p2)
{
    return p1.pi==p2.pi && p1.pj==p2.pj;
}
int SSavep(char *maze, int t, int n, int m)
{
	// 这里面添加函数功能
    if(NULL == maze || t == 0) return -1;
    bool visited[25][25]={};
    POSITION des;
    queue<POSITION> que;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
        {
            if(maze[i*n+j] == '*')
                visited[i][j] = true;
            else if(maze[i*n+j] == 'P')
                des = POSITION(i, j, t);
            else if(maze[i*n+j] == 'S')
                que.push(POSITION(i, j, 0));
        }
    while(!que.empty())
    {
        POSITION pos = que.front();
        if(pos == des)
            return pos.day <= des.day ? 0 : -1;
        int i = pos.pi, j = pos.pj, d = pos.day;
        if(visited[i][j])
        {
            que.pop();
            continue;
        }
        visited[i][j] = true;
        cout<<i<<' '<<j<<' '<<pos.day<<endl;
        if(i == 4 && j == 4)
        {
            for(int a=0; a<m; ++a)
            {
                for(int b=0; b<n; ++b)
                    cout<<visited[a][b]<<' ';
                cout<<endl;
            }
            cout<<que.back().pi<<' '<<que.back().pj<<endl;
        }
        if(i-1>=0 && !visited[i-1][j])
            que.push(POSITION(i-1, j, d+1));
        if(i+1<m && !visited[i+1][j])
            que.push(POSITION(i+1, j, d+1));
        if(j-1>=0 && !visited[i][j-1])
            que.push(POSITION(i, j-1, d+1));
        if(j+1<n && !visited[i][j+1])
            que.push(POSITION(i, j+1, d+1));
        que.pop();
        if(i == 4 && j == 4)
        cout<<que.back().pi<<' '<<que.back().pj<<' '<<que.back().day<<endl;
    }
	return -1;
}



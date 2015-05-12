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
     ÿ�������������������N,M,T(0<n, m��20, t>0)��ͷ���ֱ�����Թ��ĳ��͸ߣ��Լ������ܼ�ֵ�������
	 ��������M�У�N���ַ�����"."��"*"��"P"��"S"��ɡ����� "." �����ܹ����ߵĿյء� "*" ����ǽ�ڣ�Jesse���ܴӴ�ͨ����
	 "P" �ǹ������ڵ�λ�á� "S" ��Jesse����ʼλ�á� ÿ��ʱ�����Jesseֻ��ѡ���ϡ��¡����ҡ�����һ������һ����
Prototype
     int SSaveP (int *maze[], int M, int n, int t)
Input Param
     maze            �Թ����֣������ö�ά����ʵ�ֲ��֣�
	 M               �Թ������飩����
     N               �Թ������飩����
	 T               �����ܼ�ֵ�����
Output Param
                     ��
Return Value
     0         ���Ծȳ�����
     -1        �����Ծȳ�����

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
	// ��������Ӻ�������
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



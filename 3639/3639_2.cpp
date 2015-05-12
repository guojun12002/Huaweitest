#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int G[35][35]={};
#define max 30000;
char s[35][5]=
{
	"A1","A2","A3","A4","A5","A6","A7","A8","A9","T1","A10","A11","A12","A13","T2","A14","A15","A16","A17","A18","B1","B2","B3","B4","B5","B6","B7","B8","B9","B10","B11","B12","B13","B14","B15"
};
void setup()
{
	for(int i=0;i<35;i++)
		for(int j=i;j<35;j++)
		{
			if(j==i)
				G[i][j]=0;
			else if(j==i+1)
			{
				G[i][j]=1;
				G[j][i]=1;
			}
			else
			{
				G[i][j]=max;
				G[j][i]=max;
			}
		}
	G[0][19]=1;G[19][0]=1;
	G[9][24]=1;G[24][9]=1;G[9][25]=1;G[25][9]=1;
	G[14][29]=1;G[29][14]=1;G[14][30]=1;G[30][14]=1;
	G[19][20]=max;G[20][19]=max;
	G[24][25]=max;G[25][24]=max;
	G[29][30]=max;G[30][29]=max;
}

void Floyd()
{
	for(int k=0;k<35;k++)
	{
		for(int i=0;i<35;i++)
		{
			for(int j=0;j<35;j++)
			{
				int temp=G[i][k]+G[k][j];
				if(G[i][j]>temp)
					G[i][j]=temp;
			}
		}
	}
}
int search(string& str)
{
	for(int i=0;i<35;i++)
		if(str.compare(s[i])==0) return i;
}
int main()
{
	freopen("input.txt","r",stdin);
	setup();
	Floyd();
	string str1,str2;
	while(cin>>str1>>str2)
	{
		cout<<G[search(str1)][search(str2)]+1<<endl;
	}
	return 0;
}
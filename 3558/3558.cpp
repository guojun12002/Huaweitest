#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

char p[23][23]={};
bool q[23][23]={};

bool find(char* S, int i, int j)
{
	if(*S=='\0') return true;
	if(q[i][j])
		return false;
	else
	{
		if(isalpha(p[i][j]))
		{
			if(*S==p[i][j])
			{
				q[i][j]=true;
				if(find(S+1,i-1,j))
					return true;
				else if(find(S+1,i+1,j))
					return true;
				else if(find(S+1,i,j-1))
					return true;
				else if(find(S+1,i,j+1))
					return true;
				else
				{
					q[i][j]=false;
					return false;
				}
			}
			else
				return false;
		}
		else
			return false;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int n,m;
	const char *yes="YES";
	const char *no="NO";
	bool flag=false;
	while(cin>>n>>m)
	{
		char str[101];
		cin>>str;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>p[i][j];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(find(str,i,j))
				{
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) cout<<yes<<endl;
		else cout<<no<<endl;

	}
	return 0;
}
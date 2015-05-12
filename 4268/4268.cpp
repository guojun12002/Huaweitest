#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
// #include "source/"
typedef long long LL;

int query(int* score, int id1, int id2)
{
	if(id1 > id2)
	{
		id1 = id1 ^ id2;
		id2 = id2 ^ id1;
		id1 = id1 ^ id2;
	}
	int max = score[id1];
	for(int i=id1+1; i<=id2; ++i)
		if(max < score[i]) max = score[i];
	return max;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int N, M;
	char C;
	while(cin>>N>>M)
	{
		int* score = new int[N];
		for(int i=0; i<N; ++i)
			cin>>score[i];
		for(int i=0; i<M; ++i)
		{
			int A, B;
			cin>>C>>A>>B;
			switch(C)
			{
				case 'Q': cout<<query(score, A, B)<<endl; break;
				case 'U': score[A] = B; break;
				default: break;
			}
		}
		delete[] score;
	}
	return 0;
}
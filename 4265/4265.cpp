#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
// #include "source/"
typedef long long LL;

int N;
int MAX(int a, int b)
{
	return a > b ? a : b;
}
int longup(int* t, int mid)
{
	if(NULL == t) return 0;
	if(mid == 0) return 1;
	int* s = new int[N];
	s[0] = 1;
	int max = 0;
	for(int i=1; i<=mid; ++i)
	{
		s[i] = 1;
		for(int j=i-1; j>=0; --j)
		{
			if(t[i] > t[j]) s[i] = MAX(s[i], s[j]+1);
			max = MAX(max, s[i]);
		}
	}
	delete[] s;
	return max;
}
int longdown(int* t, int mid)
{
	if(NULL == t) return 0;
	if(mid == N-1) return 1;
	int* s = new int[N];
	s[mid] = 1;
	int max = 0;
	for(int i=mid+1; i<N; ++i)
	{
		s[i] = 1;
		for(int j=i-1; j>=mid; --j)
		{
			if(t[i] < t[j]) s[i] = MAX(s[i], s[j]+1);
			max = MAX(max, s[i]);
		}
	}
	delete[] s;
	return max;
}
int main()
{
	freopen("input.txt", "r", stdin);
	while(cin >> N)
	{
		int* T = new int[N];
		for(int i=0; i<N; ++i)
			cin >> T[i];
		int max = longup(T, 0) + longdown(T, 0);
		for(int i=1; i<N; ++i)
			max = MAX(max, longup(T, i)+longdown(T, i));
		cout << N - max +1 << endl;
		delete[] T;
	}
	return 0;
}
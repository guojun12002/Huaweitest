#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"

void res(char* s)
{
	int l = strlen(s);
	for(int i=0; i<l/2; ++i)
	{
		char c = s[i];
		s[i] = s[l-i-1];
		s[l-i-1] = c;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	char A[105], B[105];
	cin >> A >> B;
	res(A);
	res(B);
	bool c = false;
	char *a = A;
	char *b = B;
	int result[105];
	int r = 0;
	while(*a != '\0' && *b != '\0')
	{
		int n = *a - '0' + *b - '0';
		if(c) ++n;
		if(n>9) c = true;
		else c = false;
		result[r++] = n % 10;
		++a;
		++b;
	}
	char* x = (*a != '\0') ? a : b;
	while(*x != '\0')
	{
		int n = *x - '0';
		if(c) ++n;
		if(n>9) c = true;
		else c = false;
		result[r++] = n%10;
		++x;
	}
	if(c) result[r++] = 1;
	for(int i=0; i<r; ++i)
		printf("%d", result[r-i-1]);
	printf("\n");
	return 0;
}
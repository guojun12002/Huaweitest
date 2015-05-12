#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
// #include "source/"
typedef long long LL;
const int IO_BUF_SIZE=0x100000;
struct fastio
{
	char inbuf[IO_BUF_SIZE];
	char outbuf[IO_BUF_SIZE];
	fastio()
	{
		setvbuf(stdin, inbuf, _IOFBF, IO_BUF_SIZE);
		setvbuf(stdout, outbuf, _IOFBF, IO_BUF_SIZE);
	}
}io;


int main()
{
	freopen("input.txt", "r", stdin);
	int num;
	while(cin >> num)
	{
		if(num<0)
		{
			cout<<-1<<endl;
			break;
		}
		do
		{
			int n = 0;
			do
			{
				n += num%10;
				num /= 10;
			}while(num > 0);
			num=n;
		}while(num>9);
		printf("%d\n", num);
	}
	return 0;
}
#include "source/IPAddressValid.cpp"
using namespace std;
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
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	char str[20];
	while(gets(str)!=NULL)
		printf("%d\n", isIPAddressValid(str));
	return 0;
}
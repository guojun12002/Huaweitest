#include "source/OJ.cpp"
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
	char input[1024],output[1024];
	while(gets(input) != NULL)
	{
		cout<<GetResult(input, output);
		cout<<output<<endl;
	}
	return 0;
}
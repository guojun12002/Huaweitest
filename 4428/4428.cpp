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


char str[100];
int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	char* output=NULL;
	while(gets(str)!=NULL)
	{
		cout<<Continumax(&output, str)<<endl;
		cout<<output<<endl;
	}

	return 0;
}
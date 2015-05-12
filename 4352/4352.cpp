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
	freopen("input.txt", "r", stdin);
	size_t num;
	while(cin>>num)
		cout<<Bonus(num)<<endl;
	return 0;
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
// #include "source/"
typedef long long LL;


int main()
{
	freopen("input.txt", "r", stdin);
	int num;
	while(cin >> num)
	{
		if(num == 0) break;
		int sum = 0;
		for(int i=0; i<=100; ++i)
			if(i*100 > num) break;
			else for(int j=0; j<=100-i; ++j)
				if(i*100+j*50 > num) break;
				else for(int k=0; k<=100-i-j; ++k)
						if(i*100+j*50+k*20 > num) break;
						else for(int l=0; l<=100-i-j-k; ++l)
							if(i*100+j*50+k*20+l*10 > num) break;
							else for(int m=0; m<=100-i-j-k-l; ++m)
								if(i*100+j*50+k*20+l*10+m*5 > num) break;
								else for(int n=0; n<=100-i-j-k-l-m; ++n)
									if(i*100+j*50+k*20+l*10+m*5+n*2 > num) break;
									else for(int o=0; o<=100-i-j-k-l-m-n; ++o)
									{
										if(i*100+j*50+k*20+l*10+m*5+n*2+o > num) break;
										if(i*100+j*50+k*20+l*10+m*5+n*2+o == num)
											++sum;
									}
		cout << sum << endl;
	}
	return 0;
}
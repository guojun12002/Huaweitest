#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;

void swap(char& S1,char& S2,int& N1,int& N2)
{
	S1=S1^S2;
	S2=S2^S1;
	S1=S1^S2;
	N1=N1^N2;
	N2=N2^N1;
	N1=N1^N2;
}
int sameA(int N1,int N2)
{
	if(N1==N2) return 0;
	if(N2>13)
		return abs(N2-N1)+3;
	else if(N2>9)
		return abs(N2-N1)+2;
	else
		return abs(N2-N1)+1;

}
int sameB(int N1,int N2)
{
	if(N1==N2) return 0;
	if(N2>10)
		return abs(N2-N1)+3;
	else if(N2>5)
		return abs(N2-N1)+2;
	else
		return abs(N2-N1)+1;
}
int main()
{
	freopen("input.txt","r",stdin);
	string str1,str2;
	while(cin>>str1>>str2)
	{
		char S1=str1[0], S2=str2[0];
		int N1=atoi(str1.substr(1).c_str()), N2=atoi(str2.substr(1).c_str());
		if(S1==S2&&S1=='A')
		{
			cout<<sameA(N1,N2)<<endl;
		}
		else if(S1==S2&&S1=='B')
		{
			cout<<sameB(N1,N2)<<endl;
		}
		else if(S1==S2&&S1=='T')
		{
			cout<<6<<endl;
		}
		else if(S1=='T' || S2=='T')
		{
			if(S2='T') swap(S1,S2,N1,N2);
			if(S1=='T')
				if(N1==1)
					if(S2=='A')
						cout<<sameA(10,N2)-1<<endl;
					else
						cout<<sameB(6,N2)-1<<endl;
				else
		}

	}
	return 0;
}
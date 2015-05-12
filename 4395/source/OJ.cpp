#include <stdlib.h>
#include "oj.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
char change[1000];
char* p = "ECFAJKLBDGHIVWZYMNOPQRSTUX";
char* q = "erwqtyghbnuiopsjkdlfazxcvm";
void ch()
{
	for(int i='A'; i<='Z'; ++i)
		change[i] = p[i-'A'];
	for(int i='a'; i<='z'; ++i)
		change[i] = q[i-'a'];
}
char* CharReplace(char* pSourceChar)
{
	ch();
	for(int i=0; i<strlen(pSourceChar); ++i)
		if(isalpha(pSourceChar[i]))
			pSourceChar[i] = change[pSourceChar[i]];
	return pSourceChar;
}
#include <stdlib.h>
#include "oj.h"


unsigned int  GetLastThreeNumOfResult (unsigned int  m, unsigned int  n)
{
	unsigned int num = 1;
	for(unsigned int i=0; i<n; ++i)
		num = ((LL)num * (LL)m) % 1000;
	return num;
}
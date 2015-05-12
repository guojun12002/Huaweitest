
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	int pArray[2][4] = {2,3,4,5,3,7,8,10};
	RangeArray(&pArray[0][0],2,4,1);
	print(&pArray[0][0], 2, 4);
	return 0;
}
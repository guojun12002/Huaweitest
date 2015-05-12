
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	int aInputInteger[] = {1, 2, 1, 5, 4, 5, 1};
	int iMaxValue, iMaxNum, iMinValue, iMinNum;

	OutputMaxAndMin(aInputInteger, 7, &iMaxValue, &iMaxNum, &iMinValue, &iMinNum);
	cout<<iMaxValue<<' '<<iMaxNum<<endl;
	cout<<iMinValue<<' '<<iMinNum<<endl;
	return 0;
}
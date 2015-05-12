
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	int  aData[] = {1, 2, 4, 7, 11, 15};
	int  iNum1, iNum2;
	cout<<FindTwoNumbersWithSum(aData, 6, 15, &iNum1, &iNum2)<<endl;
	cout<<iNum1<<endl;
	cout<<iNum2<<endl;
	return 0;
}
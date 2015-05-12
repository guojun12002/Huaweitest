
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	double Ret;
	int M = 4;
	int N = 20;
	int paper_type_value[][2] = {{4,10},{5,22},{10,3},{1,2}};
	GetMaxValue(M, N,paper_type_value, &Ret);

	cout<<Ret<<endl;
	return 0;
}
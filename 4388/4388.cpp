
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	char str[256];
	removechars("helloworld", 'c', str);
	cout<<str<<endl;
	removechars("ccccccccc", 'c', str);
	cout<<strcmp(str, "")<<endl;
	return 0;
}
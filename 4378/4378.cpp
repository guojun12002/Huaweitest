
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
	int N = 5;
	int M = 5; 
	int T = 10;
	char a[5][5] = {
		'.', '.', '.', '.', '.',
		'.', '.', '*', '.', '.',
		'.', '.', '.', '.', '.',
		'.', '*', '*', '*', '.',
		'S', '*', '*', 'P', '.'};
    char *p = &a[0][0];
	int  Ret;
	Ret = SSavep(p, T, N, M);
	CPPUNIT_ASSERT(Ret == 0);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	return 0;
}
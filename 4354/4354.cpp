
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
	int a[6][2] = {{1000,5},{800,2},{400,5},{300,5},{400,3},{200,2}} ;
	int *p = &a[0][0];
	int GetNumber = 0;
	GetResult(p,GetNumber);
	CPPUNIT_ASSERT(3900 == GetNumber);
}
void TestCase02()
{
	int a[16][2] = {{4000,15},{821,3},{422,5},{458,5},{500,3},{200,2},{430,4},{530,3},{239,3},{630,4},{500,2},{220,3},{430,3},{400,5},{400,5},{500,3}};
	int *p = &a[0][0];
	int GetNumber = 0;
	GetResult(p,GetNumber);
	CPPUNIT_ASSERT(16393 == GetNumber);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	TestCase02();
	return 0;
}
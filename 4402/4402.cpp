
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01_1()
{
	return CPPUNIT_ASSERT(Game24Points(7, 2, 1, 10) == true);
}

void TestCase01_2()
{
	return CPPUNIT_ASSERT(Game24Points(1, 2, 3, 4) == true);
}

void TestCase01_3()
{
	return CPPUNIT_ASSERT(Game24Points(7, 7, 7, 7) == false);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01_1();
	TestCase01_2();
	TestCase01_3();
	return 0;
}
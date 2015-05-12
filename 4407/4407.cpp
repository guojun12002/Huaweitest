
#include "source/steven.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
	int pw[] = {
		19, 7, 5, 6, 1};
	int pm[] = {
		15, 13, 7, 8, 2};
	int ret = CalcMaxNum(5,	pw, pm);
	CPPUNIT_ASSERT(ret == 4);
}
void TestCase02()
{
	int pw[] = {
		1, 1, 1, 1, 1};
	int pm[] = {
		2, 1, 1, 1, 1};
	int ret = CalcMaxNum(0,	pw, pm);
	cout<<ret<<endl;;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase02();
	return 0;
}
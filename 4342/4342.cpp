
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
    int  iRet;

    iRet = PlaceQueenMethodNum(8);
    cout<<iRet<<endl;
    // CPPUNIT_ASSERT(iRet == 0);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	return 0;
}
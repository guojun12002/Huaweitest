
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
		int iRet = 0;
	string sExpectedResult = "30";
	string strResult = "";

    iRet = multiply("300", "6", strResult);
    cout<<strResult<<endl;
 //    CPPUNIT_ASSERT(0 == iRet);
	// CPPUNIT_ASSERT(sExpectedResult == strResult);
	return 0;
}
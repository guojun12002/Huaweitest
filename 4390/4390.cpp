
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	AddString("434353f");
	AddString("ABCDEFG1234");
	AddString("1234567890");

	char strRst[][9] = {"434353f0","ABCDEFG1","23400000","12345678","90000000"};

	CPPUNIT_ASSERT(5 == GetLength());
	CPPUNIT_ASSERT(0 == ArrCmp(strRst,5));
	return 0;
}
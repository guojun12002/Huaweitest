
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	char szSource[] = "Ilttabaje zaujljg#";
 	char szResult[] = "Different meaning#";
	char* pResult = CharReplace(szSource);
	cout<<pResult<<endl;
 	CPPUNIT_ASSERT(0 == strcmp(szResult, pResult));
	return 0;
}
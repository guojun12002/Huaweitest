
#include "source/Degressive.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	CPPUNIT_ASSERT(getMaxDegressiveNum(95345323)==953);
	return 0;
}
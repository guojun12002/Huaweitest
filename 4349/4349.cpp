
#include "source/cellulardistrict.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	InitCellularDistrict(61);
 	cout<<GetShortestPathLength(40, 51)<<endl;
	return 0;
}
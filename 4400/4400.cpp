
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	char *p;
    p = (char *)malloc(1000);
    CalcNN(13, p);
    CPPUNIT_ASSERT(0 == strcmp(p, "6227020800"));
    free(p);
	return 0;
}
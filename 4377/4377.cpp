
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	char *input[] = {"10 10 10 10 10 10 9 xiaoyuanwang","0 0 0 0 0 0 0 beast"};
	char result[100] = {0};
	GetResult(input, 2, result);
	CPPUNIT_ASSERT(0 == strcmp(result, "xiaoyuanwang 10.00\nbeast 0.00") );
	cout<<result;
	return 0;
}
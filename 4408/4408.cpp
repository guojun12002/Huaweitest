
#include "source/sqlist.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	int maxNum = 5;
	char *outSeq = "31245";
	CPPUNIT_ASSERT(1 == JudgeTrainSequence(maxNum, outSeq));
	return 0;
}
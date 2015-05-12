
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	int InMinSeq = 2;
    int InMaxSeq = 10;
    int InNumbLen = 5;
	char InChaStr[30] = "bdfij";

	char pBufOutData[1024] = {0};

    GetResult(InMinSeq, InMaxSeq, InNumbLen, InChaStr, pBufOutData);

	CPPUNIT_ASSERT(0 == strcmp( pBufOutData,"bdghi\nbdghj\nbdgij\nbdhij\nbefgh"));
	return 0;
}
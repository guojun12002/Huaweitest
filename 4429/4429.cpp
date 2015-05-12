
#include "source/findsimilarword.cpp"
char *Test_Word[7] = {
    "mock",
    "aabc",
    "abc",
    "ckom",
    "bcaa",
    "abca",};
void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
    AddOneWord(Test_Word[0]);
    AddOneWord(Test_Word[1]);
    AddOneWord(Test_Word[2]);
    AddOneWord(Test_Word[3]);
    AddOneWord(Test_Word[4]);
    AddOneWord(Test_Word[5]);

    int Expectnumber = 1;
    int ActualNumber;
    int Ret;

    ActualNumber = FindSimilarWordNum (Test_Word[0]);
    CPPUNIT_ASSERT(Expectnumber == ActualNumber);

    char *ExpectWord = {"bcaa"};
    char SimilarWord[51] = {'\0'};
    int Seq = 2;
    Ret = FindOneSimilarWord (Test_Word[1], Seq, SimilarWord);
    CPPUNIT_ASSERT(0 == Ret);
    CPPUNIT_ASSERT(!memcmp(ExpectWord, SimilarWord, strlen(ExpectWord) + 1));
}

int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	return 0;
}
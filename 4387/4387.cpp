
#include "source/decrease.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
// 用例1:
void TestCase01()
{
    const char * pMinuend = "85";
    const char * pSubtrahend = "79";
    char * pResult = NULL;
    Decrease(pMinuend, pSubtrahend, &pResult);
    CPPUNIT_ASSERT(pResult != NULL);
    CPPUNIT_ASSERT(strcmp(pResult, "6") == 0);
    free(pResult);
}


// 用例2:
void TestCase02()
{
    const char * pMinuend = "8.5";
    const char * pSubtrahend = "0.91";
    char * pResult = NULL;
    Decrease(pMinuend, pSubtrahend, &pResult);
    CPPUNIT_ASSERT(pResult != NULL);
    CPPUNIT_ASSERT(strcmp(pResult, "7.59") == 0);
    free(pResult);
}

// 用例3:
void TestCase03()
{
    const char * pMinuend = "8.5";
    const char * pSubtrahend = "7.5";
    char * pResult = NULL;
    Decrease(pMinuend, pSubtrahend, &pResult);
    CPPUNIT_ASSERT(pResult != NULL);
    CPPUNIT_ASSERT(strcmp(pResult, "1") == 0);
    free(pResult);
}

// 用例4:
void TestCase04()
{
    const char * pMinuend = "12.34";
    const char * pSubtrahend = "17.24";
    char * pResult = NULL;
    Decrease(pMinuend, pSubtrahend, &pResult);
    CPPUNIT_ASSERT(pResult != NULL);
    CPPUNIT_ASSERT(strcmp(pResult, "-4.9") == 0);
    free(pResult);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	char * p = NULL;
	TestCase01();
	TestCase02();
	TestCase03();
	TestCase04();
	Decrease("10.009", "10.0101", &p);
	cout<<p<<endl;
	Decrease("10.0101", "10.009", &p);
	cout<<p<<endl;
	Decrease("9.0191", "9.0101", &p);
	cout<<p<<endl;
	Decrease("9.0101", "9.0191", &p);
	cout<<p<<endl;
	Decrease("0.5", "0", &p);
	cout<<p<<endl;
	Decrease("0", "0.5", &p);
	cout<<p<<endl;
	free(p);
	return 0;
}
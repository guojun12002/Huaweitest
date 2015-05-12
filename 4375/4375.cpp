
#include "source/polynomialmultiple.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
    char InputString1[] = "7X^4";
    char InputString2[] = "-7X^4";
    char *OutputString = NULL;

    OutputString = (char*)malloc(40000);
    memset(OutputString,0,40000);

    PolynomialMultiple(InputString1,InputString2,OutputString);
    
    CPPUNIT_ASSERT(strcmp(OutputString, "-49X^8") == 0);

    free(OutputString);
}
void TestCase02()
{
    char InputString1[] = "7X^4-5X^3+3X^3+1X^0";
    char InputString2[] = "-7X^4+5X^3-3X^3+3X^3+1X^0";
    char *OutputString = NULL;

    OutputString = (char*)malloc(40000);
    memset(OutputString,0,40000);

    PolynomialMultiple(InputString1,InputString2,OutputString);
    
    CPPUNIT_ASSERT(strcmp(OutputString, "-49X^8+49X^7-10X^6+3X^3+1X^0") == 0);

    free(OutputString);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	TestCase02();
	return 0;
}
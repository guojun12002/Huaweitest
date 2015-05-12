
#include "source/Polynomial.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	char *InputString = "-7X^4+5X^6-3X^3+3X^3+1X^0-5X^6-1X^0";
    char *OutputString = NULL;

    OutputString = (char*)malloc(strlen(InputString)+2);
    memset(OutputString,0,strlen(InputString)+2);

    OrderPolynomial(InputString,OutputString);
    cout<<OutputString<<endl;
    // CPPUNIT_ASSERT(strcmp(OutputString, "-5X^6+7X^4+3X^3") == 0);

    free(OutputString);
	return 0;
}
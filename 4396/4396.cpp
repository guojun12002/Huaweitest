
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	ELEMENT_STRU  astElement[2];
	unsigned int  uiIutputLen;
	unsigned char aucIutput[2];
	
	uiIutputLen = 2;
	aucIutput[0] = 0x62;
	aucIutput[1] = 0x80;
	astElement[0].uiElementLength = 4;
	astElement[1].uiElementLength = 5;

	Decode(uiIutputLen, aucIutput, 2, astElement);

	CPPUNIT_ASSERT(astElement[0].uiElementValue == 6);
	CPPUNIT_ASSERT(astElement[1].uiElementValue == 5);
	return 0;
}
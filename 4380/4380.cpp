
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}

void TestCase01()
{
	SetPlayerNum(4);
	unsigned int nResult = GetPlayerOut(1);
	CPPUNIT_ASSERT(3 == nResult);

	nResult = GetPlayerOut(4);
	CPPUNIT_ASSERT(4 == nResult);

	nResult = GetPlayerOut(16);
	CPPUNIT_ASSERT(2 == nResult);

	nResult = GetPlayerOut(6);
	CPPUNIT_ASSERT(1 == nResult);


	GameOver();
}
void TestCase02()
{
	SetPlayerNum(1);
	unsigned int nResult = GetPlayerOut(9999);
	CPPUNIT_ASSERT(1 == nResult);


	GameOver();
}
void TestCase03()
{
	SetPlayerNum(4);
	CPPUNIT_ASSERT (3 == GetPlayerOut (8)); 
	CPPUNIT_ASSERT (4 == GetPlayerOut (4)); 
	CPPUNIT_ASSERT (2 == GetPlayerOut (16)); 
	CPPUNIT_ASSERT (1 == GetPlayerOut (2)); 

	GameOver();
}

void TestCase04()
{
	SetPlayerNum(30);
	CPPUNIT_ASSERT (2 == GetPlayerOut (69)); 
	CPPUNIT_ASSERT (4 == GetPlayerOut (699)); 
	CPPUNIT_ASSERT (6 == GetPlayerOut (1399)); 
	GameOver();
}
void TestCase05()
{
	SetPlayerNum(8);
	CPPUNIT_ASSERT (7 == GetPlayerOut (1)); 
	CPPUNIT_ASSERT (1 == GetPlayerOut (16)); 
	GameOver();
}

int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	TestCase02();
	TestCase03();
	TestCase04();
	TestCase05();
	return 0;
}
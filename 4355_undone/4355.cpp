
#include "source/maze.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
    int CycleCount = 0;
    CPPUNIT_ASSERT(FindLongestCycle("maze1.txt", &CycleCount) == 16);
    CPPUNIT_ASSERT(CycleCount == 2);    
}

void TestCase02()
{
	int CycleCount = 0;
	CPPUNIT_ASSERT(FindLongestCycle("maze2.txt", &CycleCount) == -1);
	CPPUNIT_ASSERT(CycleCount == 0);    
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	// TestCase02();
	return 0;
}
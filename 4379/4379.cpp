
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}

void TestCase01()
{
	unsigned horse_num=6;
	unsigned int speed_yanzi[]={2,3,3,4,5,1};
	unsigned int speed_opp[]={5,4,3,2,1,2};
	char* aResult=IsYuanziWin(horse_num,speed_yanzi,speed_opp);

	CPPUNIT_ASSERT(strcmp(aResult,"YES")==0);
}


// 在这里添加测试用例实现
 void TestCase02()
 {
	 unsigned horse_num=5;
	 unsigned int speed_yanzi[]={6,8,9,4,5};
	 unsigned int speed_opp[]={6,8,9,7,6};
	 char * aResult=IsYuanziWin(horse_num,speed_yanzi,speed_opp);

	 CPPUNIT_ASSERT(strcmp(aResult,"NO")==0);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	TestCase02();
	return 0;
}
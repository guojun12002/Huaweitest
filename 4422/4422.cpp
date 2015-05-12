
#include "source/findminimalpath.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
    unsigned int Line1[] = {1,2,3,4,5};
    int Ret;

    AddLine(1,5,&Line1[0]);

    Ret = CalcMinPathLen(2,4);
    CPPUNIT_ASSERT(2 == Ret);

    Clear();
}
void TestCase02()
{
    unsigned int Line1[] = {1,2,3,4,5};
    unsigned int Line2[] = {1,10,9,7,6};
    unsigned int Line3[] = {5,7,8,2};
    unsigned int Line4[] = {11,5};
    int Ret;

    AddLine(1,5,Line1);
    AddLine(2,5,Line2);
    AddLine(3,4,Line3);
    AddLine(4,2,Line4);

    // Ret = CalcMinPathLen(1,7);
    // cout<<Ret<<endl;
    // Ret = CalcMinPathLen(7,1);
    // cout<<Ret<<endl;
    // Ret = CalcMinPathLen(1,5);
    // cout<<Ret<<endl;
    // Ret = CalcMinPathLen(5,1);
    // cout<<Ret<<endl;
    UI num=0,len=0;
    UI *p, *q;
    Ret = SearchMinPathes(1,11,&num,&len,&p);
    // cout<<Ret<<endl;
    cout<<num<<' '<<len<<endl;
    for(int i=0; i<num; ++i)
    {
      for(int j=0; j<len+1; ++j)
        cout<<p[i*(len+1)+j]<<' ';
      cout<<endl;
    }
    cout<<endl;
    Ret = SearchBestPathes(1,11,&num,&len,&q);
    cout<<num<<' '<<len<<endl;
    for(int i=0; i<num; ++i)
    {
      for(int j=0; j<=len; ++j)
        cout<<q[i*(len+1)+j]<<' ';
      cout<<endl;
    }
    Clear();
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// TestCase01();
	TestCase02();
	return 0;
}
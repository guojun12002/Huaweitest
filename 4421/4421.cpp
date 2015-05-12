
#include "source/filemanager.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
void TestCase01()
{
    CreateDir("root", "DirA");
    CreateFile("DirA", "File1");
    CPPUNIT_ASSERT(1 == GetFileNum("DirA"));
    Clear();
}
void TestCase02()
{
	cout<<CreateDir("root", "DirA")<<endl;
    cout<<CreateDir("root", "DirB")<<endl;
    cout<<CreateFile("DirA", "File1")<<endl;
    cout<<CreateFile("DirA", "File2")<<endl;
    cout<<CreateFile("DirA", "File3")<<endl;
    cout<<CreateFile("DirB", "File4")<<endl;
    cout<<CreateFile("DirB", "File5")<<endl;
    cout<<CreateFile("root", "File6")<<endl;
    cout<<CreateDir("root", "DirC")<<endl;
    cout<<CreateDir("DirC", "DirD")<<endl;
    cout<<CreateFile("DirD", "File7")<<endl;
    cout<<CreateFile("DirD", "File8")<<endl;
    cout<<CreateFile("DirD", "File9")<<endl;
    show(ROOT, 0);
    cout<<GetFileNum("DirC")<<endl;
    show(ROOT, 0);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	TestCase01();
	TestCase02();

	return 0;
}
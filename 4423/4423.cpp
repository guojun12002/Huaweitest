
#include "source/ObjMgt.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	cout<<AddObject(1, 2, 3)<<endl;
    cout<<AddObject(1, 2, 4)<<endl;
    cout<<AddObject(1, 5, 1)<<endl;
    cout<<AddObject(1, 5, 3)<<endl;
    cout<<AddObject(2, 3, 4)<<endl;
    cout<<AddObject(2, 3, 5)<<endl;
    cout<<AddObject(2, 4, 5)<<endl;
    cout<<AddObject(2, 3, 6)<<endl;
    cout<<AddObject(2, 3, 5)<<endl;		// -1
    cout<<IsObjectExist(1, 5, 3)<<endl; // 1
    DeleteObject(2, 3, 6);
    cout<<IsObjectExist(2, 3, 6)<<endl; // 0
    DeleteObject(2, 0xffffffff, 5);
    cout<<IsObjectExist(2, 3, 5)<<endl;	// 0
    DeleteObject(1, 0xFFFFFFFF, 0xFFFFFFFF);
    cout<<IsObjectExist(2, 3, 6)<<endl;	// 0
    cout<<AddObject(1, 2, 3)<<endl; // 0
    printall();
    cout<<IsObjectExist(1, 2, 3)<<endl; // 1
    // DeleteObject(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
    // Clear();
    printall();
	return 0;
}
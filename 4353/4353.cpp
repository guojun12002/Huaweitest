
#include "source/oj.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int C[3][3], ExpectC[3][3] = {{30, 36, 42}, {66, 81, 96}, {102, 126, 150}};
	matrix((int**)A, (int**)A, (int**)C, 3);
	// for(int i=0; i<3; ++i)
	// {
	// 	for(int j=0; j<3; ++j)
	// 		printf("%d ", C[i][j]);
	// 	printf("\n");
	// }
	CPPUNIT_ASSERT(0 == memcmp(C, ExpectC, sizeof(C)));
	return 0;
}
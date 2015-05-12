
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	int a[] = {4589, 101, 41425, 9999};
	int b[] = {32, 321};//32132
	int c[] = {32, 324};//32324
	int d[] = {32, 323};//32323
	int e[] = {321, 32};//32132
	int f[] = {324, 32};//32324
	int g[] = {323, 32};//32323
	char szRst[100]  = {0};
	smallestDigit(a,4,szRst);
	cout<<szRst<<endl;
	smallestDigit(b,2,szRst);
	cout<<szRst<<endl;
	smallestDigit(c,2,szRst);
	cout<<szRst<<endl;
	smallestDigit(d,2,szRst);
	cout<<szRst<<endl;
	smallestDigit(e,2,szRst);
	cout<<szRst<<endl;
	smallestDigit(f,2,szRst);
	cout<<szRst<<endl;
	smallestDigit(g,2,szRst);
	cout<<szRst<<endl;
	return 0;
}
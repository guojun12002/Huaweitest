
#include "source/encrypt.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	char password[] = "azAZ09!@#";
	char actual[101];
	char pass[101];
	Encrypt (password, actual);
	cout<<actual<<endl;
	unEncrypt(actual, pass);
	cout<<pass<<endl;
	return 0;
}
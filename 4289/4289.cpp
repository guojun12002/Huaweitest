#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
// #include "source/"
struct node
{
	char x;
	node *left, *right;
	node(char c):x(c),left(NULL),right(NULL){}
};
node* restore(char *sq)
{
	if(*sq == '\0' || sq == NULL) return NULL;
	node* root = new node(*sq);
	++sq;
	node* p = root;
	while(*sq != '\0')
	{
		if(*sq < p->x)
			if(p->left != NULL)
			{
				p = p->left;
				continue;
			}
			else
				p->left = new node(*sq);
		else if(*sq > p->x)
			if(p->right != NULL)
			{
				p = p->right;
				continue;
			}
			else
				p->right = new node(*sq);
		++sq;
		p = root;
	}
	return root;
}
string str, str1, str2;
void printall(node* root)
{
	if(NULL == root) return;
	str.push_back(root->x);
	printall(root->left);
	printall(root->right);
}
int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	while(cin >> n)
	{
		if(n == 0) break;
		char sq[20];
		cin >> sq;
		// cout<<sq<<endl;
		node* root = restore(sq);
		str.clear();
		printall(root);
		str1 = str;
		// cout<<str<<endl;
		for(int i=0; i<n; ++i)
		{
			char s[20];
			cin >> s;
			// cout<<s<<endl;
			node* r = restore(s);
			str.clear();
			printall(r);
			str2 = str;
			if(str1 == str2)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}
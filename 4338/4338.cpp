#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#include "source/sqlist.cpp"

void print(strlnode* p)
{
	strlnode* q;
	while(p != NULL)
	{
		cout<<p->data<<' ';
		if(p->pnext == NULL) q = p;
		p = p->pnext;
	}
	cout<<endl;
	while(q != NULL)
	{
		cout<<q->data<<' ';
		q =q->plast;
	}
	cout<<endl;
}
void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<1<<endl;
	else cout<<0<<endl;
}
int main()
{
	struct strlnode *plus;
	struct strlnode *p;
	struct strlnode *q;
	int b[] = {4,8,6,3,0,2,7,9,3,1,0,4,2,1,3,5,2,6};
	int a[] = {7,6,0,9,3,4,0,1,9,2,0,8,6,7,8,3,1,0,3,6,9,2,0,1,6,8};
	int j = 0;

	create(&plus, 0);
	create(&p, 0);
	create(&q, 0);

	readtolnode(&p, b, 18);
	readtolnode(&q, a, 26);

	bignumberplus(&plus, &p, &q);

	int result[26];
	writetosqlist(result, plus);
	int c[] = {7,6,0,9,3,4,0,2,4,0,7,1,7,0,6,2,4,1,4,1,1,3,3,6,9,4};

	for(j = 0; j < 26; j++)
	{
		CPPUNIT_ASSERT(result[j] == c[j]);
	}
	// print(p);
	return 0;
}
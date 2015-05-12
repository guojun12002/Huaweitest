#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "oj.h"
struct bignum
{
	char *p,*_p;
	int n;
	bool flag;

	bignum()
	{
		n=0;
		p=NULL;
		_p=NULL;
		flag=true;
	}
	bignum(const bignum &num)
	{
		if(num.p)
		{
			n=num.n;
			p=new char[n+1];
			_p=new char[n+1];
			memcpy(p,num.p,sizeof(char)*n+1);
			memcpy(_p,num._p,sizeof(char)*n+1);
			flag=num.flag;
		}
	}
	bignum(const bignum &num,const bool f)
	{
		if(num.p)
		{
			n=num.n;
			p=new char[n+1];
			_p=new char[n+1];
			memcpy(p,num.p,sizeof(char)*n+1);
			memcpy(_p,num._p,sizeof(char)*n+1);
			flag=f;
		}
	}
	bignum(const char* s,bool f=true)
	{
		n=strlen(s);
		p=new char[n+1];
		_p=new char[n+1];
		for(int i=0;i<n;i++)
			if(f)
			{
				p[i]=s[i];
				_p[i]=s[n-i-1];
			}
			else
			{
				_p[i]=s[i];
				p[i]=s[n-i-1];
			}
		p[n]='\0';
		_p[n]='\0';
		flag=true;
	}
	~bignum(){delete []p;delete []_p;}
	friend ostream& operator<<(ostream& , const bignum&);
	friend bignum operator+(const bignum&, const bignum&);
	friend bignum operator*(const bignum&, const bignum&);
	bignum& operator=(const bignum&);
	// bool getflag(){return flag;}
};
ostream& operator<<(ostream& out, const bignum& x)
{
	if(!x.flag) out<<'-';
	int i=0;
	while(x.p[i++]=='0');
	if(*(x.p+i-1)=='\0')
		out<<0;
	else
		out<<x.p+i-1;
	return out;
}
bignum& bignum::operator=(const bignum& num)
{
	if(p==num.p) return *this;
	if(num.p)
	{
		delete []p;
		delete []_p;
		n=num.n;
		p=new char[n+1];
		_p=new char[n+1];
		memcpy(p,num.p,sizeof(char)*n+1);
		memcpy(_p,num._p,sizeof(char)*n+1);
		flag=num.flag;
	}
	return *this;
}
bignum operator+(const bignum& num1,const bignum& num2)
{
	int len=num1.n>num2.n?num1.n:num2.n;
	char* r=new char[len+2];
	int c=0,i=0,j=0,k=0,temp=0;
	while(num1._p[i]!='\0'||num2._p[j]!='\0')
	{
		if(num1._p[i]=='\0')
		{
			temp=num2._p[j]-'0'+c;
			j++;
		}
		else if(num2._p[j]=='\0')
		{
			temp=num1._p[i]-'0'+c;
			i++;
		}
		else
		{
			temp=num1._p[i]-'0'+num2._p[j]-'0'+c;
			i++;j++;
		}
		r[k]=temp%10+'0';
		c=temp/10;
		k++;
	}
	if(c)
	{
		r[k]=c+'0';
		r[k+1]='\0';
	}
	else
		r[k]='\0';
	bignum result(r,false);
	delete []r;
	return result;
}
bignum operator*(const bignum& num1,const bignum& num2)
{
	if(num1.n<num2.n) return bignum(num2*num1);
	bignum* num=new bignum[num2.n];
	for(int j=0;j<num2.n;j++)
	{
		int c=0,temp=0;
		char* r=new char[num1.n+j+2];
		for(int i=0;i<j;i++)
			r[i]='0';
		for(int i=0;i<num1.n;i++)
		{
			temp=(num1._p[i]-'0')*(num2._p[j]-'0')+c;
			r[i+j]=temp%10+'0';
			c=temp/10;
		}
		if(c)
		{
			r[num1.n+j]=c+'0';
			r[num1.n+j+1]='\0';
		}
		else
			r[num1.n+j]='\0';
		num[j]=bignum(r,false);
		delete []r;
	}
	bignum sum(num[0]);
	for(int i=1;i<num2.n;i++)
		sum=sum+num[i];
	delete []num;
	return sum;
}
void CalcNN(int n, char *pOut)
{
	if(NULL == pOut || n == 0) return;
	bignum bn1("1");
	for(int i=2; i<=n; ++i)
	{
		string num;
		int m = i;
		while(m > 0)
		{
			num.insert(num.begin(), '0'+m%10);
			m /= 10;
		}
		// cout<<num<<endl;
		bignum bn2(num.c_str());
		bn1 = bn1 * bn2;
	}
	strcpy(pOut, bn1.p);
	return;
}
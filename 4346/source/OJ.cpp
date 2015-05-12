#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long LL;
#include "oj.h"
class bignum
{
	char *p,*_p;
	int n;
	bool flag;
public:
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
	char* output(char* str)
	{
		if(NULL == str) return NULL;
		int i=0;
		while(p[i++] == '0');
		if(*(p+i-1)=='\0')
			strcpy(str, "0");
		else
			strcpy(str,p+i-1);
		return str;
	}
	friend ostream& operator<<(ostream& , const bignum&);
	friend bignum operator+(const bignum&, const bignum&);
	friend bignum operator-(const bignum&, const bignum&);
	friend bignum operator*(const bignum&, const bignum&);
	friend bignum operator/(const bignum&, const bignum&);
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
bignum operator-(const bignum& num1,const bignum& num2)
{
	if(num1.n<num2.n) return bignum(num2-num1,false);
	if(num1.n==num2.n)
		for(int i=0;i<num1.n;i++)
		{
			if(num1.p[i]>num2.p[i]) break;
			if(num1.p[i]<num2.p[i]) return bignum(num2-num1,false);
		}
	int len=num1.n;
	char* r=new char[len+1];
	int i=0,j=0,c=0,temp=0;
	while(num1._p[i]!='\0')
	{
		if(num2._p[j]!='\0')
			temp=num1._p[i]-num2._p[j++]-c;
		else
			temp=num1._p[i]-'0'-c;
		if(temp<0)
		{
			temp+=10;
			c=1;
		}
		else
			c=0;
		r[i]=temp+'0';
		i++;
	}
	r[i]='\0';
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
bignum operator/(const bignum& num1,const bignum& num2)
{
	if(num1.n<num2.n) return bignum("0");
	if(num1.n==num2.n)
		for(int i=0;i<num1.n;i++)
		{
			if(num1.p[i]>num2.p[i]) break;
			if(num1.p[i]<num2.p[i]) return bignum("0");
		}
	char* r=new char[num1.n+1];
	int i=0,j=0;
	char* c=new char[num2.n+1];	//储存余数
	c[0]='\0';
	bignum n[10]={"0","1","2","3","4","5","6","7","8","9"}; //储存商
	while(num1.p[i]!='\0')
	{
		char* temp=new char[i-j+3];
		if(*c!='\0') strcpy(temp,c);
		strncat(temp,num1.p+i,1);
		char* t=temp;
		while(*t=='0') t++;
		for(int k=9;k>0;k--)
		{
			bignum n1(t);
			bignum n3=n1-num2*n[k];
			if(n3.flag)
			{
				r[i]=k+'0';
				strcpy(c,n3.p);
				j=i;
				break;
			}
			if(k==1)
			{
				r[i]='0';
				strcpy(c,n1.p);
				break;
			}
		}
		i++;
		delete []temp;
	}
	r[i]='\0';
	bignum result(r);
	delete []c;
	delete []r;
	return result;
}

/*****************************************************************************
 Prototype    : multiply
 Description  : 两个任意长度的长整数相乘, 输出结果
 Input Param  : 
                const std::string strMultiplierA  乘数A
                const std::string strMultiplierB  乘数B
 Output       : 
                std::string strRst            乘法结果
 Return Value : 
                int                       0  正确  
                                         -1  异常
*****************************************************************************/
int multiply (const std::string strMultiplierA,const std::string strMultiplierB, std::string &strRst) 
{

    /* 在这里实现功能 */
    if(strMultiplierA.empty() || strMultiplierB.empty()) return -1;
    bignum a(strMultiplierA.c_str());
    bignum b(strMultiplierB.c_str());
    char str[1000];
    // cout<<a*b<<endl;
    (a*b).output(str);
    strRst.assign(str);
    return 0;
}
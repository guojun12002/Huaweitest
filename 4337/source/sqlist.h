#include <stdlib.h>

#define maxsize 50

struct strsqlist
{ 
	int sqlist[maxsize];
 	int key;
 	int size;
 	int data;
};


void setnull(struct strsqlist *p);
int getlength(struct strsqlist *p);
int getelement(struct strsqlist *p,int i) ;
/******************************************************************************

Copyright (C), 2001-2013, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 2013/9
Last Modified :
Description   :
Function List :

History       :
1.Date        : 2013/9
Author      :
Modification: Created file

******************************************************************************/
#include "FileManager.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int MAX = 10000;
struct File
{
	char filename[MAX];
	File(){};
	File(const char* name)
	{
		strcpy(filename, name);
	}
};
struct DIR
{
	char dirname[MAX];
	int dirs, files;
	DIR* parentdir;
	DIR* dir[MAX];
	File* file[MAX];
	DIR(){};
	DIR(const char* name, DIR* parent)
	{
		strcpy(dirname, name);
		parentdir = parent;
		dirs = files = 0;
		for(int i=0; i<MAX; ++i)
		{
			dir[i] = NULL;
			file[i] = NULL;
		}
	}
	~DIR()
	{
		for(int i=0; i<dirs; ++i)
		{
			delete dir[i];
			dir[i] = NULL;
		}
		for(int i=0; i<files; ++i)
		{
			delete file[i];
			file[i] = NULL;
		}
	}
};
DIR* ROOT = new DIR("root", NULL);
void show(DIR* r, int n)
{
	for(int i=0; i<n; ++i)
		printf("    ");
	printf("%s %d %d\n", r->dirname, r->dirs, r->files);
	for(int i=0; i<r->dirs; ++i)
		show(r->dir[i], n+1);
	for(int i=0; i<r->files; ++i)
	{
		for(int j=0; j<n+1; ++j)
			printf("    ");
		printf("%s\n", r->file[i]->filename);
	}
}
DIR* searchDir(DIR* root, const char* dir)
{
	if(root == NULL || dir == NULL || dir[0] == '\0') return NULL;
	if(strcmp(root->dirname, dir) == 0) return root;
	for(int i=0; i<root->dirs; ++i)
	{
		DIR* p = searchDir(root->dir[i], dir);
		if(p != NULL) return p;
	}
	return NULL;
}
DIR* searchFile(DIR* root, const char* file)
{
	if(root == NULL || file == NULL || file[0] == '\0') return NULL;
	for(int i=0; i<root->files; ++i)
		if(strcmp(root->file[i]->filename, file) == 0)
			return root;
	for(int i=0; i<root->dirs; ++i)
	{
		DIR* d = searchFile(root->dir[i], file);
		if(d != NULL)
			return d;
	}
	return NULL;
}
int CreateDir(const char * ParentDirName, const char * DirName)
{
	if(ParentDirName == NULL || DirName == NULL || ParentDirName[0] == '\0' || DirName[0] == '\0') return -1;
	DIR* p = searchDir(ROOT, DirName);
	if(p != NULL) return -1;
	p = searchDir(ROOT, ParentDirName);
	if(p == NULL) return -1;
	p->dir[p->dirs] = new DIR(DirName, p);
	p->dirs += 1;
    return 0;
}

void DeleteDir(const char * DirName)
{
	if(NULL == DirName || DirName[0] == '\0' || strcmp("root", DirName) == 0) return;
	DIR* p = searchDir(ROOT, DirName);
	if(p != NULL)
	{
		p = p->parentdir;
		for(int i=0; i<p->dirs; ++i)
		{
			if(strcmp(p->dir[i]->dirname, DirName) == 0)
			{
				delete p->dir[i];
				for(int j=i; j<p->dirs-1; ++j)
					p->dir[j] = p->dir[j+1];
				p->dir[p->dirs-1] = NULL;
				p->dirs -= 1;
				break;
			}
		}
	}
    return;
}

int MoveDir(const char * SrcDirName, const char * DestDirName)
{
	if(NULL == SrcDirName || NULL == DestDirName || SrcDirName[0] == '\0' || DestDirName[0] == '\0') return -1;
	DIR* src = searchDir(ROOT, SrcDirName);
	DIR* dest = searchDir(ROOT, DestDirName);
	if(NULL == src || NULL == dest) return -1;
	DIR* p = searchDir(src, DestDirName);
	if(p != NULL) return -1;
	if(dest == src->parentdir) return -1;
	p = src->parentdir;
	for(int i=0; i<p->dirs; ++i)
	{
		if(p->dir[i] == src)
		{
			for(int j=i; j<p->dirs-1; ++j)
				p->dir[j] = p->dir[j+1];
			p->dir[p->dirs-1] = NULL;
			p->dirs -= 1;
			break;
		}
	}
	dest->dir[dest->dirs] = src;
	src->parentdir = dest;
	dest->dirs += 1;
    return 0;
}

int CreateFile(const char * DirName, const char * FileName)
{
	if(NULL == DirName || NULL == FileName || DirName[0] == '\0' || FileName[0] == '\0') return -1;
	DIR* p = searchFile(ROOT, FileName);
	if(p != NULL) return -1;
	p = searchDir(ROOT, DirName);
	if(p == NULL) return -1;
	// for(int i=0; i<p->files; ++i)
	// 	if(strcmp(p->file[i]->filename, FileName) == 0)
	// 		return -1;
	p->file[p->files] = new File(FileName);
	p->files += 1;
    return 0;
}

void DeleteFile(const char * FileName)
{
	if(FileName == NULL || FileName[0] == '\0') return;
	DIR* p = searchFile(ROOT, FileName);
	if(p != NULL)
	{
		for(int i=0; i<p->files; ++i)
			if(strcmp(p->file[i]->filename, FileName) == 0)
			{
				delete p->file[i];
				for(int j=i; j<p->files-1; ++j)
					p->file[j] = p->file[j+1];
				p->file[p->files-1] = NULL;
				p->files -= 1;
				break;
			}
	}
    return;
}
int getnum(DIR* root)
{
	if(root == NULL) return 0;
	int sum = root->files;
	for(int i=0; i<root->dirs; ++i)
		sum += getnum(root->dir[i]);
	return sum;
}
unsigned int GetFileNum(const char * DirName)
{
	if(NULL == DirName || DirName[0] == '\0')
		return 0;
	DIR* p = searchDir(ROOT, DirName);
	if(p == NULL) return 0;
	return getnum(p);
}

void Clear(void)
{
	for(int i=0; i<ROOT->dirs; ++i)
		delete ROOT->dir[i];
	for(int i=0; i<ROOT->files; ++i)
		delete ROOT->file[i];
	ROOT->dirs = 0;
	ROOT->files = 0;
	// delete ROOT;
	// ROOT = new DIR("root", NULL);
    return;
}

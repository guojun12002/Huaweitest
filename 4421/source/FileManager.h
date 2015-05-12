#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_


int CreateDir(const char * ParentDirName, const char * DirName);

void DeleteDir(const char * DirName);

int MoveDir(const char * SrcDirName, const char * DestDirName);

int CreateFile(const char * DirName, const char * FileName);

void DeleteFile(const char * FileName);

unsigned int GetFileNum(const char * DirName);

void Clear(void);

#endif

// FileManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

typedef struct FileNode {
	char fileName[20];
	float fileSize;
	struct FileNode *fileNext;
}FileNode, *FileList;

typedef struct FolderNode {
	char folderName[20];
	struct FolderNode *folderNext; // 下级目录文件
	struct FolderNode *next; // 同级目录文件
	struct FileNode *fileNext; // 同级文件
}FolderNode, *FolderList;

void CreateFile(FolderList &folderList)
{
	FolderNode *p = new FolderNode; // 
	FileNode *q = new FileNode; // 新增文件节点
	p = folderList;
	cout<<"输入文件名"<<endl;
	cin>>q->fileName;
	cout<<"输入文件大小"<<endl;
	cin>>q->fileSize;
	q->fileNext = p->fileNext;
	p->fileNext = q;
}

void CreateFolder(FolderList &folderList)
{
	FolderNode *p = new FolderNode;
	FolderNode *q = new FolderNode;
	p = folderList;
	cout<<"输入文件夹名"<<endl;
	cin>>q->folderName;
	q->folderNext = p->folderNext;
	p->folderNext = q;
}

void Init(FolderList &folderList)
{
	folderList->fileNext = NULL;
	folderList->folderNext = NULL;
	folderList->next = NULL;
}

void Print(FolderList &folderList)
{
	FolderNode *folderTemp = new FolderNode;
	FileNode *fileTemp = new FileNode;
	folderTemp = folderList->folderNext;
	fileTemp = folderList->fileNext;
	cout<<"文件列表输出"<<endl;
	cout<<"========================="<<endl;
	while(folderTemp)
	{
		cout<<"./"<<folderTemp->folderName<<endl;
		folderTemp = folderTemp->folderNext;
	}
	while(fileTemp)
	{
		cout<<fileTemp->fileName<<" "<<fileTemp->fileSize<<endl;
		fileTemp = fileTemp->fileNext;

	}
}

int main()
{
	FolderList root = new FolderNode; // 表根目录
	Init(root);
	CreateFile(root);
	CreateFile(root);
	CreateFolder(root);
	CreateFolder(root);
	Print(root);
	return 0;
}


// FileManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

typedef struct FileNode
{
	char filename[30];
	int filesize;
	FileNode *next;
}FileNode;

typedef struct FolderNode
{
	char foldername[20];
	FolderNode *folderlist;
	FileNode *filelist;
}FolderNode, *FolderLinkList;



void Init(FolderLinkList &folder)
{
	strcpy(folder->foldername, "root");
	folder->filelist = NULL;
	folder->folderlist = NULL;
}

void CreateFolder(FolderLinkList &folder)
{
	FolderNode *tempNode = new FolderNode;
	FolderNode *insertNode = new FolderNode;
	tempNode = folder;

	// 指向链表结尾处 保证每次插入元素在尾部
	while(tempNode->folderlist)
		tempNode = tempNode->folderlist;
	// 从键盘中录入信息
	cout<<"输入文件夹名"<<endl;
	cin>>insertNode->foldername;
	insertNode->folderlist = tempNode->folderlist;
	tempNode->folderlist = insertNode;
}

// 建立文件
void CreateFile(FolderLinkList &folder)
{
	FileNode *insertfile = new FileNode;
	// 从键盘中录入文件信息
	cout<<"输入文件名"<<endl;
	cin>>insertfile->filename;
	insertfile->next = folder->filelist;
	folder->filelist = insertfile;

}

void Print(FolderLinkList &folder)
{
	FolderNode *tempNode = new FolderNode;
	FileNode *tempFile = new FileNode;
	cout<<"当前目录位置 "<<folder->foldername<<endl;
	tempNode = folder->folderlist;
	tempFile = folder->filelist;
	cout<<"============"<<endl;
	while(tempNode)
	{
		cout<<"./"<<tempNode->foldername<<endl;
		
		tempNode = tempNode->folderlist;
	}
	while(tempFile)
	{
		cout<<tempFile->filename<<endl;
		tempFile = tempFile->next;
	}
}

int main()
{
	FolderLinkList folder = new FolderNode;
	Init(folder);
	CreateFolder(folder);
	//CreateFolder(folder);

	CreateFile(folder);
	CreateFile(folder);
	Print(folder);
	cout<<"下级目录"<<endl;
	return 0;
}

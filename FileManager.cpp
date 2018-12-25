// FileManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

typedef struct FileNode {
	char fileName[50];
	float fileSize;
	struct FileNode *fileNext;
}FileNode, *FileList;

typedef struct FolderNode {
	char folderName[50];
	struct FolderNode *folderNext; // 下级目录文件
	struct FolderNode *next; // 同级目录文件
	struct FileNode *fileNext; // 同级文件
}FolderNode, *FolderList;

FolderList AllDirectory = new FolderNode; // 全局目录指针

void CreateFile(FolderList &folderList, char fileName[], float fileSize)
{
	FolderNode *p = new FolderNode; // 
	FileNode *q = new FileNode; // 新增文件节点
	p = folderList;
	strcpy(q->fileName, fileName);
	q->fileSize = fileSize;
	q->fileNext = p->fileNext;
	p->fileNext = q;
}

void CreateFolder(FolderList &folderList, char folderName[])
{
	FolderNode *p = new FolderNode;
	FolderNode *q = new FolderNode;
	p = folderList;
	strcpy(q->folderName, folderName);
	q->folderNext = p->folderNext;
	p->folderNext = q;
}

void NextDirectory(FolderList &folderList)
{
//	folderList->folderNext = folderList->folderNext->folderNext;
}
void Print(FolderList &folderList)
{
	FolderNode *folderTemp = new FolderNode;
	FileNode *fileTemp = new FileNode;
	folderTemp = folderList->folderNext;
	fileTemp = folderList->fileNext;
	cout<<"文件列表输出"<<endl;
	cout<<"当前目录: ./"<<folderList->folderName<<endl;
	cout<<"==================================================="<<endl;
	
	while(folderTemp)
	{
		cout.setf(ios::left);
		cout.width(20);
		cout<<"./"<<folderTemp->folderName<<endl;
		folderTemp = folderTemp->folderNext;
	}
	while(fileTemp)
	{
		cout.setf(ios::left);
		cout.width(20);
		cout<<"  "<<fileTemp->fileName;
		cout.setf(ios::left);
		cout.width(20);
		cout<<"  "<<fileTemp->fileSize<<endl;
		fileTemp = fileTemp->fileNext;

	}
}

void Init(FolderList &folderList)
{
	strcpy(folderList->folderName, "root");
	folderList->fileNext = NULL;
	folderList->folderNext = NULL;
	folderList->next = NULL;
}

// 写出文件
void Write()
{
	ofstream outputfile("data.txt");
	if(!outputfile)
		cout<<"尝试打开文件流失败"<<endl;
	outputfile<<"Something_like_you.mp3 53.32 Seve.mp3 23.4 java python";
	outputfile.close();
}

// 读取文件
void Read(FolderList &folderList)
{
	char fileName[50], folderName[50];
	float fileSize;
	ifstream inputfile("data.txt");
	if(!inputfile)
		cout<<"尝试读取文件流失败"<<endl;
	while(!inputfile.eof())
	{
		inputfile>>fileName;
		inputfile>>fileSize;
		cout<<"read "<<fileName<<endl;
		cout<<"read "<<fileSize<<endl;

		CreateFile(folderList, fileName, fileSize);
		
		inputfile>>fileName;
		inputfile>>fileSize;
		cout<<"read "<<fileName<<endl;
		cout<<"read "<<fileSize<<endl;
		CreateFile(folderList, fileName, fileSize);

		inputfile>>folderName;
		CreateFolder(folderList, folderName);

		inputfile>>folderName;
		CreateFolder(folderList, folderName);
	}
}

int main()
{
	FolderList root = new FolderNode; // 表根目录
	AllDirectory = root;
	Init(root);
	Write();
	Read(root);
	CreateFile(root, "helloworld", 3.42);
	Print(root);
	NextDirectory(root);
	//Print(root);
	return 0;
}



// FileManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct FileNode
{
	char filename[50];
	int filesize;
}FileNode;

typedef struct DirectoryNode
{
	char dirname[50];
	FileNode *filelist;
	DirectoryNode *directorylist;
}DirectoryNode, DirectoryLink;

// 写出文件
void Write()
{
	ofstream outputfile("data.txt");
	if(!outputfile)
		cout<<"尝试打开文件流失败"<<endl;
	outputfile<<"Something.mp3 53.32 Seve.mp3 23.4 java python";
	outputfile.close();
}

// 读取文件
void Read()
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
		inputfile>>fileName;
		inputfile>>fileSize;
		inputfile>>folderName;
		inputfile>>folderName;
	}
}

int main()
{
	DirectoryNode *Dir = new DirectoryNode;
	strcpy(Dir->dirname, "root");
	strcpy(Dir->filelist->filename, "java");
	Dir->filelist->filesize = 20;

	return 0;
}

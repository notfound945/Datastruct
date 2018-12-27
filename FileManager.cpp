// FileManagerTool.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

typedef struct FileNode
{
	char filename[20];
	float filesize;
	char attribute[5];
	FileNode *next;
}FileNode;

typedef struct FolderNode 
{
	char foldername[20];
	FileNode *filelist;
	FolderNode *folderlist;
}FolderNode, *FolderLink;

// 初始化文件目录
void Init(FolderLink &folder)
{
	strcpy(folder->foldername, "root");
	folder->folderlist = NULL;
	folder->filelist = NULL;
}

// 查看当前目录
void PrintCurrent(FolderLink &folder)
{
	cout<<"========="<<endl;
	cout<<"查看当前目录"<<endl;
	cout<<endl<<"当前根目录: "<<folder->foldername<<endl;
	cout<<"===文件名===\t\t===文件大小===\t\t===文件类型==="<<endl;
	FolderNode *tempfolder = folder->folderlist;
	FileNode *tempfile = folder->filelist;
	if (!tempfolder && !folder->filelist)
		cout<<endl<<"==目录为空=="<<endl<<endl;
	while (tempfolder)
	{
		cout<<"./"<<tempfolder->foldername<<"\t\t\t\t\t\t文件夹"<<endl;
		tempfolder = tempfolder->folderlist;
	}
	while (tempfile)
	{
		cout<<tempfile->filename<<"\t\t\t"<<tempfile->filesize<<"\t\t\t文件"<<endl;
		tempfile = tempfile->next;
	}
	cout<<"任意键返回主菜单..."<<endl;
	system("pause>nul");
}

// 查看下层文件
void PrintLower(FolderLink &folder)
{
	cout<<"======="<<endl;
	cout<<"查看下层文件"<<endl;
	cout<<"==未实现此功能"<<endl;
	cout<<"任意键返回主菜单"<<endl;
	system("pause>>nul");
	return;
}

// 返回上层目录
void ReturnUper(FolderLink &folder)
{
	cout<<"========"<<endl;
	cout<<"返回上层目录"<<endl;
	cout<<"==未实现此功能"<<endl;
	cout<<"任意键返回主菜单"<<endl;
	system("pause>>nul");
	return;
}

// 返回根目录
void ReturnRoot(FolderLink &folder)
{
	cout<<"========"<<endl;
	cout<<"返回根目录"<<endl;
	cout<<"==未实现些功能"<<endl;
	cout<<"任意键返回主菜单"<<endl;
	system("pause>>nul");
	return;
}

// 新建文件
void NewFile(FolderLink &folder)
{
	char option[10]; // 判断是否添加文件
	cout<<"新建文件"<<endl;
	FileNode *insertNode = new FileNode;
	cout<<"========="<<endl;
	cout<<"请输入新建文件信息"<<endl;
	cout<<"文件名:";
	cin>>insertNode->filename;
	cout<<"文件大小:";
	cin>>insertNode->filesize;
	insertNode->next = folder->filelist;
	folder->filelist = insertNode;
	cout<<"文件新建成功，是否继续添加？y/n"<<endl;
	cin>>option;
	if (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0)
		NewFile(folder);
}

// 新建下层目录
void NewFolder(FolderLink &folder)
{
	char option[10]; // 判断是否继续添加文件夹
	cout<<"=========="<<endl;
	cout<<"新建下层目录"<<endl;
	FolderNode *tempNode = new FolderNode;
	FolderNode *insertNode = new FolderNode;
	tempNode = folder;
	cout<<"输入文件夹相关信息"<<endl;
	cout<<"文件名:";
	cin>>insertNode->foldername;
	insertNode->folderlist = tempNode->folderlist;
	tempNode->folderlist = insertNode;
	cout<<"文件夹新建成功，是否继续添加？y/n"<<endl;
	cin>>option;
	if (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0)
		NewFolder(folder);

}

// 更新文件信息
void UpdateFile(FolderLink &folder)
{
	char filename[20], option[10];
	bool flag = false;
	cout<<"更新文件信息"<<endl;
	cout<<"========="<<endl;
	FileNode *tempfile = folder->filelist;
	if (!tempfile)
	{
		cout<<"目录为空，不能进行查找更新操作"<<endl;
		cout<<"任意键返回菜单"<<endl;
		system("pause>>nul");
		return;
	}
	cout<<"输入需要修改文件名:"<<endl;
	cin>>filename;
	while (tempfile)
	{
		// 遍历链表查找文件
		if (strcmp(tempfile->filename, filename) == 0)
		{
			cout<<"已找到 "<<filename<<" 文件"<<endl;
			cout<<"输入修改后的文件名:";
			cin>>tempfile->filename;
			cout<<"输入修改后的文件大小:";
			cin>>tempfile->filesize;
			flag = true;

		} else {
			tempfile = tempfile->next;
		}
	}
	// 判断是否找到文件
	if (flag != true)
	{
		cout<<"未找到此文件，是否继续操作？"<<endl;
		cout<<"是否继续更新操作？y/n"<<endl;
		cin>>option;
		if(strcmp(option, "y") == 0 || strcmp(option, "Y") == 0)
		{
			UpdateFile(folder);
		} else {
			return;
		}
	}
}

// 删除文件
void DeleteFile(FolderLink &folder)
{
	int serial = 0; // 记录目标序号
	bool flag = false; // 访问标志
	char filename[20]; // 输入文件名
	char option[10]; // 输入确认信息
	cout<<"=========="<<endl;
	cout<<"删除文件"<<endl;
	FileNode *tempfile = folder->filelist; // 用于遍历链表信息
	FileNode *deletefile = new FileNode; // 临时保存删除节点信息
	// 判断目录是否为空
	if (!tempfile)
	{
		cout<<"目录为空，不能进行查找删除操作"<<endl;
		cout<<"任意键返回菜单"<<endl;
		system("pause>>nul");
		return;
	}
	cout<<"请输入要删除的文件名:";
	cin>>filename;
	// 遍历查找操作
	while (tempfile)
	{
		if (strcmp(tempfile->filename, filename) == 0)
		{
			serial++;
			tempfile = tempfile->next;
			flag = serial;
			break;
		} else {
			serial++;	
			tempfile = tempfile->next;
		}
	}

	cout<<"result "<<serial<<endl;
	if (flag == true)
	{
		cout<<"找到此文件"<<endl;
		cout<<"是否删除？y/n"<<endl;
		cin>>option;	
		if (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0)
		{
			FileNode *tempfile = folder->filelist; // 用于遍历链表信息
			serial = -1;
			// 有且只有一个文件的情况
			if (tempfile->next)
			{
				cout<<"只有一个节点"<<endl;
				deletefile = tempfile;
				folder->filelist = NULL;
			}
			while (tempfile->next)
			{
				cout<<tempfile->filename<<endl;
				cout<<flag<<endl;
				cout<<serial<<endl;
				serial++;
				if (serial == flag)
				{
					deletefile = tempfile->next;
					tempfile->next = deletefile->next;
					delete tempfile;
					cout<<"文件已删除"<<endl;
					cout<<"任意键返回主菜单"<<endl;
					system("pause>>nul");
					return;
				} else {
					cout<<"????"<<endl;
				}
				tempfile = tempfile->next;
			}
		} else {
			cout<<"文件已保留"<<endl;
			cout<<"任意键返回主菜单"<<endl;
			system("pause>>nul");
			return;
		}
	} else {
		cout<<"未找到此文件"<<endl;
	}
	cout<<"是否继续删除操作？y/n"<<endl;
	cin>>option;
	if (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0)
	{
		DeleteFile(folder);
	} else {
		return;
	}
}

// 显示菜单
void ShowMenu(FolderLink &folder)
{
	cout<<endl<<"\t\t=========================="<<endl;
	cout<<"\t\t\t文件管理助手"<<endl;
	cout<<endl<<"\t\t=========================="<<endl;
	cout<<"\t\t|    1.查看当前目录    \t|"<<endl<<endl;
	cout<<"\t\t|    2.显示下层目录    \t|"<<endl<<endl;
	cout<<"\t\t|    3.返回上层目录    \t|"<<endl<<endl;
	cout<<"\t\t|    4.返回根目录    \t|"<<endl<<endl;
	cout<<"\t\t|    5.新建文件    \t|"<<endl<<endl;
	cout<<"\t\t|    6.新增下层目录    \t|"<<endl<<endl;
	cout<<"\t\t|    7.更新文件信息    \t|"<<endl<<endl;
	cout<<"\t\t|    8.删除文件信息    \t|"<<endl<<endl;
	cout<<"\t\t|    9.保存目录信息   \t|"<<endl<<endl;
	cout<<"\t\t|    10.退出文件助手   \t|"<<endl<<endl;
	cout<<endl<<"\t\t=========================="<<endl;
}

// 保存数据
int Save(FolderLink &folder)
{
	ofstream outputfile1("folder.txt"); // 输出文件夹信息到folder.txt
	ofstream outputfile2("file.txt"); // 输出文件信息到file.txt
	// 判断是否打开输出文件夹流
	if(!outputfile1 &&!outputfile2)
		return -1;

	// 保存文件夹信息
	FolderNode *tempfolder = folder->folderlist;
	while(tempfolder)
	{
		outputfile1<<endl<<tempfolder->foldername;
		tempfolder = tempfolder->folderlist;
	}

	// 保存文件信息
	FileNode *tempfile = folder->filelist;
	while(tempfile)
	{
		outputfile2<<endl<<tempfile->filename<<endl<<tempfile->filesize;
		tempfile = tempfile->next;
	}
	return 0;
}

// 选择菜单
void ChoiceMenu(FolderLink &folder)
{
	char str[30];
	cout<<"\t\t请输入编号:";
	cin>>str;
	if (strcmp(str, "1") == 0)
		PrintCurrent(folder);
	else if (strcmp(str, "2") == 0)
		PrintLower(folder);
	else if (strcmp(str, "3") == 0)
		ReturnUper(folder);
	else if (strcmp(str, "4") == 0)
		ReturnRoot(folder);
	else if (strcmp(str, "5") == 0)
		NewFile(folder);
	else if (strcmp(str, "6") == 0)
		NewFolder(folder);
	else if (strcmp(str, "7") == 0)
		UpdateFile(folder);
	else if (strcmp(str, "8") == 0)
		DeleteFile(folder);
	else if (strcmp(str, "9") == 0)
		Save(folder);
	else if (strcmp(str, "10") == 0)
		exit(0);
	else
	{
		cout<<"输入有误请重新输入."<<endl;
	}
}

// 将内置数据输入到文件中
int Write()
{
	ofstream outputfile1("file.txt");
	ofstream outputfile2("folder.txt");
	if (!outputfile1 && !outputfile2)
	{
		cout<<"尝试打开输出文件流出错."<<endl;
		return -1;
	}
	// 写入内置数据到文件信息
	outputfile1<<
		"bootsqm.dat 34.2 "
		"world.docx 43.5 "
		"demo.cpp 34.5 "
		"visual.projc 6.56 "
		"msvcr.dll 2.3 "
		"atmlib.dll 4.3 "
		"wplog.txt 3.2 "
		"windows.ini 3.4 "
		"VBadin.ini 1.8 "
		"winhelp.exe 3.6 "
		"Main.java 45.3";
	// 写入内置数据文件夹信息
	outputfile2<<
		"java "
		"c# "
		"c++ "
		"c "
		"jsp "
		"SQL "
		"php "
		"ruby "
		"html "
		"xml "
		"css "
		"perl "
		"lau "
		"bash "
		".NET";
	outputfile1.close();
	outputfile2.close();
	return 0;
}

// 载入数据
void Load(FolderLink &folder)
{
	ifstream inputfile1("file.txt");
	ifstream inputfile2("folder.txt");
	// 写入文件信息
	while(!inputfile1.eof())
	{
		FileNode *insertNode = new FileNode;
		inputfile1>>insertNode->filename;
		inputfile1>>insertNode->filesize;
		insertNode->next = folder->filelist;
		folder->filelist = insertNode;
	}
	// 写入文件夹信息
	while(!inputfile2.eof())
	{
		FolderNode *tempNode = new FolderNode;
		FolderNode *insertNode = new FolderNode;
		tempNode = folder;
		inputfile2>>insertNode->foldername;
		insertNode->folderlist = tempNode->folderlist;
		tempNode->folderlist = insertNode;
	}
	inputfile1.close();
	inputfile2.close();
}

// 主程序入口
int main()
{
	char option[10];
	// 定义输入文件流
	ifstream inputfile1("file.txt");
	ifstream inputfile2("folder.txt");
	FolderLink folder = new FolderNode;
	// 初始化
	Init(folder);
	// 判断文件是否存在
	if (!inputfile1 && !inputfile2)
	{
		cout<<"==未找到数据文件"<<endl;	
		cout<<"是否载入内置数据? y/n"<<endl;
		cin>>option;
		if (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0)
		{
			Write();
			Load(folder);
		}
	} else {
		cout<<"==找到数据文件"<<endl;
		cout<<"是否载入数据? y/n"<<endl;
		cin>>option;
		if (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0)
			Load(folder);
	}
	while (true)
	{
		ShowMenu(folder);
		ChoiceMenu(folder);
	}
	return 0;
}

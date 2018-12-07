
// BinaryTree.cpp
// 数据结构 : 二叉树
// 二叉树的二叉链表存储表示
#include <iostream>
#include <fstream> // ifstream ofstream 所用头文件

using namespace std;

typedef char TElemType;

ifstream inputfile; // 定义输入文件
ifstream inputfile1;

// 二叉树的二叉链表存储表示
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *leftChild, *rightChild;
}BiTNode, *BiTree;

//  遍历二叉树(递归算法)
void PreOrderTraverse(BiTree T)
{
    // 先序遍历
    if(T)
    {
        cout<<T->data;
        PreOrderTraverse(T->leftChild);
        PreOrderTraverse(T->rightChild);
    }
    else
        cout<<"#";
}

void InOrderTraverse(BiTree T)
{
    // 中序遍历
    if(T)
    {
        InOrderTraverse(T->leftChild);
        cout<<T->data;
        InOrderTraverse(T->rightChild);
    }
    else
        cout<<"#";
}
// 后序遍历二叉树
void PostOrderTraverse(BiTree T)
{
    // 后序遍历
    if(T)
    {
        PostOrderTraverse(T->leftChild);
        PostOrderTraverse(T->rightChild);
        cout<<T->data;
    }
    else
        cout<<"#";
}

// 先序建立二叉树
void PreOrderCreateBiTree(BiTree &T)
{
    char ch;
//    cin>>ch;
    inputfile>>ch;
    if(ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        PreOrderCreateBiTree(T->leftChild);
        PreOrderCreateBiTree(T->rightChild);
    }
}

// 先序建立二叉树
void PreOrderCreateBiTree1(BiTree &T)
{
    char ch;
//    cin>>ch;
    inputfile1>>ch;
    if(ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        PreOrderCreateBiTree1(T->leftChild);
        PreOrderCreateBiTree1(T->rightChild);
    }
}

// 后序建立二叉树
void PostOrderCreateBiTree(BiTree &T)
{
    char ch;
    cin>>ch;
    if(ch =='#')
        T = NULL;
    else
    {
        T = new BiTNode;
        PostOrderCreateBiTree(T->leftChild);
        PostOrderCreateBiTree(T->rightChild);
        T->data = ch;
    }
}
	int state = 0;
int Judge(BiTree T, BiTree T1)
{
	if(T && T1)
	{
//		cout<<"T "<<T->data<<" ";
//		cout<<"T1 "<<T->data<<" ";
//		cout<<"state "<<state<<" ";
		if((T->data == T1->data) == 0)
			state = -1;
		Judge(T->leftChild, T1->leftChild);
		Judge(T->rightChild, T1->rightChild);
	}
	state = -1;
	return state;
}

int main()
{
    BiTree T, T1;
    ofstream outputfile, outputfile1; // 定义输出文件
    cout<<endl<<" 写入树结点数据到 BiTree.txt文件中 "<<endl;
    outputfile.open("./BiTree.txt");
    outputfile1.open("./BiTree1.txt");
    cout<<" 树结点数据为 ABC##DE#G##F### "<<endl;
    outputfile<<"ABC##DE#G##F###";
    outputfile1<<"AB###CDEFGH#";
    outputfile.close(); // 关闭输出文件
    outputfile1.close();
    cout<<" 从 BiTree.txt 文件载入树结点数据 "<<endl;
    inputfile.open("./BiTree.txt");
    inputfile1.open("./BiTree1.txt");

    cout<<" 使用树结点数据先序遍历建立二叉树"<<endl;
    PreOrderCreateBiTree(T);
    inputfile.close(); // 关闭输入文件
    cout<<endl<<"---"<<endl<<" 先序遍历二叉树"<<endl<<endl<<"    ";
    PreOrderTraverse(T);
    cout<<endl<<"---"<<endl<<" 中序遍历二叉树"<<endl<<endl<<"    ";
    InOrderTraverse(T);
    cout<<endl<<"---"<<endl<<" 后序遍历二叉树"<<endl<<endl<<"    ";
    PostOrderTraverse(T);

    cout<<endl<<" 使用树结点数据先序遍历建立二叉树"<<endl;
    PreOrderCreateBiTree1(T1);
    inputfile1.close();
    cout<<endl<<"---"<<endl<<" 先序遍历二叉树"<<endl<<endl<<"    ";
    PreOrderTraverse(T1);
    cout<<endl<<"---"<<endl<<" 中序遍历二叉树"<<endl<<endl<<"    ";
    InOrderTraverse(T1);
    cout<<endl<<"---"<<endl<<" 后序遍历二叉树"<<endl<<endl<<"    ";
    PostOrderTraverse(T1);

    cout<<endl<<"Judge"<<endl;
    if(Judge(T, T1) == 0)
    	cout<<"true"<<endl;
    else
    	cout<<"false"<<endl;


}

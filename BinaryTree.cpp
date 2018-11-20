// BinaryTree.cpp
// 数据结构 : 二叉树
// 二叉树的二叉链表存储表示
#include <iostream>
#include <fstream> // ifstream ofstream 所用头文件

using namespace std;

typedef char TElemType;

ifstream inputfile; // 定义输入文件

// 二叉树的二叉链表存储表示
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *leftChild, *rightChild;
}BiTNode, *BiTree;

//  遍历二叉树(递归算法)
void PreOrderTraverse(BiTree &T)
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

void InOrderTraverse(BiTree &T)
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

void PostOrderTraverse(BiTree &T)
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


// 中序遍历建立二叉树
void InOrderCreateBiTree(BiTree &T)
{
    char ch;
   // if(inputfile.peek() != EOF) // 读取文件指针下一位置的值6
    {
        inputfile>>ch;
        if(ch == '#')
            T = NULL;
        else
        {
            T = new BiTNode;
            InOrderCreateBiTree(T->leftChild);
            T->data = ch;
            InOrderCreateBiTree(T->rightChild);
        }
    }

}

void PreOrderCreateBiTree(BiTree &T)
{
    char ch;
    cin>>ch;
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

int main()
{
    BiTree T;
    ofstream outputfile; // 定义输出文件
    cout<<endl<<" 写入树结点数据到 BiTree.txt文件中 "<<endl;
    outputfile.open("./BiTree.txt");
    cout<<" 树结点数据为 ABC##DE#G##F### "<<endl;
    outputfile<<"ABC##DE#G##F###";
    outputfile.close(); // 关闭输出文件
    cout<<" 从 BiTree.txt 文件载入树结点数据 "<<endl;
    inputfile.open("./BiTree.txt");

    cout<<" 使用树结点数据中序遍历建立二叉树"<<endl;
    InOrderCreateBiTree(T);
    inputfile.close(); // 关闭输入文件
    cout<<endl<<"---"<<endl<<" 先序遍历二叉树"<<endl<<endl<<"    ";
    PreOrderTraverse(T);
    cout<<endl<<"---"<<endl<<" 中序遍历二叉树"<<endl<<endl<<"    ";
    InOrderTraverse(T);
    cout<<endl<<"---"<<endl<<" 后序遍历二叉树"<<endl<<endl<<"    ";
    PostOrderTraverse(T);

}

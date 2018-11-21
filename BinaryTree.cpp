// BinaryTree.cpp
// ���ݽṹ : ������
// �������Ķ�������洢��ʾ
#include <iostream>
#include <fstream> // ifstream ofstream ����ͷ�ļ�

using namespace std;

typedef char TElemType;

ifstream inputfile; // ���������ļ�

// �������Ķ�������洢��ʾ
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *leftChild, *rightChild;
}BiTNode, *BiTree;

//  ����������(�ݹ��㷨)
void PreOrderTraverse(BiTree &T)
{
    // �������
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
    // �������
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
    // �������
    if(T)
    {
        PostOrderTraverse(T->leftChild);
        PostOrderTraverse(T->rightChild);
        cout<<T->data;
    }
    else
        cout<<"#";
}


// �����������������
void InOrderCreateBiTree(BiTree &T)
{
    char ch;
   // if(inputfile.peek() != EOF) // ��ȡ�ļ�ָ����һλ�õ�ֵ6
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
    ofstream outputfile; // ��������ļ�
    cout<<endl<<" д����������ݵ� BiTree.txt�ļ��� "<<endl;
    outputfile.open("./BiTree.txt");
    cout<<" ���������Ϊ ABC##DE#G##F### "<<endl;
    outputfile<<"ABC##DE#G##F###";
    outputfile.close(); // �ر�����ļ�
    cout<<" �� BiTree.txt �ļ�������������� "<<endl;
    inputfile.open("./BiTree.txt");

    cout<<" ʹ����������������������������"<<endl;
    InOrderCreateBiTree(T);
    inputfile.close(); // �ر������ļ�
    cout<<endl<<"---"<<endl<<" �������������"<<endl<<endl<<"    ";
    PreOrderTraverse(T);
    cout<<endl<<"---"<<endl<<" �������������"<<endl<<endl<<"    ";
    InOrderTraverse(T);
    cout<<endl<<"---"<<endl<<" �������������"<<endl<<endl<<"    ";
    PostOrderTraverse(T);

}

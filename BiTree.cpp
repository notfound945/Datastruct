#include <iostream>

#define TElementType char

using namespace std;

typedef struct BiTNode {
    TElementType data;
    struct BiTNode *leftchid, *rightchid;
}*BiTree, BiTNode;

// �������
void InOrderTraverse(BiTree T) {
    if(T) {
        InOrderTraverse(T->leftchid);
        cout<<T->data;
        InOrderTraverse(T->rightchid);
    }
}

// �������
void BeOrderTraverse(BiTree T) {
    if(T) {
        cout<<T->data;
        BeOrderTraverse(T->leftchid);
        BeOrderTraverse(T->rightchid);
    }
}

//�������
void LaOrderTraverse(BiTree T) {
    if(T) {
        LaOrderTraverse(T->leftchid);
        LaOrderTraverse(T->rightchid);
        cout<<T->data;
    }
}


// �������
void CreateBiTree(BiTree &T) {
    char ch;
    cin>>ch;
    if(ch == '#')
        T = NULL;
    else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->leftchid);
        CreateBiTree(T->rightchid);
    }
}
int main()
{
    BiTree T;
    while(true) {
        CreateBiTree(T);
    }


}

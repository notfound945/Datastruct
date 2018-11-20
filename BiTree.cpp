#include <iostream>

#define TElementType char

using namespace std;

typedef struct BiTNode {
    TElementType data;
    struct BiTNode *leftchid, *rightchid;
}*BiTree, BiTNode;

// 中序遍历
void InOrderTraverse(BiTree T) {
    if(T) {
        InOrderTraverse(T->leftchid);
        cout<<T->data;
        InOrderTraverse(T->rightchid);
    }
}

// 先序遍历
void BeOrderTraverse(BiTree T) {
    if(T) {
        cout<<T->data;
        BeOrderTraverse(T->leftchid);
        BeOrderTraverse(T->rightchid);
    }
}

//后序遍历
void LaOrderTraverse(BiTree T) {
    if(T) {
        LaOrderTraverse(T->leftchid);
        LaOrderTraverse(T->rightchid);
        cout<<T->data;
    }
}


// 先序插入
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

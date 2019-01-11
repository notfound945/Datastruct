/**
 * @brief 散列表的开放地址法和链地址法的插入与查找
 * @name HashTable.cpp
 * @author notfound945
 * @date 2019/01/11
 */

#include <iostream>

using namespace std;

#define MAXSIZE 10
// 开放地址法
typedef struct {
    int data;
} HashTable[MAXSIZE];
// 链地址法
typedef struct {
    int data;
    struct HashLinkNode *next;
} Table[MAXSIZE];

typedef struct HashLinkNode {
    int data;
    struct HashLinkNode *next;
} HashLinkNode;

int Hash(int data) {
    return data % MAXSIZE;
}

// 插入元素 （开放地址法）
int Insert_OpenAddress(HashTable *table, int data) {
    int location = Hash(data);
    if (table[location]->data == -1) {
        table[location]->data = data;
        return 0;
    } else {
        for (int i = 0; i < MAXSIZE; i++) {
            location = Hash(data + i);
            if (table[location]->data == -1) {
                table[location]->data = data;
                return 0;
            }
        }
        return -1;
    }
}

// 插入元素（链地址法）
void Insert_LinkAddress(Table *tablehand, int data) {
    HashLinkNode *p = new HashLinkNode;
    p->data = data;
    p->next = tablehand[Hash(data)]->next;
    tablehand[Hash(data)]->next = p;

}

// 搜索元素（开放地址法）
int Search_OpenAddress(HashTable *table, int data) {
    int location = Hash(data);
    if (table[location]->data == data) {
        return location;
    } else if (table[location]->data == -1) {
        return -1;
    } else {
        for (int i = 0; i < MAXSIZE; i++) {
            location = Hash(data + i);
            if (table[location]->data == data) {
                return location;
            }
        }
        return -1;
    }
}

// 搜索元素（链地址法）
int Search_LinkAddress(Table *tablehand, int data) {
    int location = Hash(data);
    HashLinkNode *temp = new HashLinkNode;
    temp = tablehand[location]->next;
    while (temp) {
        if (temp->data == data)
            return location;
        temp = temp->next;
    }
    return -1;
}

// 开放地址法
void OpenAddress() {
    HashTable *table = new HashTable[MAXSIZE];
    // 初始化为空表
    for (int i = 0; i < MAXSIZE; i++)
        table[i]->data = -1;
    int arrays[]{29, 23, 42, 42, 2, 34, 54, 21, 23, 54, 19, 29};
    cout << "1.插入元素" << endl;
    for (int data:arrays) {
        if (!Insert_OpenAddress(table, data)) {
            cout << data << " 插入成功" << endl;
        } else {
            cout << data << " 插入失败" << endl;
        }
    }
    cout << "2.打印数据" << endl;
    for (int i = 0; i < MAXSIZE; i++) {
        cout << "table[" << i << "] " << table[i]->data << endl;
    }
    cout << endl << "3.搜索元素 " << endl;
    cout << " 搜索元素:";
    int a;
    cin >> a;
    int location = Search_OpenAddress(table, a);
    if (location != -1) {
        cout << " 元素 " << a << " 位于table[" << location << "] 上" << endl;
    } else {
        cout << " 没有搜索到元素 " << a << endl;
    }
}

// 链地址法
void LinkAddress() {
    Table *tablehand = new Table[MAXSIZE];
    // 初始化链表头
    for (int i = 0; i < MAXSIZE; i++) {
        tablehand[i]->data = i;
        tablehand[i]->next = nullptr;
    }
    int arrays[] = {2, 21, 312, 42, 32, 23, 23, 45, 324, 34, 23, 32, 10, 31, 98, 23, 66, 99, 77, 97};
    cout << "1.插入数据" << endl;
    for (int data:arrays) {
        Insert_LinkAddress(tablehand, data);
    }
    cout << "2.打印数据" << endl;
    for (int i = 0; i < MAXSIZE; i++) {
        HashLinkNode *temp = tablehand[i]->next;
        cout << "tablehand[" << i << "] ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << "3.搜索数据" << endl;
    cout << " 输入搜索元素: ";
    int a;
    cin >> a;
    int location = Search_LinkAddress(tablehand, a);
    if (location != -1) {
        cout << " 元素 " << a << " 位于tablehand[" << location << "] 上" << endl;
    } else {
        cout << " 没有找到元素 " << a << endl;
    };
}


int main() {
    cout << "Hello 中文" << endl;
    cout << "---- 散列表操作 ----" << endl;
    cout << " 一、开放地址法" << endl;
    OpenAddress();
    cout << " 二、链地址法" << endl;
    LinkAddress();
    return 0;
}

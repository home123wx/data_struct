#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>

namespace wb {

#define T int

typedef void (*OP)(const T& data);

typedef struct Node {
    Node():data(T()),next(NULL){}
    Node(T d):data(d), next(NULL){}

    T data;
    Node* next;
} Node;

class List
{
public:
    List();
    ~List();

public:
    /**
     * 在指定Index位置插入数据,大于节点数在尾插入，小于0在头插入
     */
    int  Insert(int nIndex, const T& data);

    /**
     * 在列表尾插入
     */
    void PushBack(const T& data);

    /**
     * 在列表头插入
     */
    void PushFront(const T& data);

    /**
     * 删除列表中对应数据
     */
    void Delete(const T& data);

    /**
     * 查找对应数据并返回节点指针
     */
    Node* Find(const T& data);

    /**
     * 遍历列表，执行OP操作
     */
    void Travel(OP op);

    /**
     * 获取列表的节点数
     */
    int GetNodeCount();

private:
    int m_nodeCount;
    Node* m_headNode;
    Node* m_tailNode;
};

} // end namespace

#endif //_LIST_H_

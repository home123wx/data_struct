#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>

namespace wb {

#define T int

typedef enum Direction {
    LEFT = 1,
    RIGHT
} Direction;

typedef void (*OP)(const T& data);

typedef struct Node {
    Node():data(T()), prev(NULL), next(NULL){}
    Node(T d):data(d), prev(NULL), next(NULL){}

    T data;
    Node* next;
    Node* prev;
} Node;

class List
{
public:
    List();
    ~List();

public:
    /**
     * List为空判断
     */
    bool Empty();

    /**
     * 取第一个元素
     */
    T First();

    /**
     * 取最后一个元素
     */
    T Last();

    /**
     * 弹出第一个node, 并返回该节点值
     */
    T PopFirst();

    /**
     * 弹出最后一个node, 并返回该节点值
     */
    T PopLast();

    /**
     * 在指定Index位置插入数据,大于节点数在尾插入，小于0在头插入
     */
    int  Insert(int index, const T& data);

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
     * 清空List中Node, 除了头节点
     */
    void Clear();

    /**
     * 按照data排序
     */
    void Sort();

    /**
     * 查找对应数据并返回节点指针
     */
    Node* Find(const T& data);

    /**
     * 遍历列表，执行OP操作
     */
    void Travel(Direction dir, OP op);

    /**
     * 获取列表的节点数
     */
    int GetNodeCount();

private:
    /**
     * 插入data到node节点后面
     */
    void PushBackPri(Node* & node, const T& data);

    /**
     * 插入data到node节点前面
     */
    void PushFrontPri(Node* & node, const T& data);

    /**
      * 在index节点后插入data
      */
    void InsertNodePri(int index, const T& data);

    /**
     * 删除节点
     */
    void DeleteNode(Node* & node);

    /**
     *
     */
    void SortPri(Node* first, Node* last);

    /**
      * 从左到右遍历List，并执行op操作
      */
    void TravelLeft(OP op);

    /**
      * 从右到左遍历List，并执行op操作
      */
    void TravelRight(OP op);

    void Release();

private:
    int m_nodeCount;
    Node* m_headNode;
    Node* m_tailNode;
};

} // end namespace

#endif //_LIST_H_

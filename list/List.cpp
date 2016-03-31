#include "List.h"

namespace wb {

List::List()
{
    m_nodeCount = 0;
    m_headNode = new Node;
    m_tailNode = m_headNode;
}

List::~List()
{
    Release();
}

bool List::Empty()
{
    return (m_nodeCount == 0);
}

T List::First()
{
    T ret = T();
    if (Empty()) {
        return ret;
    }
    return m_headNode->next->data;
}

T List::Last()
{
    T ret = T();

    if (Empty()) {
        return ret;
    }
    return m_tailNode->data;
}

T List::PopFirst()
{
    T ret = First();
    if (!Empty()) {
        Node* p = m_headNode->next;
        DeleteNode(p);
    }
    return ret;
}

T List::PopLast()
{
    T ret = Last();
    if (!Empty()) {
        Node* p = m_tailNode->prev;
        DeleteNode(m_tailNode);
        m_tailNode = p;
    }
    return ret;
}

int List::Insert(int index, const T& data)
{
    if (index <= 0) {
        PushFront(data);
    } else if (index >= m_nodeCount) {
        PushBack(data);
    } else {
        //printf("在下标[%d]后插入: %d\n", index, data);
        InsertNodePri(index, data);
    }
}

void List::PushBack(const T& data)
{
    //printf("向尾插入: %d\n", data);

    PushBackPri(m_tailNode, data);
}

void List::PushFront(const T& data)
{
    //printf("向头插入: %d\n", data);

    PushFrontPri(m_headNode, data);
}

void List::Delete(const T& data)
{
    if (Empty()) {
        return;
    }

    //printf("删除数据为: %d 的节点\n", data);

    Node* p = Find(data);

    DeleteNode(p);
}

void List::Sort()
{
    SortPri(m_headNode->next, m_tailNode);
}

Node* List::Find(const T& data)
{
    Node* retNode = NULL;
    if (Empty()) {
        return retNode;
    }

    Node* p = m_headNode->next;
    while (p != NULL) {
        if (p->data == data) {
            retNode = p;
            break;
        }
        p = p->next;
    }
    return retNode;
}

void List::Travel(Direction dir, OP op)
{
    if (dir == LEFT) {
        TravelLeft(op);
    } else if (dir == RIGHT) {
        TravelRight(op);
    }
}

int List::GetNodeCount()
{
    return m_nodeCount;
}

void List::PushBackPri(Node* & node, const T& data)
{
    Node* newNode = new Node(data);

    if (node == m_tailNode) {
        node->next = newNode;
        newNode->prev = node;
        node = newNode;
    } else {
        newNode->prev = node;
        Node* p = node->next;
        p->prev = newNode;

        node->next = newNode;
        newNode->next = p;
    }

    //节点数增加
    ++m_nodeCount;
}

void List::PushFrontPri(Node* & node, const T& data)
{
    Node* newNode = new Node(data);

    if (node == m_headNode) {
        Node* p = node->next;
        newNode->prev = node;
        newNode->next = p;
        node->next = newNode;
        if (p != NULL) {
            p->prev = newNode;
        } else {
            m_tailNode = newNode;
        }
    } else {
        Node* p = node->prev;
        p->next = newNode;
        newNode->prev = p;
        newNode->next = node;
        node->prev = newNode;
    }

    //节点数增加
    ++m_nodeCount;
}

void List::InsertNodePri(int index, const T& data)
{
    int cnt = 1;
    Node* p = m_headNode->next;
    while (p != NULL) {
        if (cnt == index) {
            PushBackPri(p, data);
            break;
        }
        ++cnt;
        p = p->next;
    }
}

void List::SortPri(Node* first, Node* last)
{
    Node* left = first;
    Node* right = last;

    if (left == NULL || right == NULL) {
        return;
    }

    if (left == right) {
        return;
    }

    T d = left->data;

    while (left != right) {
        while (right != left && right != NULL && right->data >= d) {
            right = right->prev;
        }

        if (left != right && left != NULL && right != NULL) {
            left->data = right->data;
        }

        while (left != right && left != NULL && left->data <= d) {
            left = left->next;
        }

        if (left != right && left != NULL && right != NULL) {
            right->data = left->data;
        }
    }
    left->data = d;

    if (first != left) {
        SortPri(first, left->prev);
    }

    if (last != right) {
        SortPri(right->next, last);
    }
}

void List::TravelLeft(OP op)
{
    Node* p = m_tailNode;
    while (p != NULL && p != m_headNode) {
        op(p->data);
        p = p->prev;
    }
}

void List::TravelRight(OP op)
{
    Node* p = m_headNode->next;
    while (p != NULL) {
        op(p->data);
        p = p->next;
    }
}

void List::DeleteNode(Node* & node)
{
    if (node == NULL) {
        return;
    }

    Node* prev = node->prev;
    Node* next = node->next;

    if (prev != NULL) {
        node->prev->next = next;
    }

    if (next != NULL) {
        node->next->prev = prev;
    }

    delete node;
    node = NULL;

    --m_nodeCount;
}

void List::Clear()
{
    if (Empty()) {
        return;
    }
    
    Node* next = NULL;
    Node* p = m_headNode->next;
    if (p != NULL) {
        next = p->next;
    }

    while (p != NULL) {
        delete p;
        p = next;
        if (p != NULL) {
            next = p->next;
        }
    }
    m_headNode->next = NULL;
    m_tailNode = m_headNode;

    m_nodeCount = 0;
}

void List::Release()
{
    Clear();

    if (m_headNode != NULL) {
        delete m_headNode;
    }
}

} //end namespace

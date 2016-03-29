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

int List::Insert(int index, const T& data)
{
    if (index <= 0) {
        PushFront(data);
    } else if (index >= m_nodeCount) {
        PushBack(data);
    } else {
        printf("在下标[%d]后插入: %d\n", index, data);
        InsertNodePri(index, data);
    }
}

void List::PushBack(const T& data)
{
    printf("向尾插入: %d\n", data);

    PushBackPri(m_tailNode, data);
}

void List::PushFront(const T& data)
{
    printf("向头插入: %d\n", data);

    PushFrontPri(m_headNode, data);
}

void List::Delete(const T& data)
{
    Node* p = Find(data);

    Node* prev = p->prev;
    Node* next = p->next;

    prev->next = next;
    next->prev = prev;

    if (p != NULL) {
        delete p;
    }
}

Node* List::Find(const T& data)
{
    Node* retNode = NULL;
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

void List::Release()
{
    Node* next = m_headNode->next;
    Node* p = m_headNode;
    while (p != NULL) {
        delete p;
        p = next;
        if (p != NULL) {
            next = p->next;
        }
    }
}

} //end namespace

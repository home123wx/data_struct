#include "List.h"

namespace wb {

List::List()
{
    m_nodeCount = 0;
    m_headNode = new Node;
}

List::~List()
{
}

int  List::Insert(int nIndex, const T& data)
{
}

void List::PushBack(const T& data)
{
}

void List::PushFront(const T& data)
{
    //节点数增加
    ++m_nodeCount;

    if (m_headNode->next == NULL) {
        Node* newNode = new Node(data);
        m_headNode->next = newNode;
        m_tailNode = newNode;
        return;
    }

    Node* p = m_headNode->next;
    Node* newNode = new Node(data);
    m_headNode->next = newNode;
    m_headNode->next->next = p;

    //尾节点没有改变
}

void List::Delete(const T& data)
{
}

Node* List::Find(const T& data)
{
}

void List::Travel(OP op)
{
    Node* p = m_headNode->next;
    while (p != NULL) {
        op(p->data);
        p = p->next;
    }
}

int List::GetNodeCount()
{
    return m_nodeCount;
}

} //end namespace

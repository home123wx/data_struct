#include "List.h"

void display(const int& d)
{
    printf("%d\n", d);
}

int main(int argc, char* argv[])
{
    wb::List l;

    l.PushFront(10);
    l.PushFront(20);

    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);

    l.Insert(4, 50);
    l.Insert(-1, 40);
    l.Insert(100, 100);

    printf("正向遍历：\n");
    l.Travel(wb::RIGHT, display);

    printf("反向遍历：\n");
    l.Travel(wb::LEFT, display);

    l.Delete(40);

    wb::Node* p = l.Find(40);
    if (p != NULL) {
        printf("data: %d\n", p->data);
    }

    int count = l.GetNodeCount();
    printf("列表中有 %d 个元素\n", count);
}

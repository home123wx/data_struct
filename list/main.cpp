#include "List.h"

void display(const int& d)
{
    printf("%d ", d);
}

void show(wb::Direction dir, const char* s, wb::List* l)
{
    printf("%s\n", s);
    l->Travel(dir, display);
    printf("\n");
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

    show(wb::RIGHT, "正向遍历", &l);
    show(wb::LEFT,  "反向遍历", &l);

    l.Delete(40);
    l.Delete(100);

    show(wb::RIGHT, "正向遍历", &l);

    int count = l.GetNodeCount();
    printf("列表中有 %d 个元素\n", count);

    l.Clear();

    for (int i = 1; i < 8; ++i) {
        l.PushBack(i);
    }

    show(wb::RIGHT, "正向遍历", &l);
    show(wb::LEFT,  "反向遍历", &l);

    printf("第一个元素 : %d\n", l.PopFirst());
    printf("最后一个元素 : %d\n", l.PopLast());

    show(wb::RIGHT, "正向遍历", &l);
    show(wb::LEFT,  "反向遍历", &l);
}

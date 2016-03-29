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

    l.Travel(display);
}

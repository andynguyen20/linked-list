#include "linked_list.h"

int main()
{
    LinkedList list; 

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    list.print();

    return 0;
}
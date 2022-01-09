#include <iostream>

class DoublyLinkedListNode
{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

DoublyLinkedListNode *reverse(DoublyLinkedListNode *llist)
{
    if (llist == nullptr || llist->next == nullptr)
    {
        return llist;
    }
    DoublyLinkedListNode *current = llist;
    DoublyLinkedListNode *after = nullptr;
    DoublyLinkedListNode *before = nullptr;
    while (current != nullptr)
    {
        after = current->next;
        current->next = before;
        current->prev = after;

        before = current;
        current = after;
    }
    return before;
}
void addEnd(DoublyLinkedListNode *&llist, int data)
{
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    if (llist == nullptr)
    {
        llist = newNode;
        return;
    }
    DoublyLinkedListNode *endNode = llist;
    while (endNode->next != nullptr)
    {
        endNode = endNode->next;
    }
    endNode->next = newNode;
    newNode->prev = endNode;
}
void print(DoublyLinkedListNode *llist)
{
    while (llist != nullptr)
    {
        std::cout << llist->data << " ";
        llist = llist->next;
    }
    std::cout << std::endl;
}

int main()
{
    DoublyLinkedListNode *llist = new DoublyLinkedListNode(1);
    addEnd(llist, 3);
    addEnd(llist, 3);
    addEnd(llist, 3);
    addEnd(llist, 4);
    addEnd(llist, 4);
    addEnd(llist, 4);
    addEnd(llist, 5);
    addEnd(llist, 10);
    print(llist);
    addEnd(llist, 15);
    print(llist);

    llist = reverse(llist);
    print(llist);

    return 0;
}
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

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    if (llist == NULL)
    {
        return newNode;
    }
    if (llist->data >= data)
    {
        newNode->next = llist;
        newNode->prev = NULL;
        return newNode;
    }
    DoublyLinkedListNode *outputList = llist;
    DoublyLinkedListNode *previous = llist;
    while (llist != NULL && llist->data < data)
    {
        previous = llist;
        llist = llist->next;
    }
    if (llist == NULL) // add to the end
    {
        newNode->next = NULL;
        previous->next = newNode;
        newNode->prev = previous;
    }
    else
    {
        previous->next = newNode;
        llist->prev = newNode;
        newNode->prev = previous;
        newNode->next = llist;
    }
    return outputList;
}

void print(DoublyLinkedListNode *list)
{
    while (list != NULL)
    {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << std::endl;
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
    DoublyLinkedListNode *ouput = sortedInsert(llist, 2);
    print(ouput);
    return 0;
}
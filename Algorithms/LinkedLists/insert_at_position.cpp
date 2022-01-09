#include <iostream>
struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode() : data(0), next(NULL) {}
    SinglyLinkedListNode(int f_data) : data(f_data), next(NULL) {}
};

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist, int data, int position)
{
    SinglyLinkedListNode *ouputList = llist;
    int currentPosition{1};
    while (llist != NULL)
    {
        if (currentPosition == position)
        {
            SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
            temp->next = llist->next;
            llist->next = temp;
            break;
        }
        llist = llist->next;
        currentPosition++;
    }
    return ouputList;
}

void print(SinglyLinkedListNode *list)
{
    while (list != NULL)
    {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

int main()
{
    SinglyLinkedListNode *llist = new SinglyLinkedListNode(16);
    llist->next = new SinglyLinkedListNode(13);
    llist->next->next = new SinglyLinkedListNode(7);
    print(llist);

    SinglyLinkedListNode *output = insertNodeAtPosition(llist, 1, 2);
    print(output);
    // print(output);
    return 0;
}
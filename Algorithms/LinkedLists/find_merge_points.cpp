#include <iostream>

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    SinglyLinkedListNode *head1Temp = head1;
    SinglyLinkedListNode *head2Temp = head2;
    while (head1Temp != head2Temp)
    {
        head1Temp = head1Temp == NULL ? head1 : head1Temp->next;
        head2Temp = head2Temp == NULL ? head2 : head2Temp->next;
    }
    return head1Temp->data;
}

void print(SinglyLinkedListNode *node)
{
    while (node != nullptr)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    SinglyLinkedListNode *head1 = new SinglyLinkedListNode(1);
    head1->next = new SinglyLinkedListNode(2);

    SinglyLinkedListNode *head2 = new SinglyLinkedListNode(10);
    head2->next = new SinglyLinkedListNode(20);
    head2->next->next = new SinglyLinkedListNode(30);

    SinglyLinkedListNode *combined = new SinglyLinkedListNode(5);
    combined->next = new SinglyLinkedListNode(6);

    head1->next->next = combined;
    head2->next->next->next = combined;

    print(head1);
    print(head2);

    std::cout << findMergeNode(head1, head2) << std::endl;

    return 0;
}
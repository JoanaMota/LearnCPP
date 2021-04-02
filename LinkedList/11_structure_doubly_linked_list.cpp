#include <iostream>

struct Node
{
    Node *previous;
    int data;
    Node *next;
};

int main()
{
    Node *p1 = new Node;
    p1->data = 10;
    p1->previous = NULL;
    p1->next = NULL;

    Node *p2 = new Node;
    p2->data = 20;
    p2->previous = p1;
    p2->next = NULL;
    p1->next = p2;

    Node *p3 = new Node;
    p3->data = 30;
    p3->previous = p2;
    p3->next = NULL;
    p2->next = p3;

    std::cout << p1->data << std::endl;             // 10
    std::cout << p1->next->data << std::endl;       // 20
    std::cout << p1->next->next->data << std::endl; // 30

    std::cout << p3->data << std::endl;                     // 30
    std::cout << p3->previous->data << std::endl;           // 20
    std::cout << p3->previous->previous->data << std::endl; // 10
    return 0;
}
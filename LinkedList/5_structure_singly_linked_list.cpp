#include <iostream>

struct Node
{
    int data;
    Node * next;
};


int main()
{
    Node * node1;
    node1 = new Node;
    Node * node2;
    node2 = new Node;
    node1->data = 10;
    node1->next = node2;

    std::cout << "Node1 data: " << node1->data << std::endl;
    std::cout << "Node1 next pointer: " << node1->next << std::endl;
    
    node2->data = 20;
    node2->next = NULL;
    std::cout << "Node2 data: " << node2->data << std::endl; // 20
    std::cout << "Node2 data from node 1: " << node1->next->data << std::endl; //20
    std::cout << "Node2 next pointer: " << node2->next << std::endl;
    
    return 0;
}
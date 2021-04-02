#include <iostream>

struct Node
{
    Node *previous;
    int data;
    Node *next;
};

class Doubly
{
public:
    Node *m_tail, *m_head;
    Doubly()
    {
        m_head = NULL;
        m_tail = NULL;
    };

    void create(int f_data)
    {
        Node *temp1 = new Node;
        Node *temp2;
        temp1->data = f_data;

        // For the first node
        if (m_head == NULL)
        {
            temp1->previous = NULL;
            temp1->next = NULL;
            m_head = temp1;
            temp2 = temp1;
        }
        else
        {
            temp1->next = NULL;
            temp1->previous = temp2;
            temp2->next = temp1;
            temp2 = temp1;
        }
    }
    void display()
    {
        Node *temp = new Node;
        temp = m_head;
        while (temp != NULL)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
    void deleteNode(Node* delNode)
    {
        if (m_head == NULL || delNode == NULL)
            return;
        // If we want to delete the head node
        if (m_head == delNode)
            m_head = delNode->next;
        if (delNode->next != NULL)
            delNode->next->previous = delNode->previous;
        if (delNode->previous !=NULL)
            delNode->previous->next = delNode->next;
        free(delNode);
    }
};

int main()
{
    Doubly d1 = Doubly();
    d1.create(1);
    d1.create(2);
    d1.create(4);
    d1.create(8);
    std::cout << "After Creation" << std::endl;
    d1.display();
    d1.deleteNode(d1.m_head);
    d1.deleteNode(d1.m_head->next->next);
    std::cout << "After Deletion" << std::endl;
    d1.display();
    return 0;
}
#include <iostream>

struct Node
{
    Node *previous;
    int data;
    Node *next;
};

class Doubly
{
private:
    Node *m_tail, *m_head;

public:
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

    int getLength()
    {
        int counter{0};
        Node* temp = m_head;
        while (temp !=  NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void reverse()
    {
        Node* temp = NULL;
        Node* current = m_head;
        while (current != NULL)
        {
            temp = current->previous;
            current->previous = current->next;
            current->next = temp;
            current = current->previous;
        }
        if (temp != NULL)
        {
            m_head = temp->previous;
        }
    }
};

int main()
{
    Doubly d1 = Doubly();
    d1.create(1);
    d1.create(2);
    d1.create(4);
    d1.create(8);
    d1.display();
    std::cout << "DLL Legnth: " << d1.getLength() << std::endl;
    d1.reverse();
    std::cout << "After Reverse" << std::endl;
    d1.display();
    return 0;
}
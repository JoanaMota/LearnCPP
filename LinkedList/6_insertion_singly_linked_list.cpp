#include <iostream>

struct Node
{
    int data;
    Node * next;
};

class Singly
{
private:
    Node *tail, *head;
public:
    Singly()
    {
        head = NULL;
        tail = NULL;
    }
    void create(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL) // for the first node
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void display()
    {
        Node * temp = new Node;
        temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
    void insert_start(int value)
    {
        Node * temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insert_position(int position, int value)
    {
        Node * previous = new Node;
        Node * current = new Node;
        Node * temp = new Node;

        current = head; // Start from the head and iterate until the requested position
        for (int i = 0; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        temp->data = value;
        previous->next = temp;
        temp->next = current;
        
    }
};


int main()
{ 
    Singly s1 = Singly();
    s1.create(2);
    s1.create(3);
    s1.create(4);
    s1.insert_start(1);
    s1.insert_start(7);
    s1.insert_position(3,8);
    s1.display();
    
    return 0;
}
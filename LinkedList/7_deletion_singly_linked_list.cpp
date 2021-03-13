#include <iostream>

struct Node
{
    int data;
    Node * next;
};

class Singly
{
public:
    Node *m_tail, *m_head;
    Singly()
    {
        m_head = NULL;
        m_tail = NULL;
    }
    void create(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (m_head == NULL) // for the first node
        {
            m_head = temp;
            m_tail = temp;
            temp = NULL;
        }
        else
        {
            m_tail->next = temp;
            m_tail = temp;
        }
    }
    void display()
    {
        Node * temp = new Node;
        temp = m_head;
        while (temp != NULL)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
    void deleteNode(int key)
    {
        // Store head node
        Node *temp = m_head;
        Node *prev = NULL;

        // In case it is the head that we want to delete
        if (temp != NULL && temp->data == key) 
        {
            m_head = temp->next; // change head
            delete temp;         // free the memory
            return;
        }

        // Iterate through the list to find the key
        // Save prev since next we will have to change
        // prev->next
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        // If key was not present in linked list
        if (temp == NULL) return;

        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp;
    }

};
void deleteComplete(Node **head_ref)
{
    // dereference of head_ref to get the real head
    Node *current = *head_ref;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}


int main()
{ 
    Singly s1 = Singly();
    s1.create(2);
    s1.create(3);
    s1.create(4);
    std::cout << "After Create:" << std::endl;
    s1.display();

    s1.deleteNode(4);
    std::cout << "After Delete by key 4:" << std::endl;
    s1.display();

    deleteComplete(&s1.m_head);
    std::cout << "After Delete Entire List:" << std::endl;
    s1.display();
    
    return 0;
}
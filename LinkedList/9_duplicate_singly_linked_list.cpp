#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class Singly
{
private:

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
        Node *temp = new Node;
        temp = m_head;
        while (temp != NULL)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
    void removeDuplicatesSorted()
    {
        Node *current = m_head;
        Node *nextOfNext = NULL;
        if (current == NULL)
            return;
        while (current->next != NULL)
        {
            if (current->data == current->next->data)
            {
                nextOfNext = current->next->next;
                free(current->next);
                current->next = nextOfNext;
            }
            else
            {
                current = current->next; // Iterate normally
            }
        }
    }
    void removeDuplicatesUnsorted()
    {
        Node *ptr1, *ptr2, *duplicate;
        ptr1 = m_head;
        // Iterate through elements
        while (ptr1 != NULL && ptr1->next != NULL)
        {
            ptr2 = ptr1;
            // Iterate through elements for comparing
            while (ptr2->next != NULL)
            {
                if (ptr1->data == ptr2->next->data)
                {
                    duplicate = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete duplicate;
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }
    void insert_start(int value)
    {
        Node * temp = new Node;
        temp->data = value;
        temp->next = m_head;
        m_head = temp;
    }
};

int main()
{
    Singly s1 = Singly();
    s1.insert_start(2);
    s1.insert_start(3);
    s1.insert_start(3);
    s1.insert_start(4);
    s1.insert_start(4);
    s1.insert_start(4);
    std::cout << "After Create:" << std::endl;
    s1.display();

    s1.removeDuplicatesSorted();
    std::cout << "After Remove Duplicates on Sorted List:" << std::endl;
    s1.display();

    std::cout << "After Adding more elements:" << std::endl;
    s1.insert_start(5);
    s1.insert_start(5);
    s1.insert_start(5);
    s1.insert_start(4);
    s1.insert_start(2);
    s1.display();

    s1.removeDuplicatesUnsorted();
    std::cout << "After Remove Duplicates on Unsorted List:" << std::endl;
    s1.display();
    return 0;
}
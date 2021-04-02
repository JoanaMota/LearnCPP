#include <iostream>

struct Node
{
    int data;
    Node *next;
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
        Node *temp = new Node;
        temp = m_head;
        while (temp != NULL)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
    void reverse()
    {
        Node *current = m_head;
        Node *before = NULL;
        Node *after = NULL;

        while (current != NULL)
        {
            after = current->next;
            current->next = before;

            before = current;
            current = after;
        }
        m_head = before;
    }

    void segregate_even_odd()
    {
        Node *end = m_head;
        Node *previous = NULL;
        Node *current = m_head;

        // Move end node until end of liked list
        while (end->next != NULL)
        {
            end = end->next;
        }
        Node *new_end = end;

        // Consider all odd nodes before the first  
        // even node and move then after end
        while (current->data % 2 != 0 && current != NULL)
        {
            new_end->next = current;
            current = current->next;
            new_end->next->next = NULL;
            new_end = new_end->next;
        }

        // Do following steps only if there is any even node 
        if (current->data % 2 == 0)
        {
            // Change the head pointer to point to first even node 
            m_head = current;

            // now current points to the first even node 
            while (current != end)
            {
                if ((current->data) % 2 == 0)
                {
                    previous = current;
                    current = current->next;
                }
                else
                {
                    // break the link between previous and current 
                    previous->next = current->next;

                    // Make next of curr as NULL 
                    current->next = NULL;

                    // Move current to end 
                    new_end->next = current;

                    // make current as new end of list 
                    new_end = current;

                    // Update current pointer to next of the moved node 
                    current = previous->next;
                }
            }
        }

        // We must have previous set before executing lines following this statement 
        else
            previous = current;

        // If there are more than 1 odd nodes  
        // and end of original list is odd then  
        // move this node to end to maintain  
        // same order of odd numbers in modified list 
        if (new_end != end && (end->data) % 2 != 0)
        {
            previous->next = end->next;
            end->next = NULL;
            new_end->next = end;
        }
    }
};

int main()
{
    Singly s1 = Singly();
    s1.create(2);
    s1.create(3);
    s1.create(4);
    s1.create(5);
    std::cout << "LL1 After Create:" << std::endl;
    s1.display();

    s1.reverse();
    std::cout << "LL1 After Reverse:" << std::endl;
    s1.display();

    Singly s2 = Singly();
    s2.create(20);
    s2.create(3);
    s2.create(41);
    s2.create(6);
    s2.create(12);
    s2.create(9);
    s2.create(15);
    s2.create(14);
    s2.create(10);
    std::cout << "LL2 After Create:" << std::endl;
    s2.display();
    s2.segregate_even_odd();
    std::cout << "LL2 After Segregating Even and Odd numbers:" << std::endl;
    s2.display();
    return 0;
}
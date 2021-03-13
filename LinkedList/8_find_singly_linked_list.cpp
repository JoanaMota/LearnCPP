#include <iostream>

struct Node
{
    int data;
    Node * next;
};

class Singly
{
private:
    Node *m_tail, *m_head;
public:
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
    int count()
    {
        int counter = 0;
        Node * current = m_head;
        while (current != NULL)
        {
            counter++;
            current = current->next;
        }
        return counter;
    }
    bool search(int x)
    {
        Node * current = m_head;
        while (current != NULL)
        {
            if (x == current->data)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    int occurrences(int x)
    {
        int counter = 0;
        Node * current = m_head;
        while (current != NULL)
        {
            if (x == current->data)
            {
                counter++;
            }
            current = current->next;
        }
        return counter;
    } 
};


int main()
{ 
    Singly s1 = Singly();
    s1.create(2);
    s1.create(3);
    s1.create(3);
    s1.create(4);
    s1.create(4);
    s1.create(4);
    std::cout << "After Create:" << std::endl;
    s1.display();
    std::cout << "Length of Linked List: " << s1.count() << std::endl;
    std::cout << "Find key 3: "<< std::boolalpha << s1.search(3) << std::endl;
    std::cout << "Find key 5: "<< std::boolalpha << s1.search(5) << std::endl;
    std::cout << "How many keys 2: " << s1.occurrences(2) << std::endl;
    std::cout << "How many keys 3: " << s1.occurrences(3) << std::endl;
    std::cout << "How many keys 4: " << s1.occurrences(4) << std::endl;
    std::cout << "How many keys 5: " << s1.occurrences(5) << std::endl;
    
    return 0;
}
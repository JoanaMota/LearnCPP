#include <iostream>

struct Node
{
    int data;
    Node * next;
};

class Circular
{
private:
    Node *m_tail, *m_head;

public:
    Circular()
    {
        m_head = NULL;
        m_tail = NULL;
    };

    void create(int f_data)
    {
        Node *newNode = new Node;
        Node *temp;
        newNode->data = f_data;
        // First Node
        if (m_head == NULL)
        {
            m_head = newNode;
            newNode->next = NULL;
            temp = newNode;
            m_tail = newNode;
        }
        else
        {
            newNode->next = m_head;
            temp->next = newNode;
            temp = newNode;
            m_tail = newNode;
        }
    }
    void displayOnce()
    {
        Node *temp = new Node;
        temp = m_head;
        do
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        } while (temp != m_head);
    }

    void addStart(int f_data)
    {
        Node* newNode = new Node;
        newNode->data = f_data;
        newNode->next = m_head;
        m_head = newNode;
        m_tail->next = m_head;
    }

    void searching(int key)
    {
        Node* search = m_head;
        do
        {
            if (search->data == key)
            {
                std::cout << "Element " << key << " Exists" << std::endl;
            }
            search = search->next;
        } while (search != m_head);
    }

    void deleteElement(int key)
    {
        // If linked list is empty
        if (m_head == NULL)
            return;
            
        // If the list contains only a single node
        if(m_head->data==key && m_head->next==m_head)
        {
            free(m_head);
            m_head=NULL;
            return;
        }

        // If Head is to be deleted
        if(m_head->data==key)
        {
            m_head=m_head->next;
            m_tail->next=m_head;
            return;
        }
        Node* temp1, *temp2;
        temp1 = m_head;
        do
        {
            if (temp1->data == key)
            {
                // If Tail is to be deleted
                if(temp1 == m_tail)
                {
                    m_tail = temp2; 
                    m_tail->next = m_head;
                    free(temp1);
                    return;
                }
                else
                {
                    std::cout << "Element " << key << " Exists" << std::endl;
                    temp2->next = temp1->next;
                    free(temp1);
                    return;
                }
                
            }
            temp2 = temp1;
            temp1 = temp1->next;
        } while (temp1 != m_head);
    }
};

int main()
{
    Circular d1 = Circular();
    std::cout << "Creation" << std::endl; 
    d1.create(1);
    d1.create(2);
    d1.create(4);
    d1.create(5);
    d1.create(7);
    d1.create(8);
    d1.displayOnce();
    d1.searching(5);
    std::cout << "Adding to Start" << std::endl; 
    d1.addStart(0);
    d1.displayOnce();
    std::cout << "Deleting 4" << std::endl; 
    d1.deleteElement(4);
    d1.displayOnce();
    std::cout << "Deleting Head" << std::endl; 
    d1.deleteElement(0);
    d1.displayOnce();
    std::cout << "Deleting Tail" << std::endl; 
    d1.deleteElement(8);
    d1.displayOnce();
    return 0;
}
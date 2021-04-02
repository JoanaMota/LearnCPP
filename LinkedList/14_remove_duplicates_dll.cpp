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
    void removeDuplicatesSorted()
    {
        if (m_head == NULL || m_head->next == NULL)
            return;
        Node* current = m_head;
        while (current->next != NULL)
        {
            if (current->data == current->next->data)
                deleteNode(current->next);
            else
                current = current->next;
        }
    }
    void removeDuplicatesUnsorted()
    {
        if (m_head == NULL || m_head->next == NULL)
            return;
        Node* ptr1, * ptr2, * nextNode;

        for (ptr1 = m_head; ptr1 != NULL; ptr1 = ptr1->next) // Same as while loop
        {
            ptr2 = ptr1->next;
            while (ptr2 != NULL)
            {
                if (ptr1->data == ptr2->data)
                {
                    nextNode = ptr2->next;
                    deleteNode(ptr2);
                    ptr2 = nextNode;
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            
        }
        
    }
};

int main()
{
    Doubly d1 = Doubly();
    std::cout << "Sorted DLL" << std::endl;
    d1.create(1);
    d1.create(1);
    d1.create(2);
    d1.create(4);
    d1.create(4);
    d1.create(4);
    d1.create(8);
    d1.create(8);
    std::cout << "After Creation" << std::endl;
    d1.display();
    std::cout << "After Remove Duplicates" << std::endl;
    d1.removeDuplicatesSorted();
    d1.display();

    Doubly d2 = Doubly();
    std::cout << "Unsorted DLL" << std::endl;
    d2.create(4);
    d2.create(1);
    d2.create(8);
    d2.create(4);
    d2.create(4);
    d2.create(8);
    d2.create(2);
    d2.create(1);
    std::cout << "After Creation" << std::endl;
    d2.display();
    std::cout << "After Remove Duplicates" << std::endl;
    d2.removeDuplicatesUnsorted();
    d2.display();
    return 0;
}
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
    void newHead(int f_data)
    {
        Node* prevHead = m_head;
        Node* newNode = new Node;
        newNode->data = f_data;
        newNode->previous = NULL;
        m_head = newNode;
        m_head->next = prevHead;
        prevHead->previous = m_head; 
    }
    void addEnd(int f_data)
    {
        Node* endNode = m_head;
        while (endNode->next != NULL)
        {
            endNode = endNode->next;
        }
        Node* newNode = new Node;
        newNode->data = f_data;
        endNode->next = newNode;
        newNode->previous = endNode;
        newNode->next = NULL;
    }
    void addAfterNode(int f_key, int f_data)
    {
        Node* prevNode = m_head;
        Node* nextNode;
        while (prevNode->data != f_key)
        {
            prevNode = prevNode->next;
        }
        nextNode = prevNode->next;
        Node* newNode = new Node;
        newNode->data = f_data;
        prevNode->next = newNode;
        newNode->previous = prevNode;
        newNode->next = nextNode;
        nextNode->previous = newNode;
    }
    void addBeforeNode(int f_key, int f_data)
    {
        Node* nextNode = m_head;
        Node* prevNode;
        while (nextNode->data != f_key)
        {
            nextNode = nextNode->next;
        }
        prevNode = nextNode->previous;
        Node* newNode = new Node;
        newNode->data = f_data;
        nextNode->previous = newNode;
        newNode->previous = prevNode;
        newNode->next = nextNode;
        prevNode->next = newNode;
    }
};

int main()
{
    Doubly d1 = Doubly();
    d1.create(1);
    d1.create(2);
    d1.create(4);
    d1.create(8);
    d1.newHead(0);
    d1.addEnd(9);
    d1.addAfterNode(4,6);
    d1.addBeforeNode(4,3);
    d1.display();
    return 0;
}
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (NULL == head->next)
    {
        return nullptr;
    }

    ListNode *temp = head;
    int counter{0};
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }

    if (counter <= n)
    {
        return head->next;
    }

    temp = head;
    for (int i = 1; i < counter - n; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}
void print(ListNode *node)
{
    while (node != NULL)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print(head);
    ListNode *head2 = removeNthFromEnd(head, 10);
    print(head2);
    return 0;
}
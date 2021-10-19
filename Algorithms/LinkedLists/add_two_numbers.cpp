#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL, *current = new ListNode();
    int temp{0}, pass{0}, l1v{l1->val}, l2v{l2->val};
    while (true)
    {
        l1v = 0;
        l2v = 0;
        if (l1 != NULL)
        {
            l1v = l1->val;
        }
        if (l2 != NULL)
        {
            l2v = l2->val;
        }
        if (l1 == NULL && l2 == NULL && pass == 0)
        {
            break;
        }

        temp = l1v + l2v;
        temp += pass;
        pass = 0;
        if (temp >= 10)
        {
            pass = temp / 10;
            temp = temp % 10;
        }
        if (head == NULL)
        {
            head = new ListNode(temp);
            current = head;
        }
        else
        {
            current->next = new ListNode(temp);
            current = current->next;
        }
        if (l1 != NULL)
        {
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            l2 = l2->next;
        }
    }
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
    ListNode *head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    print(head1);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(6);
    print(head2);

    ListNode *output = addTwoNumbers(head1, head2);
    print(output);

    return 0;
}
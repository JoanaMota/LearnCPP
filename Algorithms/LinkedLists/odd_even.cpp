#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *headOut{NULL}, *headEven{NULL}, *odd{NULL}, *even{NULL};
    bool noOdd{true};

    odd = new ListNode(head->val);
    headOut = odd;
    head = head->next;

    if (head == NULL)
        return headOut;

    even = new ListNode(head->val);
    headEven = even;
    head = head->next;

    int index{2};
    while (head != NULL)
    {
        index++;
        if ((index % 2) == 0)
        {
            even->next = new ListNode(head->val);
            even = even->next;
        }
        else
        {
            odd->next = new ListNode(head->val);
            odd = odd->next;
        }
        head = head->next;
    }
    odd->next = headEven;
    return headOut;
}

ListNode *oddEvenListFaster(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = even->next;

        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenHead;

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
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    // head1->next->next->next = new ListNode(5);
    // head1->next->next->next->next = new ListNode(6);
    // head1->next->next->next->next->next = new ListNode(4);
    // head1->next->next->next->next->next->next = new ListNode(7);
    print(head1);

    ListNode *out = oddEvenListFaster(head1);
    print(out);
    return 0;
}
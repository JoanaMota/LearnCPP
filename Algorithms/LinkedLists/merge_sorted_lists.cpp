#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *node)
{
    while (node != NULL)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *head, *current;
    if (l1 == NULL && l2 == NULL)
        return NULL;
    else if (l1 != NULL && l2 == NULL)
        return l1;
    else if (l1 == NULL && l2 != NULL)
        return l2;

    if (l2->val < l1->val)
    {
        head = l2;
        l2 = l2->next;
    }
    else
    {
        head = l1;
        l1 = l1->next;
    }
    current = head;

    while (l2 != NULL && l1 != NULL)
    {
        if (l1->val >= l2->val)
        {
            current->next = l2;
            l2 = l2->next;
        }
        else if (l1->val < l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        current = current->next;
    }
    // If one list ended but we still have values in the other
    // we need to add in the end
    if (l1 != NULL)
        current->next = l1;
    if (l2 != NULL)
        current->next = l2;
    return head;
}

int main()
{
    ListNode *head1 = new ListNode(5);
    // head1->next = new ListNode(2);
    // head1->next->next = new ListNode(4);
    print(head1);
    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    print(head2);
    ListNode *headMerged = mergeTwoLists(head1, head2);
    print(headMerged);
    return 0;
}
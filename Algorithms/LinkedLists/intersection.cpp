#include <iostream>
#include <set>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    std::set<ListNode *> nodes;
    while (headA != NULL)
    {
        nodes.insert(headA);
        headA = headA->next;
    }
    while (headB != NULL)
    {
        if (nodes.count(headB))
        {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}
ListNode *getIntersectionNodeOnTimeO1Space(ListNode *headA, ListNode *headB)
{
    ListNode *headATemp = headA;
    ListNode *headBTemp = headB;
    while (headATemp != headBTemp)
    {
        headATemp = headATemp == NULL ? headB : headATemp->next;
        headBTemp = headBTemp == NULL ? headA : headBTemp->next;
    }
    return headATemp;
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
    ListNode *listA = new ListNode(4);
    listA->next = new ListNode(1);
    // listA->next->next = new ListNode(8);
    // listA->next->next->next = new ListNode(4);
    // listA->next->next->next->next = new ListNode(5);
    ListNode *listB = new ListNode(5);
    listB->next = new ListNode(6);
    listB->next->next = new ListNode(1);
    // listB->next->next->next = new ListNode(8);
    // listB->next->next->next->next = new ListNode(4);
    // listB->next->next->next->next->next = new ListNode(5);

    ListNode *combined = new ListNode(8);
    combined->next = new ListNode(4);
    combined->next->next = new ListNode(5);

    listA->next->next = combined;
    listB->next->next->next = combined;

    print(listA);
    print(listB);

    ListNode *listInt = getIntersectionNode(listA, listB);
    print(listInt);
    return 0;
}
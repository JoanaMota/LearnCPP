#include <iostream>
#include <vector>
#include <math.h>
#include <map>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *node, int size)
{
    int counter{0};
    while (node != NULL && counter != size * 2)
    {
        std::cout << node->val << " ";
        node = node->next;
        counter++;
    }
    std::cout << std::endl;
}
bool hasCycle(ListNode *head)
{
    std::map<ListNode *, int> list;
    bool isCycle{false};
    while (head != NULL && isCycle == false)
    {
        if (1 == list[head])
        {
            isCycle = true;
        }
        list[head] = 1;
        head = head->next;
    }
    return isCycle;
}
bool hasCycleSpaceO1(ListNode *head)
{
    if (!head || !head->next)
        return false;
    ListNode *slow = head->next, *fast = head->next->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
int main()
{
    ListNode *head = new ListNode(0);
    ListNode *first = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *second1 = new ListNode(4);
    ListNode *second2 = new ListNode(6);
    ListNode *second3 = new ListNode(8);
    ListNode *third = new ListNode(3);
    head->next = first;
    first->next = second;
    second->next = second1;
    second1->next = second2;
    second2->next = second3;
    second3->next = third;
    third->next = first;
    print(head, 8);
    std::cout << std::boolalpha << hasCycle(head) << std::endl;
    return 0;
}
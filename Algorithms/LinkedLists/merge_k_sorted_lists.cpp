#include <iostream>
#include <vector>
#include <queue>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct compare
{
    bool operator()(ListNode *l, ListNode *r)
    {
        return l->val > r->val;
    }
};

ListNode *mergeKListsFaster(std::vector<ListNode *> &lists)
{
    std::priority_queue<ListNode *, std::vector<ListNode *>, compare> q;
    for (auto l : lists)
    {
        if (l)
            q.push(l);
    }
    if (q.empty())
        return NULL;

    ListNode *result = q.top();
    q.pop();
    if (result->next)
        q.push(result->next);
    ListNode *tail = result;
    while (!q.empty())
    {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if (tail->next)
            q.push(tail->next);
    }
    return result;
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

ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
    if (0 == lists.size())
    {
        return nullptr;
    }
    if (1 == lists.size())
    {
        return lists[0];
    }

    ListNode *merged = lists[0];
    ListNode *mergedHead = merged;
    for (int i = 1; i < lists.size(); i++)
    {
        merged = mergeTwoLists(merged, lists[i]);
    }
    return merged;
}

void print(ListNode *list)
{
    while (list != nullptr)
    {
        std::cout << list->val << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    std::vector<ListNode *> allLists(3);
    allLists[0] = list1;
    allLists[1] = list2;
    allLists[2] = list3;

    ListNode *merged = mergeKLists(allLists);
    print(merged);

    std::vector<ListNode *> allLists2(2);
    allLists2[0] = NULL;
    allLists2[1] = new ListNode(1);
    std::cout << allLists2.size() << std::endl;
    ListNode *merged2 = mergeKLists(allLists2);
    print(merged2);

    return 0;
}
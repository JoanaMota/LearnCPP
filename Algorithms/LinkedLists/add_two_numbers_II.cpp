#include <iostream>
#include <stack>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Reverse
ListNode *reverse(ListNode *list)
{
    ListNode *after = NULL;
    ListNode *before = NULL;
    while (list != NULL)
    {
        after = list->next;
        list->next = before;

        before = list;
        list = after;
    }
    return before;
}
ListNode *addTwoNumbersI(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL, *current = new ListNode();
    int temp{0}, pass{0}, l1v{l1->val}, l2v{l2->val};
    while (true)
    {
        if (l1 == NULL && l2 == NULL && pass == 0)
        {
            break;
        }
        l1v = 0;
        l2v = 0;
        if (l1 != NULL)
        {
            l1v = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            l2v = l2->val;
            l2 = l2->next;
        }

        temp = l1v + l2v + pass;
        pass = (int)(temp / 10);
        temp = temp % 10;
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
    }
    return head;
}
ListNode *addTwoNumbersReverse(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode *lSum = addTwoNumbersI(l1, l2);
    return reverse(lSum);
}

// Stack and fill linked list in reverse
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    std::stack<int> stack1;
    std::stack<int> stack2;
    while (l1 != NULL)
    {
        stack1.push(l1->val);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        stack2.push(l2->val);
        l2 = l2->next;
    }

    ListNode *head = NULL;
    int s1v{0}, s2v{0}, sum{0}, pass{0};
    while (true)
    {
        if (stack1.empty() && stack2.empty() && 0 == pass)
        {
            break;
        }
        s1v = 0;
        s2v = 0;
        if (!stack1.empty())
        {
            s1v = stack1.top();
            stack1.pop();
        }
        if (!stack2.empty())
        {
            s2v = stack2.top();
            stack2.pop();
        }

        sum = s1v + s2v + pass;
        pass = (int)(sum / 10);
        sum = sum % 10;
        ListNode *newNode = new ListNode(sum);
        newNode->next = head;
        head = newNode;
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
    ListNode *head1 = new ListNode(7);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    head1->next->next->next = new ListNode(3);
    print(head1);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    print(head2);

    ListNode *output = addTwoNumbersReverse(head1, head2);
    print(output);

    return 0;
}
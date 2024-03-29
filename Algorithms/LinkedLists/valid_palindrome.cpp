#include <iostream>
#include <vector>
#include <math.h>

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
void print(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
bool isPalindrome(ListNode *head)
{
    std::vector<int> list;
    while (head != NULL)
    {
        list.push_back(head->val);
        head = head->next;
    }
    int j = list.size() - 1;
    for (int i = 0; i < std::ceil(list.size() / 2); ++i)
    {
        if (list[i] != list[j - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ListNode *head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(2);
    // head->next->next->next->next = new ListNode(1);
    print(head);
    std::cout << std::boolalpha << isPalindrome(head) << std::endl;
    return 0;
}
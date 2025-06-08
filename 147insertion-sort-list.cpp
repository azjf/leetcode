#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode dummy, *cur = head;
        while (cur) {
            ListNode *next = cur->next, *gpre = &dummy;  // greater pre
            while (gpre->next && gpre->next->val < cur->val) {
                gpre = gpre->next;
            }
            cur->next = gpre->next;
            gpre->next = cur;
            cur = next;
        }
        return dummy.next;
    }
};


int main()
{
    Solution().insertionSortList(
        new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3)))));
    return 0;
}

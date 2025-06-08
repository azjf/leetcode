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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy, *cur = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

class Solution2
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        return recur(list1, list2);
    }

private:
    ListNode *recur(ListNode *l1, ListNode *l2)
    {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }
        ListNode *res;
        if (l1->val < l2->val) {
            l1->next = recur(l1->next, l2);
            res = l1;
        } else {
            l2->next = recur(l1, l2->next);
            res = l2;
        }
        return res;
    }
};

int main()
{
    Solution2 s;

    // do not care about memory leaks
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *res = s.mergeTwoLists(l1, l2);
    while (res) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    res = s.mergeTwoLists(nullptr, nullptr);
    while (res) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    res = s.mergeTwoLists(nullptr, new ListNode(0));
    while (res) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}

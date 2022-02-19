#include "ListNode.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        return recur(list1, list2);
    }

private:
    ListNode *recur(ListNode *list1, ListNode *list2)
    {
        if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }

        ListNode *result;
        if (list1->val < list2->val) {
            list1->next = recur(list1->next, list2);
            result = list1;
        } else {
            list2->next = recur(list1, list2->next);
            result = list2;
        }
        return result;
    }
};

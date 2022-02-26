#pragma once

#include "ListNode.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return recur(l1, l2, 0);
    }

private:
    ListNode *recur(ListNode *l1, ListNode *l2, int carry)
    {
        if (!l1 && !l2 && !carry) {
            return nullptr;
        }
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        return new ListNode(carry % 10, recur(l1, l2, carry / 10));
    }
};

#pragma once

#include "ListNode.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy, *pre = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            pre->next = new ListNode(carry % 10);
            carry /= 10;
            pre = pre->next;
        }
        return dummy.next;
    }
};

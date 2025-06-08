#pragma once

#include "ListNode.h"

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummy(0, head), *pre = &dummy;
        while (pre->next) {
            if (pre->next->val == val) {
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }
        return dummy.next;
    }
};

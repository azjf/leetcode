#pragma once

#include "ListNode.h"

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0, head), *pre = &dummy, *cur = head;
        while (cur && cur->next) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = pre->next;
        }
        return dummy.next;
    }
};

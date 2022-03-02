#pragma once

#include "ListNode.h"

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        return recur(head);
    }

private:
    ListNode *recur(ListNode *cur) {
        if (!cur || !cur->next) {
            return cur;
        }
        ListNode *next = cur->next;
        cur->next = recur(next->next);
        next->next = cur;
        return next;
    }
};

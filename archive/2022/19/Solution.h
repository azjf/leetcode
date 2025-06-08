#pragma once

#include "ListNode.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0, head), *l = &dummy, *r = head;
        for (int i = 0; i != n; ++i) {
            r = r->next;
        }
        while (r) {
            r = r->next;
            l = l->next;
        }
        ListNode *nnext = l->next->next;
        delete l->next;
        l->next = nnext;
        return dummy.next;
    }
};

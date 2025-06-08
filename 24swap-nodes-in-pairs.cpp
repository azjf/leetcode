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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0, head), *pre = &dummy, *cur = head;
        while (cur && cur->next) {  // pre, cur, next
            auto next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

class Solution2
{
public:
    ListNode *swapPairs(ListNode *head) { return recur(head); }

private:
    ListNode *recur(ListNode *cur)
    {
        if (!cur || !cur->next) {
            return cur;
        }
        auto next = cur->next;
        cur->next = recur(next->next);
        next->next = cur;
        return next;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    public:
        ListNode *reverseList(ListNode *head) {
            if (!head) return nullptr;
            return recur(head);
        }

    private:
        ListNode *recur(ListNode *cur) {
            if (!cur->next) return cur;
            ListNode *res = recur(cur->next);
            cur->next->next = cur;  // cur->next is the tail of recur(cur->next)
            cur->next = nullptr;
            return res;
        }
};

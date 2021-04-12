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
            ListNode dummy, *cur = head;
            while (cur) {
                ListNode *next = cur->next;
                cur->next = dummy.next;
                dummy.next = cur;
                cur = next;
            }
            return dummy.next;
        }
};

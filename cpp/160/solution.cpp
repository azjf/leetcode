struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *n1 = headA, *n2 = headB;
            while (n1 != n2) {
                n1 = n1 ? n1->next : headB;
                n2 = n2 ? n2->next : headA;
            }
            return n1;
        }
};

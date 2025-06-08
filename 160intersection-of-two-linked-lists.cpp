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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        auto n1 = headA, n2 = headB;
        while (n1 != n2) {
            n1 = n1 ? n1->next : headB;
            n2 = n2 ? n2->next : headA;
        }
        return n1;
    }
};

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0, head), *l = &dummy, *r = head;
        while (n--) {  // r - l = n + 1
            r = r->next;
        }
        while (r) {
            l = l->next;
            r = r->next;
        }  // r = -(1 - 1), l = r - (n + 1) = -(n + 1), so l is just left before
           // -n
        r = l->next->next;
        delete l->next;
        l->next = r;
        return dummy.next;
    }
};

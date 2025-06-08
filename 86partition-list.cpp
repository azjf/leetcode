struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * partition() of quick sort does not keep order
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // l and r are pre-nodes
        // [0, l] < x
        ListNode dummy(0, head), *l = &dummy, *r = l;
        while (r->next) {
            ListNode *cur = r->next;
            if (cur->val < x) {
                if (r == l) {
                    r = r->next;
                    l = r;
                    continue;
                }
                // insert r->next into the position just after l->next
                r->next = cur->next;
                cur->next = l->next;
                l->next = cur;
                l = cur;
            } else {
                r = r->next;
            }
        }
        return dummy.next;
    }
};


class Solution2
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // {head1} < x, {head2} >= x
        ListNode dummy1(0, head), dummy2(0, head), *head1 = &dummy1,
                                                   *head2 = &dummy2;
        for (; head; head = head->next) {
            if (head->val < x) {
                head1->next = head;
                head1 = head;
            } else {
                head2->next = head;
                head2 = head;
            }
        }
        head2->next = nullptr;
        head1->next = dummy2.next;
        return dummy1.next;
    }
};

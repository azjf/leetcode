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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode dummy(0, head), *cur = &dummy;
        for (int i = 1; i != left; ++i) {
            cur = cur->next;
        }
        ListNode *tail1 = cur;  // head1..tail1..tail2..head2..head3..tail3
        cur = cur->next;
        ListNode *tail2 = cur, *head2 = nullptr;
        for (int i = left; i != right + 1; ++i) {
            ListNode *next = cur->next;
            cur->next = head2;
            head2 = cur;
            cur = next;
        }
        tail2->next = cur;
        tail1->next = head2;
        return dummy.next;
    }
};

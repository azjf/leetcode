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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !k) {  // the following algorithm only apply to k > 0
            return head;
        }

        ListNode *l = head, *r = l;
        // find the -k node
        int sz = 0;
        while (true) {
            if (!r) {  // one pass
                r = head;
                k %= sz;
                if (!k) {
                    return head;
                }
            }
            if (!k) {
                break;
            }
            r = r->next;
            --k;
            ++sz;
        }
        while (r->next) {  // k % size < size, so r is not nullptr
            r = r->next;
            l = l->next;
        }  // l is the -(k + 1) node, r is the tail

        auto *ans = l->next;
        l->next = nullptr;
        r->next = head;
        return ans;
    }
};

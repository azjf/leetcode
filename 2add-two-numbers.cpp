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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy, *pre = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            pre->next = new ListNode(carry % 10);
            carry /= 10;
            pre = pre->next;
        }
        return dummy.next;
    }
};

class Solution2
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return recur(l1, l2, 0);
    }

private:
    ListNode *recur(ListNode *l1, ListNode *l2, int carry)
    {
        if (!l1 && !l2 && !carry) {
            return nullptr;
        }
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        return new ListNode(carry % 10, recur(l1, l2, carry / 10));
    }
};

class Solution3
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy, *pre = &dummy;
        int carry = 0;
        while (l1 && l2) {
            carry += l1->val + l2->val;
            l1->val = carry % 10, carry /= 10;
            pre->next = l1, pre = pre->next;
            l1 = l1->next, l2 = l2->next;
        }
        pre->next = l1 ? l1 : l2;
        while (pre->next) {
            carry += pre->next->val;
            pre->next->val = carry % 10, carry /= 10;
            pre = pre->next;
        }
        if (carry) {
            pre->next = new ListNode(carry);
        }
        return dummy.next;
    }
};

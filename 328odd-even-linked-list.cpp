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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head) { return nullptr; }
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even && even->next) {
            // if even == nullptr, then odd is the last node and there has no
            // need to continue.
            // if even->next == nullptr, then even is the last node of the even
            // list, and there still has no need to continue.
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;  // odd is always not nullptr
        return head;
    }
};


class Solution2
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode dummyOdd, dummyEven, *odd = &dummyOdd, *even = &dummyEven;
        ListNode *cur = head;
        bool isOdd = true;
        while (cur) {
            if (isOdd) {
                odd->next = cur;
                odd = cur;
            } else {
                even->next = cur;
                even = cur;
            }
            cur = cur->next;
            isOdd = !isOdd;
        }
        odd->next = dummyEven.next;
        even->next = nullptr;
        return dummyOdd.next;
    }
};

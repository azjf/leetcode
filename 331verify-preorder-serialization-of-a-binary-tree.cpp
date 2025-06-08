#include <iostream>
#include <stack>
#include <string>

class Solution
{
public:
    bool isValidSerialization(std::string preorder)
    {
        // stk[i]: the count of empty slots for current node
        std::stack<int> stk;
        stk.push(1);  // dummy head
        std::string::size_type pos = 0, ppos = pos;
        while (true) {
            pos = preorder.find(',', pos);
            if (pos == std::string::npos) {
                if (ppos < preorder.size()) {
                    pos = preorder.size();
                } else {
                    break;
                }
            }
            if (stk.empty()) { return false; }
            --stk.top();  // current node consume a slot of its parent node
            if (!stk.top()) { stk.pop(); }
            if (pos - ppos > 1 || preorder[ppos] != '#') { stk.push(2); }
            ppos = ++pos;
        }
        return stk.empty();
    }
};


/*
 * replace the count stack of Solution with count sum
 */
class Solution2
{
public:
    bool isValidSerialization(std::string preorder)
    {
        // the count of total empty slots for all nodes before current node
        //
        // every out edge consumes a empty slot and every non-empty node adds
        // two empty slots, so the count of total empty slots exactly equals to
        // the difference between the out-degree and in-degree of the tree graph
        int slots = 1;  // dummy head
        std::string::size_type pos = 0, ppos = pos;
        while (true) {
            pos = preorder.find(',', pos);
            if (pos == std::string::npos) {
                if (ppos < preorder.size()) {
                    pos = preorder.size();
                } else {
                    break;
                }
            }
            if (!slots) { return false; }
            --slots;  // current node consume a slot of its parent node
            if (pos - ppos > 1 || preorder[ppos] != '#') { slots += 2; }
            ppos = ++pos;
        }
        return !slots;
    }
};


int main()
{
    Solution().isValidSerialization("9,#,92,#,#");
    return 0;
}

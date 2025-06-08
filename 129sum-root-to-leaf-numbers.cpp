#include <queue>
#include <stack>


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(right), right(right)
    {}
};


class Solution
{
public:
    int sumNumbers(TreeNode *root) { return recur(root, 0); }

private:
    int recur(TreeNode *cur, int sum)
    {
        if (!cur) {
            return 0;
        }
        sum = sum * 10 + cur->val;
        if (!cur->left && !cur->right) {
            return sum;
        }
        return recur(cur->left, sum) + recur(cur->right, sum);
    }
};


class Solution2
{
public:
    int sumNumbers(TreeNode *root)
    {
        std::stack<TreeNode *> stk;
        std::stack<int> sums;
        TreeNode *cur = root;
        int res = 0, sum = 0, parentSum = 0;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                sum = parentSum * 10 + cur->val;
                sums.push(sum);
                cur = cur->left;
                parentSum = sum;
            }
            cur = stk.top(), stk.pop();
            sum = sums.top(), sums.pop();
            if (!cur->left && !cur->right) {
                res += sum;
            }
            cur = cur->right;
            parentSum = sum;
        }
        return res;
    }
};


class Solution3
{
public:
    int sumNumbers(TreeNode *root)
    {
        int res = 0;
        std::queue<TreeNode *> q;
        std::queue<int> sums;
        if (root) {
            q.push(root);
            sums.push(root->val);
        }
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i != sz; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                int sum = sums.front();
                sums.pop();
                if (!cur->left && !cur->right) {
                    res += sum;
                }
                if (cur->left) {
                    q.push(cur->left);
                    sums.push(sum * 10 + cur->left->val);
                }
                if (cur->right) {
                    q.push(cur->right);
                    sums.push(sum * 10 + cur->right->val);
                }
            }
        }
        return res;
    }
};


int main()
{
    Solution3().sumNumbers(new TreeNode(1, new TreeNode(2), new TreeNode(3)));
    return 0;
}

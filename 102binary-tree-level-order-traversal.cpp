#include <queue>
#include <vector>


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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }
        std::vector<std::vector<int>> res;
        while (!q.empty()) {
            int sz = q.size();
            std::vector<int> vec;
            for (int i = 0; i != sz; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                vec.push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};


class Solution2
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        if (root) {
            q.push(root);
            q.push(nullptr);
        }
        std::vector<std::vector<int>> res;
        while (!q.empty()) {
            std::vector<int> vec;
            TreeNode *cur = q.front();
            q.pop();
            while (cur) {
                vec.push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                cur = q.front(), q.pop();
            }
            if (!q.empty()) {
                q.push(nullptr);
            }
            res.push_back(vec);
        }
        return res;
    }
};


class Solution3
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        recur(root, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    void recur(TreeNode *cur, int level)
    {
        if (!cur) {
            return;
        }
        if (level >= res.size()) {
            res.push_back({});
        }
        res[level].push_back(cur->val);
        recur(cur->left, level + 1);
        recur(cur->right, level + 1);
    }
};

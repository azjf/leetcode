#include <list>
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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> q;
        bool left = true;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int sz = q.size();
            std::list<int> ilist;
            for (int i = 0; i != sz; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                if (left) {
                    ilist.push_back(cur->val);
                } else {
                    ilist.push_front(cur->val);
                }
            }
            res.push_back(std::vector<int>(ilist.cbegin(), ilist.cend()));
            left = !left;
        }
        return res;
    }
};


// Solution2 is nearly the same as Solution


class Solution3
{
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
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
        if (level % 2) {
            // TODO fix inserting at the front of vector
            res[level].insert(res[level].cbegin(), cur->val);
        } else {
            res[level].push_back(cur->val);
        }
        recur(cur->left, level + 1);
        recur(cur->right, level + 1);
    }
};

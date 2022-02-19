#include <queue>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
        int maxDepth(TreeNode *root) {
            std::queue<TreeNode*> queue;
            if (root) queue.push(root);
            int ans = 0;
            while (!queue.empty()) {
                int sz = queue.size();
                for (int i = 0; i < sz; i++) {
                    TreeNode *cur = queue.front();
                    queue.pop();
                    if (cur->left) queue.push(cur->left);
                    if (cur->right) queue.push(cur->right);
                }
                ++ans;
            }
            return ans;
        }
};

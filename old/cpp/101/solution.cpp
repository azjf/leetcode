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
        bool isSymmetric(TreeNode *root) {
           return recur(root->left, root->right);
        }

    private:
        bool recur(TreeNode *l, TreeNode *r) {
            if (!l && !r) return true;
            if (!l || !r || l->val != r->val) return false;
            return recur(l->left, r->right) && recur(l->right, r->left);
        }
};

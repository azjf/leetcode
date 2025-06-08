#include <string>

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
    std::string tree2str(TreeNode *root) { return recur(root); }

private:
    std::string recur(TreeNode *cur)
    {
        if (!cur) {
            return "";
        }
        std::string l = recur(cur->left);
        std::string r = recur(cur->right);
        std::string res(std::to_string(cur->val));
        if (!l.empty() || !r.empty()) {
            res += "(" + l + ")";
        }
        if (!r.empty()) {
            res += "(" + r + ")";
        }
        return res;
    }
};

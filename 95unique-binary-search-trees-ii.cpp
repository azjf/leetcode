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
    std::vector<TreeNode *> generateTrees(int n) { return recur(1, n); }

private:
    std::vector<TreeNode *> recur(int min, int max)
    {
        if (min > max) {
            return {nullptr};
        }
        std::vector<TreeNode *> res;
        for (int i = min; i != max + 1; ++i) {
            const auto ls = recur(min, i - 1);  // [min, i)
            const auto rs = recur(i + 1, max);  // (i, max]
            for (auto l : ls) {
                for (auto r : rs) {
                    res.push_back(new TreeNode(i, l, r));
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution().generateTrees(1);
    return 0;
}

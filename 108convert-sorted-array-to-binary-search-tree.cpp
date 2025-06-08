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
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        return recur(nums, 0, nums.size());
    }

private:
    TreeNode *recur(std::vector<int> &nums, decltype(nums.size()) l,
                    decltype(nums.size()) r)
    {
        if (l >= r) {
            return nullptr;
        }
        auto mid = l + (r - l) / 2;
        return new TreeNode(nums[mid], recur(nums, l, mid),
                            recur(nums, mid + 1, r));
    }
};

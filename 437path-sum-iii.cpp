#include <map>

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
    int pathSum(TreeNode *root, int targetSum)
    {
        return recur(root, targetSum);
    }

private:
    int recur(TreeNode *cur, long sum)
    {
        if (!cur) {
            return 0;
        }
        int cnt = 0;
        cnt += recur(cur->left, sum);
        cnt += recur(cur->right, sum);
        cnt += helper(cur, sum);  // can not be replaced with two recur(), or
                                  // some path will be counted multi-times
        return cnt;
    }

    int helper(TreeNode *cur, long sum)
    {
        if (!cur) {
            return 0;
        }
        int cnt = 0;
        if (cur->val == sum) {
            ++cnt;
            ;
        }
        cnt += helper(cur->left, sum - cur->val);
        cnt += helper(cur->right, sum - cur->val);
        return cnt;
    }
};

class Solution2
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        return backtrack(root, targetSum, 0);
    }

private:
    std::map<long, int> prefix = {{0, 1}};  // prefix sum

    // f(cur, sum) = prefixSum[sum + val - targetSum] + f(left, sum + val) +
    // f(right, sum + val)
    int backtrack(TreeNode *cur, int targetSum, long sum)
    {
        if (!cur) {
            return 0;
        }

        int cnt = 0;
        sum += cur->val;
        long residual = sum - targetSum;
        if (prefix.count(residual)) {
            cnt += prefix[residual];
        }

        ++prefix[sum];  // prefix sums that including current node
        cnt += backtrack(cur->left, targetSum, sum);
        cnt += backtrack(cur->right, targetSum, sum);
        --prefix[sum];  // restore status
        return cnt;
    }
};

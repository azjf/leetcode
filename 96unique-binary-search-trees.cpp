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


/*
 * dp[n] = \sum{dp[i] \times dp[n - 1 - i]}
 */
class Solution
{
public:
    int numTrees(int n)
    {
        std::vector<int> dp(n + 1, 0);  // i -> dp[i + 1]
        dp[0] = 1;
        for (int i = 1; i != n + 1; ++i) {
            for (int j = 0; j != i; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};


/*
 * f(n) = \sum{f(i) \times f(n - 1 - i)}
 */
class Solution2
{
public:
    int numTrees(int n)
    {
        visited = std::vector<int>(n + 1, 0);
        visited[0] = 1;
        return recur(n);
    }

private:
    std::vector<int> visited;  // without cache will cause timeout
    int recur(int n)
    {
        if (visited[n]) {
            return visited[n];
        }
        int res = 0;
        for (int i = 0; i != n; ++i) {
            res += recur(i) * recur(n - 1 - i);
        }
        visited[n] = res;
        return res;
    }
};

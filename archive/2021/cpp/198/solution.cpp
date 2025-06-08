#include <vector>

using namespace std;


class Solution
{
public:
    int rob(vector<int>& nums)
    {
        // dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
        int pre = 0, ppre = 0;
        for (int num : nums) {
            int cur = max(pre, ppre + num);
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};

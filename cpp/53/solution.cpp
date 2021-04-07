#include <vector>

using namespace std;


class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            // dp[i]: the max sum of subarrays ending with num[i]
            // dp[i] = max(dp[i - 1] + nums[i], nums[i])
            int dp = nums[0], ans = dp;
            for (int i = 1; i < nums.size(); i++) {
                dp = nums[i] + max(dp, 0);
                ans = max(ans, dp);
            }
            return ans;
        }
};

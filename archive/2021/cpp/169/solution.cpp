#include <vector>

using namespace std;


class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int ans = 0, cnt = 0;
        for (int num : nums) {
            if (num == ans) {
                ++cnt;
            } else if (cnt > 0) {
                --cnt;
            } else {
                ans = num;
                cnt = 1;
            }
        }
        return ans;
    }
};

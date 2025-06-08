#include <vector>

/*
 * Let different numbers cancel each other out, then the remaining will be the
 * majority
 */
class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int ret = 0, cnt = 0;
        for (const auto &n : nums) {
            if (n == ret) {
                ++cnt;
            } else {
                if (cnt) {
                    --cnt;
                } else {
                    ret = n;
                    cnt = 1;
                }
            }
        }
        return ret;
    }
};

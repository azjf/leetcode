#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> res;
        auto sz = nums.size();
        for (auto i = 0; i != sz; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int l = i + 1, r = sz - 1; l < r;) {
                int sum = nums[i] + nums[l] + nums[r];
                if (!sum) {
                    res.push_back({nums[i], nums[l], nums[r]});
                }
                if (sum <= 0) {
                    do {
                        ++l;
                    } while (l < r && nums[l] == nums[l - 1]);
                }
                if (sum >= 0) {
                    do {
                        --r;
                    } while (l < r && nums[r] == nums[r + 1]);
                }
            }
        }
        return res;
    }
};

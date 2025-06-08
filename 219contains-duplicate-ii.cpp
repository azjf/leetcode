#include <map>
#include <vector>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::map<int, int> m;
        for (auto i = 0; i != nums.size(); ++i) {
            auto n = nums[i];
            if (m.count(n) && (i - m[n] <= k)) {
                return true;
            } else {
                m[n] = i;
            }
        }
        return false;
    }
};

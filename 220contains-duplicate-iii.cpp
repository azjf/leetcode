#include <cmath>
#include <map>
#include <vector>


/*
 * bucket sort
 * bucketNo(x) = x / (t + 1)
 * if bucketNo(x) == bucketNo(y),  then abs(x - y) <= t
 *
 * in 219 contains-duplicate-ii, bucket saves nums[i] (not nums[i] / (t + 1)),
 * and there is no need to remove nums[i - k]
 */
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int indexDiff,
                                       int valueDiff)
    {
        auto floorDiv = [](int x, int y) {
            y = x / y;
            return y - (x < 0);
        };
        std::map<int, int> bucket;
        for (int i = 0; i != nums.size(); ++i) {
            int key = floorDiv(nums[i], (valueDiff + 1));
            if (bucket.count(key)) { return true; }
            if (bucket.count(key + 1) &&
                std::abs(nums[i] - bucket[key + 1]) <= valueDiff) {
                return true;
            }
            if (bucket.count(key - 1) &&
                std::abs(nums[i] - bucket[key - 1]) <= valueDiff) {
                return true;
            }
            bucket[key] = nums[i];
            if (i >= indexDiff) {
                bucket.erase(floorDiv(nums[i - indexDiff], (valueDiff + 1)));
            }
        }
        return false;
    }
};


int main()
{
    std::vector<int> nums{-3, 3};
    Solution().containsNearbyAlmostDuplicate(nums, 2, 4);
    return 0;
}

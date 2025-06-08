#include <algorithm>
#include <list>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        visited = std::vector<bool>(nums.size(), false);
        recur(nums);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<bool> visited;
    std::vector<int> ivec;

    void recur(std::vector<int> &nums)
    {
        if (ivec.size() == nums.size()) {
            res.push_back(ivec);
            return;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (visited[i] ||
                (i > 0 && visited[i - 1] && nums[i] == nums[i - 1])) {
                // nums[] is sorted, so if nums[i] == nums[i - 1], we should not
                // choose it to avoid duplication (nums[i - 1] has already been
                // selected in this round)
                continue;
            }
            ivec.push_back(nums[i]);
            visited[i] = true;
            recur(nums);
            ivec.pop_back();
            visited[i] = false;
        }
    }
};


/**
 * The solution 2 of 46permutions can not be applied, because it is not easy to
 * deduplicate the cases such as [(1, 1), 2, (1, *1*)] for it use the
 * *insertion* method (not the selection method used in the solution 1 and 2)
 */
class Solution2
{};


class Solution3
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        recur(nums, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;

    void recur(std::vector<int> nums, int lo)
    {
        if (lo == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = lo; i != nums.size(); ++i) {
            // nums[0..lo - 1] has already been determined
            // [*1*, 1, *2*, 2] -> [*2*, 1, *1*, 2]
            if (i != lo && nums[i] == nums[lo]) {
                // nums[i] == numsPrev[i - 1] == nums[lo]
                // nums[] is sorted, so nums[i] ==  numsPrev[i - 1] should not
                // be selected to can avoid nums[i] being processed twice, which
                // is the same as 40combination-sum-ii
                continue;
            }
            std::swap(nums[i], nums[lo]);
            recur(nums, lo + 1);  // nums must be copied, because nums[] can not
                                  // be easily restored?
            // std::swap(nums[i], nums[lo]);  // error
        }
    }
};


int main()
{
    std::vector<int> nums{1, 1, 2};
    Solution().permuteUnique(nums);

    nums = {2, 2, 1, 1};
    Solution().permuteUnique(nums);
    return 0;
}

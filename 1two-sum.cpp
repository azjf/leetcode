#include <iostream>
#include <map>
#include <memory>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::map<int, decltype(nums.size())> m;
        std::vector<int> res;
        for (auto i = 0; i != nums.size(); ++i) {
            int x = nums[i], y = target - x;
            if (m.count(y)) {
                res = {static_cast<int>(i), static_cast<int>(m[y])};
                break;
            } else {
                m[x] = i;
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;

    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;
    std::vector<int> res = solution.twoSum(nums, target);
    std::cout << res[0] << " " << res[1] << std::endl;

    nums = {3, 2, 4}, target = 6, res = solution.twoSum(nums, target);
    std::cout << res[0] << " " << res[1] << std::endl;

    nums = {3, 3}, target = 6, res = solution.twoSum(nums, target);
    std::cout << res[0] << " " << res[1] << std::endl;
    return 0;
}

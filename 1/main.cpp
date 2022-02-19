#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;
    auto result = Solution().twoSum(nums, target);
    std::cout << result[0] << " " << result[1] << std::endl;

    nums = {3, 2, 4};
    target = 6;
    result = Solution().twoSum(nums, target);
    std::cout << result[0] << " " << result[1] << std::endl;

    nums = {3, 3};
    target = 6;
    result = Solution().twoSum(nums, target);
    std::cout << result[0] << " " << result[1] << std::endl;
    return 0;
}

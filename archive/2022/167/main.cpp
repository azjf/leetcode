#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;
    auto result = Solution().twoSum(nums, target);
    std::cout << result[0] << " " << result[1] << std::endl;

    nums = {2, 3, 4};
    target = 6;
    result = Solution().twoSum(nums, target);
    std::cout << result[0] << " " << result[1] << std::endl;

    nums = {-1, 0};
    target = -1;
    result = Solution().twoSum(nums, target);
    std::cout << result[0] << " " << result[1] << std::endl;
    return 0;
}

#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = Solution().maxSubArray(nums);
    std::cout << result << std::endl;

    nums = {1};
    result = Solution().maxSubArray(nums);
    std::cout << result << std::endl;

    nums = {5, 4, -1, 7, 8};
    result = Solution().maxSubArray(nums);
    std::cout << result << std::endl;
    return 0;
}

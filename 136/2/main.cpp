#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{2, 2, 1};
    auto result = Solution().singleNumber(nums);
    std::cout << result << std::endl;

    nums = {4, 1, 2, 1, 2};
    result = Solution().singleNumber(nums);
    std::cout << result << std::endl;
    return 0;
}

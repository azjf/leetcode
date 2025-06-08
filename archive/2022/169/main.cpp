#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{3, 2, 3};
    auto result = Solution().majorityElement(nums);
    std::cout << result << std::endl;

    nums = {2, 2, 1, 1, 1, 2, 2};
    result = Solution().majorityElement(nums);
    std::cout << result << std::endl;
    return 0;
}

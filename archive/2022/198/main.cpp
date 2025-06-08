#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{1, 2, 3, 1};
    auto result = Solution().rob(nums);
    std::cout << result << std::endl;

    nums = {2, 7, 9, 3, 1};
    result = Solution().rob(nums);
    std::cout << result << std::endl;
    return 0;
}

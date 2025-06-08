#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{1, 1, 2};
    auto result = Solution().removeDuplicates(nums);
    std::cout << result << std::endl;

    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    result = Solution().removeDuplicates(nums);
    std::cout << result << std::endl;
    return 0;
}

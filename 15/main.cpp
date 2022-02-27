#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution().threeSum(nums);
    nums = {};
    Solution().threeSum(nums);
    return 0;
}

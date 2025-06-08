#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{1, 2, 3, 1};
    int k = 3;
    auto result = Solution().containsNearbyDuplicate(nums, k);
    std::cout << (result ? "true" : "false") << std::endl;

    nums = {1, 0, 1, 1};
    k = 1;
    result = Solution().containsNearbyDuplicate(nums, k);
    std::cout << (result ? "true" : "false") << std::endl;

    nums = {1, 2, 3, 1, 2, 3};
    k = 2;
    result = Solution().containsNearbyDuplicate(nums, k);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

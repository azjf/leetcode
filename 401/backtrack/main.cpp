#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> nums{1, 2, 3};
    auto ans = Solution().permut(nums);
    for (const auto &ivec : ans) {
        for (const auto &i : ivec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

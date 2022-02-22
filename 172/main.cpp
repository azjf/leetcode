#include <iostream>
#include "Solution.h"

int main()
{
    int n = 3;
    auto result = Solution().trailingZeroes(n);
    std::cout << result << std::endl;

    n = 5;
    result = Solution().trailingZeroes(n);
    std::cout << result << std::endl;
    return 0;
}

#include <iostream>
#include "Solution.h"

int main()
{
    int n = 6;
    auto result = Solution().isUgly(n);
    std::cout << (result ? "true" : "false") << std::endl;

    n = 8;
    result = Solution().isUgly(n);
    std::cout << (result ? "true" : "false") << std::endl;

    n = 14;
    result = Solution().isUgly(n);
    std::cout << (result ? "true" : "false") << std::endl;

    n = 1;
    result = Solution().isUgly(n);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

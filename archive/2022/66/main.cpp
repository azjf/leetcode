#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> digits{1, 2, 3};
    auto result = Solution().plusOne(digits);

    digits = {4, 3, 2, 1};
    result = Solution().plusOne(digits);

    digits = {0};
    result = Solution().plusOne(digits);
    return 0;
}

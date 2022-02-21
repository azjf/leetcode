#include <iostream>
#include "Solution.h"

int main()
{
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    auto result = Solution().maxProfit(prices);
    std::cout << result << std::endl;

    prices = {1, 2, 3, 4, 5};
    result = Solution().maxProfit(prices);
    std::cout << result << std::endl;

    prices = {7, 6, 4, 3, 1};
    result = Solution().maxProfit(prices);
    std::cout << result << std::endl;
    return 0;
}

#pragma once

#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        if (prices.empty()) {
            return -1;
        }

        int min = prices[0], profit = 0;
        for (decltype(prices.size()) i = 1; i != prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit = std::max(profit, prices[i] - min);
            } else {
                min = std::min(min, prices[i]);
            }
        }
        return profit;
    }
};

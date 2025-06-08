#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        if (prices.empty()) {
            return 0;
        }
        // profit[i] = max(profit, cur - buy[i - 1])
        // buy[i] = min(buy[i - 1], cur)
        int profit = 0, buy = prices[0];
        for (auto i = 1; i != prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit = std::max(profit, prices[i] - buy);
            } else {
                buy = std::min(buy, prices[i]);
            }
        }
        return profit;
    }
};

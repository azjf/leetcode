#include <vector>

using namespace std;


class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.empty()) return 0;

            // maxProfit[i] = max(maxProfit[i - 1], prices[i] - minPrice[i - 1]);
            // minPrice[i] = min(minPrice[i - 1], price[i])
            int maxProfit = 0, minPrice = prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit = max(maxProfit, prices[i] - minPrice);
                } else {
                    minPrice = min(minPrice, prices[i]);
                }
            }
            return maxProfit;
        }
};

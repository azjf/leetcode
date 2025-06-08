#include <vector>

/*
 * multi-state DP
 */
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int buy1 = -12345, buy2 = buy1, sell1 = 0, sell2 = 0;
        for (int p : prices) {
            // a stock can be bought and sold multi-times in the same day. If
            // buy1 is updated, then sell1/buy2/sell2 may also be updated.
            //
            // sell2 is always after buy1/sell1/buy2, so there is no need to
            // warry about action controductions between the buy and sell.
            // Moreover, if sell2 is not updated finally, then the stock
            // selection for sell2 will not be updated, even there are new the
            // stock selections for buy1/sell1/buy2.
            buy1 = std::max(buy1, -p);
            sell1 = std::max(sell1, buy1 + p);
            buy2 = std::max(buy2, sell1 + p);
            sell2 = std::max(sell2, buy2 + p);
        }
        return sell2;
    }
};

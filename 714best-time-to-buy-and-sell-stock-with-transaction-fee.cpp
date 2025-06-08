#include <map>
#include <tuple>
#include <vector>

/*
 * multi-state DP
 */
class Solution
{
public:
    int maxProfit(std::vector<int> &prices, int fee)
    {
        int one = -prices[0], zero = 0;
        for (int price : prices) {
            std::tie(one, zero) = std::make_pair(
                std::max(one, zero - price), std::max(zero, one + price - fee));
        }
        return zero;
    }
};


class Solution2a
{
public:
    int maxProfit(std::vector<int> &prices, int fee)
    {
        return recur(prices, fee, prices.size() - 1).second;
    }

private:
    std::pair<int, int> recur(const std::vector<int> &prices, int fee, int i)
    {
        if (!i) { return std::make_pair(-prices[0], 0); }
        int one, zero;
        std::tie(one, zero) = recur(prices, fee, i - 1);
        return std::make_pair(std::max(one, zero - prices[i]),
                              std::max(zero, one + prices[i] - fee));
    }
};


/*
 * timeout (35/44, 19/44 for no cache) when size(prices) is too large
 */
class Solution2b
{
public:
    int maxProfit(std::vector<int> &prices, int fee)
    {
        return recur(prices, fee, 0, false);
    }

private:
    std::map<int, int> cache;
    int recur(const std::vector<int> &prices, int fee, int i, bool hasOne)
    {
        if (i == prices.size()) { return 0; }
        int key = (i << 1) + hasOne;
        if (cache.count(key)) { return cache[key]; }
        int res =
            hasOne
                ? std::max(recur(prices, fee, i + 1, true),  // TODO cache it
                           recur(prices, fee, i + 1, false) + prices[i] - fee)
                : std::max(recur(prices, fee, i + 1, false),
                           recur(prices, fee, i + 1, true) - prices[i]);
        cache[key] = res;
        return res;
    }
};


/*
 * 309 rest-time-to-buy-and-sell-stock-with-cooldown
 */
class Solution3
{
public:
    int maxProfit(std::vector<int> &prices, int fee)
    {
        int sz = prices.size();
        int buy[sz];     // buy at day i
        int sell[sz];    // sell at day i
        int bought[sz];  // bought before day i
        int sold[sz];    // sold before day i
        buy[0] = bought[0] = -prices[0];
        sell[0] = sold[0] = 0;
        for (int i = 1; i != sz; i++) {
            buy[i] = std::max(sell[i - 1], sold[i - 1]) - prices[i];
            bought[i] = std::max(bought[i - 1], buy[i - 1]);
            sell[i] = std::max(buy[i - 1], bought[i - 1]) + prices[i] - fee;
            sold[i] = std::max(sold[i - 1], sell[i - 1]);
        }
        return std::max(sell[sz - 1], sold[sz - 1]);
    }
};


/*
 * greedy
 */
class Solution4
{
public:
    int maxProfit(std::vector<int> &prices, int fee)
    {
        int sz = prices.size();
        int buy = prices[0] + fee, profit = 0;
        for (int i = 1; i != sz; i++) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            } else if (prices[i] > buy) {
                profit += prices[i] - buy;
                buy = prices[i];  // in case of prices[i + 1] > prices[i]
            }
        }
        return profit;
    }
};

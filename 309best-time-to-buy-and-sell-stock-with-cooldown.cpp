#include <algorithm>
#include <vector>


class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int sz = prices.size();
        int one[sz];      // balance when holding a stake at day i
        int zero[sz];     // balance when not holding a stake at day i
        int buyable[sz];  // balance when able to buy a stake at day i
        one[0] = -prices[0];
        zero[0] = 0;
        buyable[0] = 0;
        for (int i = 1; i != sz; ++i) {
            one[i] = std::max(one[i - 1], buyable[i - 1] - prices[i]);
            // 1) buyable[i] = std::max({buyable[i - 1], zero[i - 1], 0});
            // 2) zero[i] >= buyable[i] >= buyable[i - 1]? so there is no need
            // to include buyable[i - 1] in max() for zero[i] and buyable[i]
            zero[i] = std::max(zero[i - 1], one[i - 1] + prices[i]);
            buyable[i] = std::max(zero[i - 1], 0);
        }
        return std::max(one[sz - 1], zero[sz - 1]);
    }
};


class Solution1a
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int sz = prices.size();
        int one = -prices[0];
        int zero = 0;
        int buyable = 0;
        for (int i = 1; i != sz; ++i) {
            int newOne = std::max(one, buyable - prices[i]);
            int newZero = std::max(zero, one + prices[i]);
            int newBuyable = std::max(zero, 0);
            one = newOne, zero = newZero, buyable = newBuyable;
        }
        return std::max(one, zero);
    }
};


/*
 *  buyable[] is removed
 */
class Solution1b
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int sz = prices.size();
        if (sz == 1) { return 0; }

        int one[sz];   // balance when holding a stake at day i
        int zero[sz];  // balance when not holding a stake at day i
        one[0] = -prices[0], one[1] = std::max(-prices[0], -prices[1]);
        zero[0] = 0, zero[1] = std::max(prices[1] - prices[0], 0);
        for (int i = 2; i != sz; ++i) {
            // the action is determated by argmax, so is it possible that the
            // action taken by buy[] controdict that by sell[]?
            one[i] = std::max(one[i - 1], zero[i - 2] - prices[i]);
            zero[i] = std::max(zero[i - 1], one[i - 1] + prices[i]);
        }
        return std::max(one[sz - 1], zero[sz - 1]);
    }
};


class Solution2
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int sz = prices.size();
        int buy[sz];     // buy at day i
        int sell[sz];    // sell at day i
        int bought[sz];  // bought before day i
        int sold[sz];    // sold before day i, cooled
        buy[0] = bought[0] = -prices[0];
        sell[0] = sold[0] = 0;
        for (int i = 1; i != sz; i++) {
            buy[i] = sold[i - 1] - prices[i];
            bought[i] = std::max(bought[i - 1], buy[i - 1]);
            sell[i] = std::max(buy[i - 1], bought[i - 1]) + prices[i];
            sold[i] = std::max(sold[i - 1], sell[i - 1]);
        }
        return std::max(sell[sz - 1], sold[sz - 1]);
    }
};


/*
 * (day, state)  # state: >=0 (one stake), -1 (no stake), -2 (cooldown)
 * (day, >=0) -> (day + 1, >=0 or -1)
 * (day, -1) -> (day + 1, -1 or -2)
 * (day, -2) -> (day + 1, -1)
 *
 * timeout for cases with large number of prices (208/210)
 */
class Solution3
{
public:
    int maxProfit(std::vector<int> &prices) { return recur(prices, 0, -1); }

private:
    /*
     * @return max profit
     */
    int recur(const std::vector<int> &prices, int i, int state)
    {
        if (i == prices.size() - 1) {
            return state >= 0 ? std::max(prices[i] - state, 0) : 0;
        }
        if (state >= 0) {  // 1 stake
            return std::max(recur(prices, i + 1, state),
                            recur(prices, i + 1, -2) + prices[i] - state);
        } else if (state == -1) {  // no stake at begaining of day i
            return std::max(recur(prices, i + 1, -1),
                            recur(prices, i + 1, prices[i]));
        } else if (state == -2) {  // cooldown
            return std::max(recur(prices, i + 1, -1), 0);
        }
        return -(1 << 20);
    }
};


/*
 * recur() returns current balance
 *
 * timeout for cases with large number of prices (208/210)
 */
class Solution3a
{
public:
    int maxProfit(std::vector<int> &prices) { return recur(prices, 0, -1); }

private:
    /*
     * @return balance
     *
     * FIX caching recur(i, state) leads to incorrect result
     */
    int recur(const std::vector<int> &prices, int i, int state)
    {
        if (i == prices.size() - 1) { return !state ? prices[i] : 0; }
        if (!state) {  // 1 stake
            return std::max(recur(prices, i + 1, state),
                            recur(prices, i + 1, -2) + prices[i]);
        } else if (state == -1) {  // no stake at begaining of day i
            return std::max(recur(prices, i + 1, -1),
                            recur(prices, i + 1, 0) - prices[i]);
        } else if (state == -2) {  // cooldown
            return std::max(recur(prices, i + 1, -1), 0);
        }
        return -(1 << 20);
    }
};


int main()
{
    std::vector<int> prices{1, 2, 3, 0, 2};
    Solution().maxProfit(prices);
    return 0;
}

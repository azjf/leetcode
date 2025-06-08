#include <map>
#include <string>

/*
 * dp[i] = dp[i - 1] (if s[i] != 0) + dp[i - 2] (if 1 <= s[i-1..i] <= 26)
 * bottom up
 */
class Solution
{
public:
    int numDecodings(std::string s)
    {
        int dp[s.size() + 1];  // dp[i] -> s[i - 1]
        dp[0] = 1;
        for (int i = 1; i != s.size() + 1; ++i) {
            dp[i] = 0;
            if (s[i - 1] - '0') {
                dp[i] += dp[i - 1];
            }
            if (i >= 2 && s[i - 2] != '0' &&
                ((s[i - 2] - '0') * 10 + s[i - 1] - '0') <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};


class Solution2
{
public:
    int numDecodings(std::string s)
    {
        int pre = 1, ppre = -1;
        for (int i = 1, cur = 0; i != s.size() + 1; ++i) {
            cur = 0;
            if (s[i - 1] - '0') {
                cur += pre;
            }
            if (i >= 2 && s[i - 2] != '0' &&
                ((s[i - 2] - '0') * 10 + s[i - 1] - '0') <= 26) {
                cur += ppre;
            }
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};


/*
 * f(idx) = f(idx + 1) (if s[i] != 0) + f(idx + 2) (if 1 <= s[idx..idx+1] <= 26)
 * top down
 */
class Solution3
{
public:
    int numDecodings(std::string s) { return recur(s, 0); }

private:
    std::map<int, int> imap;
    int recur(const std::string &s, int lo)
    {
        if (lo == s.size()) {
            return 1;
        }
        if (s[lo] == '0') {
            return 0;
        }

        if (!imap.count(lo + 1)) {
            imap[lo + 1] = recur(s, lo + 1);
        }
        int res = imap[lo + 1];
        if (lo < s.size() - 1 && ((s[lo] - '0') * 10 + s[lo + 1] - '0') <= 26) {
            if (!imap.count(lo + 2)) {
                imap[lo + 2] = recur(s, lo + 2);
            }
            res += imap[lo + 2];
        }
        return res;
    }
};


int main()
{
    Solution().numDecodings("12");
    return 0;
}

#include <iostream>
#include <string>
#include <vector>

/*
 * The core of palindrome is extending the current char
 */
class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        int maxLen = 0, beg = 0;
        for (auto i = 0; i != s.size(); ++i) {
            int l1 = extend(s, i, i);
            int l2 = extend(s, i, i + 1);
            int len = std::max(l1, l2);
            if (maxLen < len) {
                maxLen = len;
                beg = i - (len - 1) / 2;  // odd: (len - 1) / 2 = i - beg, even:
                                          // len / 2 = i + 1 - beg
            }
        }
        return s.substr(beg, maxLen);
    }

private:
    int extend(const std::string &s, int l, int r)
    {
        while (l >= 0 && r < s.size() &&
               s[l] == s[r]) {  // s[l] == s[r] should always be true, so do not
                                // use s[l--] == s[r++]
            --l, ++r;
        }
        return r - l + 1 - 2;  // now l/r is invalid
    }
};

class Solution2
{
public:
    std::string longestPalindrome(std::string s)
    {
        // dp[i][j]: s[i..j] is palindromic
        // dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
        // dp[i][i] = true
        // dp[i][i + 1] == s[i] == s[i + 1]
        // res = max(dp[i <= j])
        auto sz = s.size();
        std::vector<std::vector<bool>> dp(sz, std::vector<bool>(sz, false));
        int beg = 0, maxLen = 0;
        // iterating in the diagonal direction (top left to bottom right) so
        // that dp[i + 1][j - 1] has already been calculated iterating by line
        // ~j = i + d~
        for (auto d = 0; d != sz; ++d) {
            for (auto i = 0; i != sz - d; ++i) {
                auto j = i + d;
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = j - i < 2 ? true : dp[i + 1][j - 1];
                    if (dp[i][j]) {
                        auto len = j - i + 1;
                        if (len > maxLen) {
                            maxLen = len;
                            beg = i;
                        }
                    }
                }
            }
        }
        return s.substr(beg, maxLen);
    }
};

int main()
{
    std::cout << Solution2().longestPalindrome("babad") << std::endl;
    std::cout << Solution2().longestPalindrome("cbbd") << std::endl;
    return 0;
}

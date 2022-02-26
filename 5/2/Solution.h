#pragma once

#include <string>
#include <vector>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        auto sz = s.size();
        if (sz < 2) {
            return s;
        }

        int beg = 0, max_len = 0;

        // dp[i][j] = dp[i + 1][j - 1] && (s[i + 1] == s[j - 1])
        // dp[i][i + 1] = s[i] == s[i + 1]
        // dp[i][i] = true
        std::vector<std::vector<bool>> dp(sz, std::vector<bool>(sz));
        // sepcially designed iterating pattern
        for (decltype(sz) m = 0; m != sz; ++m) {
            // iterating by line: y = x + m;
            for (decltype(sz) i = 0; i != sz - m; ++i) {
                int j = i + m;
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    dp[i][j] = j - i < 2 ? true : dp[i + 1][j - 1];
                    if (dp[i][j]) {
                        int len = j - i + 1;
                        if (max_len < len) {
                            max_len = len;
                            beg = i;
                        }
                    }
                }
            }
        }
        return s.substr(beg, max_len);
    }
};

#pragma once

#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string &digits)
    {
        std::vector<std::string> ret;
        if (digits.empty()) {
            return ret;
        }

        std::string s;
        recur(ret, digits, 0, s);
        return ret;
    }

private:
    const std::vector<std::string> digit_map{"abc", "def",  "ghi", "jkl",
                                             "mno", "pqrs", "tuv", "wxyz"};

    void recur(std::vector<std::string> &svec, const std::string &digits,
               unsigned depth, std::string &s)
    {
        if (depth == digits.size()) {
            svec.push_back(s);
            return;
        }
        for (const auto c : digit_map[digits[depth] - '2']) {
            s.push_back(c);
            recur(svec, digits, depth + 1, s);
            s.erase(depth);
        }
    }
};

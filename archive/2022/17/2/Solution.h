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
        return recur(digits, 0, s);
    }

private:
    const std::vector<std::string> digit_map{"abc", "def",  "ghi", "jkl",
                                             "mno", "pqrs", "tuv", "wxyz"};

    std::vector<std::string> recur(const std::string &digits, unsigned depth,
                                   std::string s)
    {
        if (depth == digits.size()) {
            return std::vector<std::string>{s};
        }

        std::vector<std::string> ret;
        for (const auto &c : digit_map[digits[depth] - '2']) {
            for (const auto &str : recur(digits, depth + 1, s + c)) {
                ret.push_back(str);
            }
        }
        return ret;
    }
};

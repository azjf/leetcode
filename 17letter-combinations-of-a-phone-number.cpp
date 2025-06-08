#include <string>
#include <vector>

/*
 * Cartesian product
 * f(n) = [c1, c2, c3] + f(n-1)
 */
class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty()) {
            return {};
        }
        return recur(digits, 0);
    }

private:
    std::vector<std::string> d2s{"abc", "def",  "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> recur(const std::string &digits,
                                   int depth)  // how to return rvalue?
    {
        if (depth == digits.size()) {
            return {""};
        }
        std::vector<std::string> res;
        for (const auto &s : recur(digits, depth + 1)) {
            for (char c : d2s[digits[depth] - '2']) {
                res.push_back(c + s);
            }
        }
        return res;
    }
};

class Solution2
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty()) {
            return {};
        }
        std::vector<std::string> res;
        std::string s;
        recur(res, digits, 0, s);
        return res;
    }

private:
    std::vector<std::string> d2s{"abc", "def",  "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
    void recur(std::vector<std::string> &svec, const std::string &digits,
               int depth, std::string &s)
    {
        if (depth == digits.size()) {
            svec.push_back(s);
            return;
        }
        for (char c : d2s[digits[depth] - '2']) {
            s.push_back(c);
            recur(svec, digits, depth + 1,
                  s);  // inefficiently recur for multiple times
            s.erase(depth);
        }
    }
};

class Solution3
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty()) {
            return {};
        }
        return recur(digits, 0, "");
    }

private:
    std::vector<std::string> d2s{"abc", "def",  "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> recur(
        const std::string &digits, int depth,
        std::string s)  // s should be copyed every time
    {
        if (depth == digits.size()) {
            return {s};
        }
        std::vector<std::string> res;
        for (char c : d2s[digits[depth] - '2']) {
            for (const auto &str :
                 recur(digits, depth + 1,
                       s + c)) {  // inefficiently recur for multiple times
                res.push_back(str);
            }
        }
        return res;
    }
};

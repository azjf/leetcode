#pragma once

#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> ret;
        std::string s;
        recur(ret, n, s, 0, 0);
        return ret;
    }

private:
    void recur(std::vector<std::string> &ret, int n, std::string &s, int l,
               int r)
    {
        if (l > n || r > n) {
            return;
        }
        if (l == r && r == n) {
            ret.push_back(s);
            return;
        }
        if (l < r) {
            return;
        }
        s.push_back('(');
        recur(ret, n, s, l + 1, r);
        s.pop_back();
        s.push_back(')');
        recur(ret, n, s, l, r + 1);
        s.pop_back();
    }
};

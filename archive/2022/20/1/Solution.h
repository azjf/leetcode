#pragma once

#include <stack>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::unordered_map<char, char> parentheses{
            {'(', ')'}, {'{', '}'}, {'[', ']'}};
        bool result = true;
        std::stack<char> stk;
        for (const char &c : s) {
            if (parentheses.find(c) != parentheses.cend()) {
                stk.push(c);
            } else {
                if (stk.empty() || c != parentheses[stk.top()]) {
                    result = false;
                    break;
                }
                stk.pop();
            }
        }
        return stk.empty() && result;
    }
};

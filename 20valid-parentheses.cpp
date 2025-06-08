#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::map<char, char> parentheses = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        std::stack<char> stk;
        for (char c : s) {
            if (parentheses.count(c)) {
                stk.push(c);
            } else {
                if (stk.empty() || c != parentheses[stk.top()]) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};

class Solution2
{
public:
    bool isValid(std::string s)
    {
        std::map<char, char> parentheses = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        int top = -1;
        for (char c : s) {
            if (parentheses.count(c)) {
                s[++top] = c;
            } else {
                if (top == -1 || c != parentheses[s[top]]) {
                    return false;
                } else {
                    --top;
                }
            }
        }
        return top == -1;
    }
};

int main()
{
    Solution s;
    std::cout << s.isValid("()") << std::endl;
    std::cout << s.isValid("()[]{}") << std::endl;
    std::cout << s.isValid("(]") << std::endl;
    return 0;
}

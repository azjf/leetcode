#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isValid(std::string s)
    {
        const std::unordered_map<char, char> parentheses{
            {'(', ')'},
            {'{', '}'},
            {'[', ']'} };
        bool result = true;
        int top = -1;
        for (const char &c : s) {
            if (parentheses.find(c) != parentheses.cend()) {
                s[++top] = c;
            } else {
                if (top == -1 || c != parentheses.at(s[top])) {
                    result = false;
                    break;
                }
                --top;
            }
        }
        return top == -1 && result;
    }
};

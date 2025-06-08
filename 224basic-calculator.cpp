#include <cctype>
#include <stack>
#include <string>

class Solution
{
public:
    int calculate(std::string s)
    {
        int d = 0;
        return recur(s + '$', d);
    }

    int recur(const std::string &s, int &d)
    {
        std::stack<int> stk;
        char preOpr = '+';
        int num = 0;
        while (d != s.size()) {
            char c = s[d++];
            if (c == ' ') { continue; }
            if (c == '(') {
                num = recur(s, d);
            } else if (std::isdigit(c)) {
                num = num * 10 - '0' + c;  // -'0' + c to avoid overflow
            } else {
                switch (preOpr) {
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                }
                // put this if statement not in the outer if-else so that ')' to
                // make sure that preOpr will be consumed
                if (c == ')') { break; }
                num = 0;
                preOpr = c;
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};


int main()
{
    Solution().calculate("2147483647");
    return 0;
}

#include <cctype>
#include <stack>
#include <string>


class Solution
{
public:
    int calculate(std::string s)
    {
        int num = 0;
        char preOpr = '+';
        std::stack<int> stk;
        // '$' to make sure the last operator be processed
        for (char c : s + '$') {
            if (c == ' ') { continue; }
            if (std::isdigit(c)) {
                num = 10 * num - '0' + c;  // -'0' + c to avoid overflow
            } else {
                switch (preOpr) {
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    stk.top() *= num;
                    break;
                case '/':
                    stk.top() /= num;
                    break;
                }
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
    Solution().calculate(" 3/2 ");
    return 0;
}

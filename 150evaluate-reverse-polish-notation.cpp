#include <stack>
#include <string>
#include <vector>

class Solution
{
public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> nums;
        for (const auto &token : tokens) {
            if (std::isdigit(token.back())) {
                nums.push(std::stoi(token));
                continue;
            }
            int y = nums.top();
            nums.pop();
            int &x = nums.top();
            switch (token[0]) {
            case '+':
                x += y;
                break;
            case '-':
                x -= y;
                break;
            case '*':
                x *= y;
                break;
            case '/':
                x /= y;
                break;
            }
        }
        return nums.top();
    }
};


class Solution2
{
public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        // n(ops) = n(nums) - 1 -> n(nums) = (N + 1) / 2
        int nums[tokens.size() / 2 + 1], idx = 0;
        for (const auto &token : tokens) {
            if (std::isdigit(token.back())) {
                nums[idx++] = std::stoi(token);
                continue;
            }
            int y = nums[--idx], &x = nums[idx - 1];
            switch (token[0]) {
            case '+':
                x += y;
                break;
            case '-':
                x -= y;
                break;
            case '*':
                x *= y;
                break;
            case '/':
                x /= y;
                break;
            }
        }
        return nums[0];
    }
};


int main()
{
    std::vector<std::string> tokens{"2", "1", "+", "3", "*"};
    tokens = {"4", "13", "5", "/", "+"};
    Solution2().evalRPN(tokens);
    return 0;
}

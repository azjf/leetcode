#pragma once

#include <stack>


class MinStack
{
public:
    MinStack() {}

    void push(int val)
    {
        data.push(val);
        if (min.empty() || val <= min.top()) {
            min.push(val);
        }
    }

    void pop()
    {
        int top = data.top();
        data.pop();
        if (top == min.top()) {
            min.pop();
        }
    }

    int top() { return data.top(); }

    int getMin() { return min.top(); }

private:
    std::stack<int> data, min;
};

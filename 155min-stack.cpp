#include <stack>

class MinStack
{
public:
    MinStack() {}

    void push(int val)
    {
        data.push(val);
        if (min.empty() || val <= min.top()) {  // <=, not ==, or there will be
                                                // more pops than pushs for min
            min.push(val);
        }
    }

    void pop()
    {
        if (data.top() == min.top()) {
            min.pop();
        }
        data.pop();
    }

    int top() { return data.top(); }

    int getMin() { return min.top(); }

private:
    std::stack<int> data, min;
};

class MinStack2
{
public:
    void push(int val)
    {
        if (data.empty()) {
            min = val;
        }
        data.push(val - min);
        if (val < min) {
            min = val;
        }
    }

    void pop()
    {
        long val = data.top();
        data.pop();
        if (val < 0) {
            min -= val;
        }
    }

    int top() { return data.top() < 0 ? min : data.top() + min; }

    int getMin() { return min; }

private:
    std::stack<long> data;
    long min = 0;
};

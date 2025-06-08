#pragma once

#include <stack>

class MyQueue
{
public:
    MyQueue() {}

    void push(int x) { push_stack.push(x); }

    int pop()
    {
        if (pop_stack.empty()) {
            while (!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        int n = pop_stack.top();
        pop_stack.pop();
        return n;
    }

    int peek()
    {
        if (pop_stack.empty()) {
            while (!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        return pop_stack.top();
    }

    bool empty() { return pop_stack.empty() && push_stack.empty(); }

private:
    std::stack<int> push_stack, pop_stack;
};

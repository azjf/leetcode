#include <stack>

class MyQueue
{
public:
    MyQueue() {}

    void push(int x) { pushstk.push(x); }

    int pop()
    {
        if (popstk.empty()) {
            while (!pushstk.empty()) {
                popstk.push(pushstk.top());
                pushstk.pop();
            }
        }
        auto top = popstk.top();
        popstk.pop();
        return top;
    }

    int peek()
    {
        if (popstk.empty()) {
            while (!pushstk.empty()) {
                popstk.push(pushstk.top());
                pushstk.pop();
            }
        }
        return popstk.top();
    }

    bool empty() { return pushstk.empty() && popstk.empty(); }

private:
    std::stack<int> pushstk, popstk;
};

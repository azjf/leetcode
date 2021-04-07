#include <string>

using namespace std;


class Solution {
    public:
        bool isValid(string s) {
            int top = -1;
            for (int i = 0; i < s.length(); ++i) {
                if (top < 0 || !isMatch(s[top], s[i])) {
                    s[++top] = s[i];
                } else {
                    --top;
                }
            }
            return top == -1;
        }

        bool isMatch(char c1, char c2) {
            if (c1 == '(' && c2 == ')') return true;
            if (c1 == '{' && c2 == '}') return true;
            if (c1 == '[' && c2 == ']') return true;
            return false;
        }
};

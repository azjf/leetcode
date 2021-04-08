#include <string>

using namespace std;


class Solution {
    public:
        bool isPalindrome(string s) {
            if (s.empty()) return false;
            const char *l = s.c_str();
            const char *r = l + s.length() - 1;
            while (l < r) {
                if (!isalnum(*l)) {
                    ++l;
                    continue;
                }
                if (!isalnum(*r)) {
                    --r;
                    continue;
                }
                if (tolower(*l) != tolower(*r)) return false;
                ++l, --r;
            }
            return true;
        }
};

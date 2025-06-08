#include <string>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        auto l = s.cbegin(), r = s.cend() - 1;
        while (l < r) {
            if (!std::isalnum(*l)) {
                ++l;
                continue;
            }
            if (!std::isalnum(*r)) {
                --r;
                continue;
            }
            if (std::tolower(*l++) != std::tolower(*r--)) {
                return false;
            }
        }
        return true;
    }
};

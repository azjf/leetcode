#include <string>

class Solution
{
public:
    int removePalindromeSub(std::string s)
    {
        // if ~s~ is not palindromic, remove all 'a' and then remove all 'b'
        return isPalindromic(s) ? 1 : 2;
    }

private:
    bool isPalindromic(const std::string &s)
    {
        // return s == std::string(s.crbegin(), s.crend());
        auto l = s.cbegin(), r = s.cend() - 1;
        while (l < r) {
            if (*l != *r) {
                return false;
            }
            ++l, --r;
        }
        return true;
    }
};

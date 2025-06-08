#include <iterator>
#include <string>

class Solution
{
public:
    std::string convertToBase7(int num)
    {
        if (!num) {
            return "0";
        }

        std::string res(num < 0 ? "-" : "");
        num = std::abs(num);

        std::string s;
        int r = 0;
        while (num) {
            r = num % 7;
            num /= 7;
            s.push_back('0' + r);
        }

        std::copy(s.crbegin(), s.crend(), std::back_inserter(res));
        return res;
    }
};

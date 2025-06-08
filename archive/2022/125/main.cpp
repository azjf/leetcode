#include <iostream>
#include "Solution.h"

int main()
{
    std::string s("A man, a plan, a canal: Panama");
    auto result = Solution().isPalindrome(s);
    std::cout << (result ? "true" : "false") << std::endl;

    s = "race a car";
    result = Solution().isPalindrome(s);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

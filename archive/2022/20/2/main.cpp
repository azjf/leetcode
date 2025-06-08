#include <iostream>
#include "Solution.h"

int main()
{
    std::string s = "()";
    auto result = Solution().isValid(s);
    std::cout << (result ? "true" : "false") << std::endl;

    s = "()[]{}";
    result = Solution().isValid(s);
    std::cout << (result ? "true" : "false") << std::endl;

    s = "(]";
    result = Solution().isValid(s);
    std::cout << (result ? "true" : "false") << std::endl;

    s = "([)]";
    result = Solution().isValid(s);
    std::cout << (result ? "true" : "false") << std::endl;

    s = "{[]}";
    result = Solution().isValid(s);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

#include <iostream>
#include "Solution.h"

int main()
{
    std::uint32_t n = 0b00000010100101000001111010011100;
    auto result = Solution().reverseBits(n);
    std::cout << result << std::endl;

    n = 0b11111111111111111111111111111101;
    result = Solution().reverseBits(n);
    std::cout << result << std::endl;
    return 0;
}

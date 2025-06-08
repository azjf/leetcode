#include <functional>
#include <numeric>
#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        return std::accumulate(nums.cbegin(), nums.cend(), 0,
                               std::bit_xor<int>());
    }
};

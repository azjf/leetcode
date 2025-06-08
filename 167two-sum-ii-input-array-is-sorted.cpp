#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        decltype(numbers.size()) l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                break;
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return {static_cast<int>(++l), static_cast<int>(++r)};
    }
};

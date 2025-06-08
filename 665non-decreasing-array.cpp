#include <vector>

class Solution
{
public:
    bool checkPossibility(std::vector<int> &nums)
    {
        bool isFirstRound = true;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (isFirstRound) {
                    isFirstRound = false;
                    // [3, 4, 2, 3], [3, 4, 3, 3]
                    if (i >= 2 && nums[i] < nums[i - 2]) {
                        nums[i] = nums[i - 1];
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

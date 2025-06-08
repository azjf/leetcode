#include <limits>
#include <vector>


class Solution
{
public:
    bool increasingTriplet(std::vector<int> &nums)
    {
        int a1 = nums[0], a2 = std::numeric_limits<int>::max();
        for (int n : nums) {
            if (n > a2) {
                return true;
            } else if (n > a1) {
                // a2 will always become smaller
                a2 = n;
            } else {
                // a1 will always become smaller.
                // when a1 is updated, a2 will still refer to the older tuple,
                // but which does not matter.
                a1 = n;
            }
        }
        return false;
    }
};

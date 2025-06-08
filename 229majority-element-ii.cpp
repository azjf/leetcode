#include <vector>

/*
 * Boyer–Moore majority vote algorithm
 *
 * there are at most 2 numbers that satisfy the requirement.
 * all other numbers can be cancelled by them.
 *
 * n % 3 <= 2. the worse case is n == 5, where n / 3 == 1 and n % 3 == 2, in
 * which case the above speculations still hold.
 */
class Solution
{
public:
    std::vector<int> majorityElement(std::vector<int> &nums)
    {
        int v1 = -2 ^ 30, v2 = v1 - 1, c1 = 0, c2 = 0;
        for (int n : nums) {
            if (n == v1) {
                ++c1;
            } else if (n == v2) {
                ++c2;
            } else if (!c1) {
                v1 = n;
                ++c1;
            } else if (!c2) {
                v2 = n;
                ++c2;
            } else {
                --c1;
                --c2;
            }
        }

        c1 = 0, c2 = 0;
        for (int n : nums) {
            c1 += n == v1;
            c2 += n == v2;
        }

        std::vector<int> res;
        if (c1 > nums.size() / 3) { res.push_back(v1); }
        if (c2 > nums.size() / 3) { res.push_back(v2); }
        return res;
    }
};

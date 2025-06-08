#include <vector>

/*
 * maxArea = max(a_1, a_2, a_{n-1})
 * a_{n-1} is obtained by move the lower side of a_n (moving the higher side of
 * a_n only results in a smaller area)
 */
class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        auto l = height.cbegin(), r = height.cend() - 1;
        int res = 0;
        while (l < r) {
            res = std::max(res, std::min(*l, *r) * (int) (r - l));
            if (*l < *r) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};

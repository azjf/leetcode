#include <vector>

/*
 * [x, x, 1, 2, 3] -> [1, 2, 3] -> [1, 3, 2]
 * [3, 2, 1] -> [1, 2, 3]
 *
 * [1, 4, 2] -> [2, 4, 1] -> [2, 1, 4]
 * [3, 4, 2] -> [4, 3, 2] -> [4, 2, 3]
 * [1, 4, 2, 2] -> [2, 4, 2, 1] -> [2, 1, 4, 3]
 * [1, 4, 2, 0] -> [2, 4, 1, 0] -> [2, 1, 4, 3]
 *
 * 1. Find the first reverse number in the ascending array starting from the end
 * to the beginning
 * 2. Find the first smallest number greater than the reverse number
 * 3. Swap them
 * 4. reverse the right part of the array that is a descending array
 */
class Solution
{
public:
    void nextPermutation(std::vector<int> &nums)
    {
        // [ 3, 5, 0, 1, 4, 2] -> [3, 5, 0, 2, 1, 4]
        auto sz = nums.size();
        auto l = nums.end() - 2,
             r = nums.end() - 1;  // *l will be the first reverse number, and *r
                                  // the first smallest number greater than *l

        while (l >= nums.begin() &&
               *l >= *(l + 1)) {  // the first reverse number
            --l;
        }
        if (l >= nums.begin()) {
            while (r > l && *r <= *l) {
                --r;
            }  // now *r is the first smallest number greater than *l
            std::swap(*l, *r);
            r = nums.end() - 1;
        }

        // reverse nums[l+1..end]
        while (++l < r) {
            std::swap(*l, *r--);
        }
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3};
    nums = {3, 2, 1};
    nums = {2, 3, 1};
    Solution().nextPermutation(nums);
    return 0;
}

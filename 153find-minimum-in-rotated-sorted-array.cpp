#include <vector>

class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            if (nums[lo] < nums[hi]) {
                break;
            }
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[0]) {  // mid is in the right half
                hi = mid;  // no infinite loop because of floor rounding
            } else {
                lo = mid + 1;
            }
        }
        return nums[lo];
    }
};


int main()
{
    std::vector<int> nums{3, 4, 5, 1, 2};
    nums = {11, 13, 15, 17};
    nums = {2, 1};
    Solution().findMin(nums);
    return 0;
}

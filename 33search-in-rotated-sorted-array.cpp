#include <vector>


/*
 * if nums[i] < nums[0], then nums[i..end] is in the ascending order, or
 * nums[0..i) is in the ascending order
 */
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size(), mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > nums[lo]) {  // left part is ordered
                if (nums[lo] <= target &&
                    target < nums[mid]) {  // check if target in the left
                                           // ordered part
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (nums[mid] < target &&
                    target <= nums[hi - 1]) {  // check if target in the right
                                               // ordered part
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
        }

        return -1;
    }
};


class Solution2
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int sz = nums.size(), lo = 0, hi = sz;

        // find the kk that divide nums into two parts: nums[0, kk), nums[kk,
        // size)
        int kk = 0, mid = 0;
        while (lo < hi) {
            if (lo == hi - 1) {
                if (lo && nums[lo - 1] > nums[lo]) {
                    kk = lo;
                }
                break;
            }
            mid = lo + (hi - lo) / 2;
            if (nums[mid - 1] > nums[mid]) {
                kk = mid;
                break;
            } else if (nums[mid] < nums[0]) {  // k is in the left part
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // binary search
        lo = kk, hi = sz + kk;
        int mid1;
        while (lo < hi) {  // nums[kk..sz + kk)
            mid = lo + (hi - lo) / 2, mid1 = mid % sz;
            if (nums[mid1] == target) {
                return mid1;
            } else if (nums[mid1] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return -1;
    }
};


int main()
{
    std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution().search(nums, 0);

    // nums = {1, 3};
    // nums = {3, 1};
    // Solution().search(nums, 3);
    return 0;
}

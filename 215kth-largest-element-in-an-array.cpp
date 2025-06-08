#include <vector>


/*
 * quick select -> O(n)
 * quick sort / priority queue (heap sort) -> O(nlog(n))
 */
class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        int lo = 0, hi = nums.size();
        while (true) {
            // nums[<idx] <= nums[idx] < nums[>idx], i.e. nums[idx] is the (N -
            // idx)-th largest number
            int idx = partition(nums, lo, hi);
            if (idx < nums.size() - k) {
                lo = idx + 1;
            } else if (idx > nums.size() - k) {
                hi = idx;
            } else {
                return nums[idx];
            }
        }
        return 0;
    }

    int findKthLargest2(std::vector<int> &nums, int k)
    {
        return recur(nums, 0, nums.size(), nums.size() - k);
    }

    int recur(std::vector<int> &nums, int lo, int hi, int k)
    {
        int idx = partition(nums, lo, hi);
        if (idx < k) {
            return recur(nums, idx + 1, hi, k);
        } else if (idx > k) {
            return recur(nums, lo, idx, k);
        } else {
            return nums[idx];
        }
    }


private:
    // Sedgewich
    int partition(std::vector<int> &a, int lo, int hi)  // [lo, hi)
    {
        int i = lo, j = hi;
        int v = a[lo];
        while (true) {  // (lo, hi) because nums[lo] is the pivot
            while (++i != hi && a[i] < v) {}
            while (--j != lo && a[j] > v) {}
            if (i >= j) { break; }
            std::swap(a[i], a[j]);
        }
        std::swap(a[lo], a[j]);  // nums[>j] > pivot
        return j;  // nums[lo..j) <= pivot == nums[j] < nums(j, hi)
    }

    // timeout for the last case (large number of same nums), and random pivot
    // index is useless for it
    int partition2(std::vector<int> &nums, int lo, int hi)  // [lo, hi)
    {
        int pivot = nums[lo];
        int j = lo;
        for (int i = lo + 1; i != hi; ++i) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[++j]);  // nums(lo, j] < pivot
            }
        }
        std::swap(nums[lo], nums[j]);
        return j;
    }

    // timeout for the last case (large number of same nums), and random pivot
    // index is useless for it
    int partition3(std::vector<int> &nums, int lo, int hi)  // [lo, hi)
    {
        int pivot = nums[lo];
        std::swap(nums[lo], nums[hi - 1]);
        int j = lo;
        for (int i = lo; i != hi; ++i) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[j++]);  // nums[lo, j) < pivot
            }
        }
        std::swap(nums[hi - 1], nums[j]);  // nums(j, hi] >= pivot
        return j;
    }
};


int main()
{
    std::vector<int> nums{3, 2, 1, 5, 6, 4};
    Solution().findKthLargest(nums, 2);
    return 0;
}

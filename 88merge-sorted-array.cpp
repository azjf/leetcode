#include <iostream>
#include <vector>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        auto it = nums1.rbegin();
        --m, --n;
        while (n >= 0 && m >= 0) {
            *it++ = nums1[m] < nums2[n] ? nums2[n--] : nums1[m--];
        }
        while (n >= 0) {
            *it++ = nums2[n--];
        }
    }
};

int main()
{
    Solution s;

    std::vector<int> nums1 = {4, 5, 6, 0, 0, 0}, nums2 = {1, 2, 3};
    s.merge(nums1, 3, nums2, 3);
    return 0;
}

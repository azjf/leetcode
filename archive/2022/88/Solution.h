#pragma once

#include <vector>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        auto it = nums1.rbegin();
        --m, --n;
        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                *it++ = nums1[m--];
            } else {
                *it++ = nums2[n--];
            }
        }
        while (n >= 0) {
            *it++ = nums2[n--];
        }
    }
};

#include <vector>

using namespace std;


class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p = m + n;
        --m, --n;
        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[--p] = nums1[m--];
            } else {
                nums1[--p] = nums2[n--];
            }
        }
        while (n >= 0) nums1[--p] = nums2[n--];
    }
};

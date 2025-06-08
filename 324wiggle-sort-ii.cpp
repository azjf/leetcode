#include <algorithm>
#include <vector>


class Solution
{
public:
    void wiggleSort(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        auto tmp = nums;
        int j = 0;
        int sz = nums.size();
        // nums[0,2,4,...] = tmp[0..N/2)
        // nums[1,3,5,...] = tmp[N/2..N)
        for (int i = 0, j = (sz + 1) / 2 - 1, k = sz - 1; i < sz;
             i += 2, --j, --k) {
            // j -> [N/2, 0)
            // k -> [N, N/2)
            nums[i] = tmp[j];
            if (i + 1 < sz) { nums[i + 1] = tmp[k]; }
        }
    }
};

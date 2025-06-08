#include <vector>

using namespace std;


class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int l = 0, r = 1;
        while (r < nums.size()) {
            if (nums[r] != nums[l]) nums[++l] = nums[r];
            ++r;
        }
        return l + 1;
    }
};

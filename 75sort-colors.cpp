#include <vector>

/*
 * partition() of 3-way quick sort
 */
class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        // nums[0, lt) == 0, nums[lt, i) == 1, nums(gt, nums.size()) == 2
        int i = 0, lt = 0, gt = nums.size() - 1;
        while (i <= gt) {
            if (!nums[i]) {
                // if i > lt, then nums[lt] == 1 must hold
                std::swap(nums[i++], nums[lt++]);
            } else if (nums[i] == 1) {
                ++i;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[gt--]);
            }
        }
    }
};


class Solution2
{
public:
    void sortColors(std::vector<int> &nums)
    {
        int cnt[] = {0, 0, 0};
        for (int n : nums) {
            ++cnt[n];
        }
        for (int i = 0; i != nums.size(); ++i) {
            nums[i] = i < cnt[0] ? 0 : (i < cnt[0] + cnt[1] ? 1 : 2);
        }
    }
};


class Solution3
{
public:
    void sortColors(std::vector<int> &nums)
    {
        int r = 0, g = 0, b = 0;
        // finally, r = cnt0, g = cnt0 + cnt1, b = cnt0 + cnt1 + cnt2
        // a 'r' push the 'g' and 'b' backward, same for 'g'
        for (int i = 0; i != nums.size(); ++i) {
            if (!nums[i]) {
                nums[b++] = 2;
                nums[g++] = 1;
                nums[r++] = 0;
            } else if (nums[i] == 1) {
                nums[b++] = 2;
                nums[g++] = 1;
            } else {
                nums[b++] = 2;
            }
        }
    }
};


int main()
{
    std::vector<int> nums{2, 0, 2, 1, 1, 0};
    Solution().sortColors(nums);
    return 0;
}

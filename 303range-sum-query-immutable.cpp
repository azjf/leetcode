#include <vector>


class NumArray
{
public:
    NumArray(std::vector<int> &nums)
    {
        // prefix[i] -> nums[i - 1]
        prefix = std::vector<int>(nums.size() + 1, 0);
        prefix[0] = nums[0];
        for (int i = 0; i != nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return prefix[right + 1] - prefix[left];
    }

private:
    std::vector<int> prefix;
};

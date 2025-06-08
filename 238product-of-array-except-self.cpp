#include <vector>


class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> res(nums.size());
        for (int i = 0, pre = 1; i != nums.size(); ++i) {
            res[i] = pre;  // res[i] -> prod[0, i)
            pre *= nums[i];
        }
        for (int i = nums.size() - 1, post = 1; i != -1; --i) {
            res[i] *= post;
            post *= nums[i];
        }
        return res;
    }
};


class Solution2
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> pre(nums.size());
        pre[0] = 1;
        for (int i = 1; i != nums.size(); ++i) {
            pre[i] = pre[i - 1] * nums[i - 1];  // res[i] -> prod[0, i)
        }
        std::vector<int> post(nums.size());
        post[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i != -1; --i) {
            post[i] = post[i + 1] * nums[i + 1];
        }

        for (int i = 0; i != nums.size(); ++i) { pre[i] *= post[i]; }
        return pre;
    }
};

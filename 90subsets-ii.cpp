#include <algorithm>
#include <vector>

/*
 * f(idx) = f(idx+1) + {n, f(idx+1)}
 */
class Solution
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        return recur(nums, 0);
    }

private:
    std::vector<std::vector<int>> recur(std::vector<int> &nums, int lo)
    {
        if (lo == nums.size()) {
            return {{}};
        }

        int hi = lo + 1;
        for (; hi != nums.size() && nums[hi] == nums[lo]; ++hi)
            ;
        std::vector<std::vector<int>> res = recur(nums, hi);

        int sz = res.size();
        for (int i = 0; i != sz; ++i) {
            for (int j = 0; j != hi - lo; ++j) {
                res.push_back(res[i]);
                auto &back = res.back();
                back.insert(back.end(), j + 1, nums[lo]);
            }
        }
        return res;
    }
};


class Solution2
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        recur(nums, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> ivec;
    void recur(std::vector<int> &nums, int lo)
    {
        if (lo == nums.size()) {
            res.push_back(ivec);
            return;
        }

        int hi = lo + 1;
        for (; hi != nums.size() && nums[hi] == nums[lo]; ++hi)
            ;
        for (int i = lo; i != hi + 1; ++i) {
            // when i == lo, nothing is inserted into ivec, which equals to not
            // using nums[idx]
            ivec.insert(ivec.end(), nums.cbegin() + lo, nums.cbegin() + i);
            recur(nums, hi);
            ivec.erase(ivec.end() - (i - lo), ivec.end());
        }
    }
};


class Solution3
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        recur(nums, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> ivec;
    void recur(std::vector<int> &nums, int lo)
    {
        res.push_back(ivec);
        for (int i = lo; i != nums.size(); ++i) {
            if (i != lo && nums[i] == nums[i - 1]) {
                // nums[i] == nums[i - 1] causes duplication
                continue;
            }
            ivec.push_back(nums[i]);
            recur(nums, i + 1);
            ivec.pop_back();
        }
    }
};

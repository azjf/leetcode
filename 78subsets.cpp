#include <iterator>
#include <vector>

/*
 * f(n) = f(n-1) + {n, f(n-1)}
 */
class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        return recur(nums, 0);
    }

private:
    std::vector<std::vector<int>> recur(std::vector<int> &nums, int idx)
    {
        if (idx == nums.size()) {
            return {{}};
        }
        std::vector<std::vector<int>> res = recur(nums, idx + 1);
        int sz = res.size();
        for (int i = 0; i != sz; ++i) {
            res.push_back(res[i]);  // reference to res[i] may be invalid
                                    // because of possible memory reallocation
            res.back().push_back(nums[idx]);
        }
        return res;
    }
};


/*
 * for each nums[i], it may be selected or not
 */
class Solution2
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        recur(nums, 0);
        return res;
    }

private:
    std::vector<int> ivec;
    std::vector<std::vector<int>> res;
    void recur(std::vector<int> &nums, int idx)
    {
        if (idx == nums.size()) {
            res.push_back(ivec);
            return;
        }
        recur(nums, idx + 1);       // do not use nums[i]
        ivec.push_back(nums[idx]);  // use nums[i]
        recur(nums, idx + 1);
        ivec.pop_back();
    }
};


class Solution3
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        recur(nums, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> ivec;
    void recur(std::vector<int> &nums, int lo)
    {
        res.push_back(ivec);
        // now that ivec is a valid set, so nums[>=lo] is appended to create
        // a new valid set. use nums[>=lo] to avoid repeatance
        for (int i = lo; i != nums.size(); ++i) {
            ivec.push_back(nums[i]);
            recur(nums, i + 1);
            ivec.pop_back();
        }
    }
};


int main()
{
    std::vector<int> nums{0};
    nums = {1, 2};
    // nums = {1, 2, 3};
    Solution().subsets(nums);
    return 0;
}

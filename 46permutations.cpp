#include <iostream>
#include <list>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        visited = std::vector<bool>(nums.size(), false);
        recur(nums, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> ivec;
    std::vector<bool> visited;  // equivalent to std::set

    void recur(std::vector<int> &nums, int size)
    {
        if (size == nums.size()) {
            res.push_back(ivec);
            return;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            ivec.push_back(nums[i]);
            visited[i] = true;
            recur(nums, size + 1);
            ivec.pop_back();
            visited[i] = false;
        }
    }
};


class Solution2
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        recur(nums, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::list<int> ilist;

    /*
     * insert nums[lo] to ilist[i], and now nums[lo] has already been handled
     */
    void recur(std::vector<int> &nums, int lo)
    {
        if (lo == nums.size()) {
            res.push_back(std::vector<int>(ilist.cbegin(), ilist.cend()));
            return;
        }
        auto it = ilist.cbegin();
        while (true) {
            ilist.insert(it, nums[lo]);  // ilist[it - 1] = nums[lo]
            recur(nums, lo + 1);
            it = ilist.erase(--it);
            if (it != ilist.cend()) {
                ++it;
            } else {
                break;
            }
        }
    }
};


class Solution3
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        recur(nums, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;

    void recur(std::vector<int> &nums, int lo)
    {
        if (lo == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = lo; i != nums.size(); ++i) {
            std::swap(nums[lo], nums[i]);  // select nums[i] as nums[lo]. now
                                           // nums[0..lo] have been determined
            recur(nums, lo + 1);
            std::swap(nums[lo], nums[i]);
        }
    }
};


int main()
{
    std::list<int> ilist;
    auto it = ilist.cbegin();
    ilist.insert(it, 0);
    ilist.insert(it, 1);
    auto tmp = it;
    --tmp;
    ilist.erase(tmp);
    std::cout << *tmp << " " << (tmp == it) << std::endl;
    // ilist.insert(tmp, 2);  // error because tmp is now invalid
    ilist.insert(it, 2);
    it = ilist.cbegin();
    auto next =
        ilist.erase(it);  // now it -> 0, ilist.erase(it) again causes error
    ilist.erase(next);

    std::vector<int> nums{1, 2};
    Solution2().permute(nums);
    return 0;
}

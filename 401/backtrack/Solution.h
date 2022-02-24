#pragma once

#include <vector>
#include <array>
#include <string>

class Solution
{
public:
    std::vector<std::vector<int>> permut(const std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans;
        if (nums.empty()) {
            return ans;
        }

        auto sz = nums.size();
        std::vector<bool> used(sz, 0);
        std::vector<int> path;
        dfs(nums, sz, 0, path, used, ans);
        return ans;
    }

private:
    void dfs(const std::vector<int> &nums, int len, int depth,
            std::vector<int> &path, std::vector<bool> &used,
            std::vector<std::vector<int>> &ans)
    {
        if (depth == len) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i != len; ++i) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                dfs(nums, len, depth + 1, path, used, ans);
                used[i] = false;
                path.erase(path.end() - 1);
            }
        }
    }
};

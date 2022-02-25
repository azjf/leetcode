#pragma once

#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> shiftGrid(
            std::vector<std::vector<int>> &grid, int k)
    {
        auto m = grid.size(), n = grid[0].size(), len = m * n;
        k %= len;
        revert(grid, 0, len - k - 1);
        revert(grid, len - k, len - 1);
        revert(grid, 0, len - 1);
        std::vector<std::vector<int>> ret(grid.cbegin(), grid.cend());
        return ret;
    }

private:
    void revert(std::vector<std::vector<int>> &grid, int beg, int end)
    {
        int n = grid[0].size();
        while (beg < end) {
            int i1 = beg / n, j1 = beg % n;
            int i2 = end / n, j2 = end % n;
            int tmp = grid[i1][j1];
            grid[i1][j1] = grid[i2][j2];
            grid[i2][j2] = tmp;
            ++beg;
            --end;
        }
    }
};

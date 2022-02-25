#pragma once

#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> shiftGrid(
            std::vector<std::vector<int>> &grid, int k)
    {
        auto m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> ret(m, std::vector<int>(n, 0));
        for (decltype(m) i = 0; i != m; ++i) {
            for (decltype(n) j = 0; j != n; ++j) {
                int idx = (i * n + j + k) % (m * n);
                ret[idx / n][idx % n] = grid[i][j];
            }
        }
        return ret;
    }
};

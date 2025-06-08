#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid,
                                            int k)
    {
        auto m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
        for (auto i = 0; i != m; ++i) {
            for (auto j = 0; j != n; ++j) {
                auto idx = (i * n + j + k) % (m * n);
                res[idx / n][idx % n] = grid[i][j];
            }
        }
        return res;
    }
};

// https://juejin.cn/post/6844903764940308488
class Solution2
{
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid,
                                            int k)
    {
        auto m = grid.size(), n = grid[0].size(), sz = m * n;
        k %= sz;
        // [0, N - k), [N - k, N), [0, N)
        flip(grid, 0, sz - k - 1);   // x + f1(x) = 0 + (N-1-k)
        flip(grid, sz - k, sz - 1);  // x + f2(x) = (N-1) + (N-k)
        flip(grid, 0,
             sz - 1);  // x + f3(x) = 0 + (N-1) -> f31(x) = (N-1) - f1(x) = x +
                       // k, f32(x) = (N-1) - f2(x) = x + N-k
        return grid;
    }

private:
    void flip(std::vector<std::vector<int>> &grid, int beg, int end)
    {
        auto n = grid[0].size();
        while (beg < end) {
            int i1 = beg / n, j1 = beg % n;
            int i2 = end / n, j2 = end % n;
            std::swap(grid[i1][j1], grid[i2][j2]);
            ++beg, --end;
        }
    }
};

#include <vector>

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    mark(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    void mark(std::vector<std::vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '0';
        std::pair<int, int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto &dir : dirs) {
            mark(grid, i + dir.first, j + dir.second);
        }
    }
};


int main()
{
    std::vector<std::vector<char>> grid{{'1', '1'}};
    grid = {{'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};
    Solution().numIslands(grid);
    return 0;
}

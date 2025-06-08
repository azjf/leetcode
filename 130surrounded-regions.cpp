#include <vector>

/*
 * all 'O' not connected to 'O' at boards should be changed to 'X'
 */
class Solution
{
public:
    void solve(std::vector<std::vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i != m; ++i) {
            if (board[i][0] == 'O') {
                recur(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                recur(board, i, n - 1);
            }
        }
        for (int j = 1; j < n - 1; ++j) {
            if (board[0][j] == 'O') {
                recur(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                recur(board, m - 1, j);
            }
        }
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }

private:
    void recur(std::vector<std::vector<char>> &board, int x, int y)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
            board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        std::pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto &dir : dirs) {
            recur(board, x + dir.first, y + dir.second);
        }
    }
};

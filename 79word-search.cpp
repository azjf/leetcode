#include <string>
#include <vector>


/*
 * f(idx) = (board[i+-1, j+-1] == word[idx]) && f(idx + 1)
 */
class Solution
{
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (board[i][j] == word[0] && recur(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool recur(std::vector<std::vector<char>> &board, std::string &word,
               int idx, int i, int j)
    {
        if (idx == word.size()) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[idx]) {
            return false;
        }

        board[i][j] = 0;
        bool res = recur(board, word, idx + 1, i - 1, j) ||
                   recur(board, word, idx + 1, i + 1, j) ||
                   recur(board, word, idx + 1, i, j + 1) ||
                   recur(board, word, idx + 1, i, j - 1);
        board[i][j] = word[idx];
        return res;
    }
};

int main()
{
    std::vector<std::vector<char>> board{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution().exist(board, "ABCCED");
    return 0;
}

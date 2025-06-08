#include <vector>

/*
 * row_i -> col_{n - 1 - i}
 * matrix[i, j] -> matrix[j, n - 1 - i]
 * matrix[i, j] ->(flip by row) matrix[n - 1 - i, j] ->(flip by diagonal)
 *   matrix[j, n - 1 - i]
 * matrix[i, j] ->(flip by anti-diagonal) matrix[n - 1 - j, n - 1 - i]
 *   ->(flip by row) matrix[j, n - 1 - i]
 *
 * 1 2 -> 3 1
 * 3 4    4 2
 */
class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        // flip by row
        for (int lo = 0, hi = matrix.size() - 1; lo < hi; ++lo, --hi) {
            std::swap(matrix[lo], matrix[hi]);
        }
        // flip by diagonal
        for (int i = 0; i != matrix.size(); ++i) {
            for (int j = 0; j != i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};


/*
 * matrix[i, j] -> matrix[j, n - 1 - i] -> matrix[n - 1 - i, n - 1 - j] ->
 * matrix[n - 1 - j, i] -> matrix[i, j]
 *
 * matrix[i, j] <- matrix[n - 1 - j, i]
 */
class Solution2
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int N = matrix.size();
        // iterate by the up triangle that consist 1/4 of the rectangle
        for (int i = 0; i != N / 2; ++i) {
            for (int j = i; j != N - 1 - i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - j][i];
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
                matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
                matrix[j][N - 1 - i] = tmp;
            }
        }
    }
};

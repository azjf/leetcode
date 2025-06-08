#include <vector>


/*
 * 1. use bool[m + n] flags to save the info that if the result row/col should
 * be all zeros
 * 2. use the first row/col as the bool[m + n] flags
 */
class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool hasZeroFirstRow = false, hasZeroFirstCol = false;
        for (int j = 0; j != n; ++j) {
            if (!matrix[0][j]) {
                hasZeroFirstRow = true;
                break;
            }
        }
        for (int i = 0; i != m; ++i) {
            if (!matrix[i][0]) {
                hasZeroFirstCol = true;
                break;
            }
        }

        // traverse the matrix to find if the i-th row and the j-th col should
        // be all zeroes
        for (int i = 1; i != m; ++i) {
            for (int j = 1; j != n; ++j) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int j = 1; j != n; ++j) {
            if (!matrix[0][j]) {
                for (int i = 1; i != m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i != m; ++i) {
            if (!matrix[i][0]) {
                for (int j = 1; j != n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (hasZeroFirstRow) {
            for (int j = 0; j != n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (hasZeroFirstCol) {
            for (int i = 0; i != m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};


int main()
{
    std::vector<std::vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution().setZeroes(matrix);
    return 0;
}

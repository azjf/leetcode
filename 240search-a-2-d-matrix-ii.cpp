#include <algorithm>
#include <vector>


/*
 * O(m + n)
 *
 * search from [m -1 , 0] or [0, n - 1], so that there will be only one
 * direction to go for each comparsion.
 * for each move, one row or column will be discarded.
 *
 * binary search is inefficient, because for each compare, only one rectangle
 * block of 3 can be discarded, while the rest two of them need are of nearly
 * the same difficulty as the whole rectangle to tangle
 */
class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int i = matrix.size() - 1, j = 0;
        while (i != -1 && j != matrix[0].size()) {
            if (matrix[i][j] < target) {
                ++j;
            } else if (matrix[i][j] > target) {
                --i;
            } else {
                return true;
            }
        }
        return false;
    }
};


int main()
{
    std::vector<std::vector<int>> matrix{{-1, 3}};
    Solution().searchMatrix(matrix, 1);
    return 0;
}

#include <vector>

class Solution
{
public:
    int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes)
    {
        std::vector<int> count(81, 0);
        int res = 0, key = 0;
        for (const auto &d : dominoes) {
            // key = d[0] < d[1] ? d[0] << 4 | d[1] : d[1] << 4 | d[0];  // 1 <=
            // d[i][j] <= 9
            key = d[0] < d[1] ? (d[0] - 1) * 9 + d[1] - 1
                              : (d[1] - 1) * 9 + d[0] - 1;  // 9-base counting
            res += count[key];  // Sum of the arithmetic sequence
            ++count[key];
        }
        return res;
    }
};

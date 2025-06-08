#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> merge(
        std::vector<std::vector<int>> &intervals)
    {
        std::sort(
            intervals.begin(), intervals.end(),
            [](const auto &lhs, const auto &rhs) { return lhs[0] < rhs[0]; });

        std::vector<std::vector<int>> res;
        std::vector<int> &pre = intervals[0];
        for (int i = 1; i != intervals.size(); ++i) {
            if (intervals[i][0] > pre[1]) {
                res.push_back(pre);
                pre = intervals[i];
            } else if (intervals[i][1] > pre[1]) {
                pre[1] = intervals[i][1];
            }
        }
        res.push_back(pre);
        return res;
    }
};


int main()
{
    std::vector<std::vector<int>> intervals{{1, 4}, {4, 5}};
    Solution().merge(intervals);
    return 0;
}

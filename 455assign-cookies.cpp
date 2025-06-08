#include <algorithm>
#include <vector>

class Solution
{
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int res = 0;
        auto itg = g.cbegin(), its = s.cbegin();
        while (itg != g.cend() && its != s.cend()) {
            if (*itg <= *its) {
                ++res;
                ++itg;
            }
            ++its;
        }
        return res;
    }
};

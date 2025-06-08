#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                  int target)
    {
        std::sort(candidates.begin(), candidates.end());
        recur(candidates, target, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> ivec;

    void recur(std::vector<int> &candidates, int target, int lo)
    {
        if (!target) {
            res.push_back(ivec);
        }
        for (int i = lo; i != candidates.size() && candidates[i] <= target;
             ++i) {
            /*if (i != lo && candidates[i] == candidates[i - 1]) {
                // only candidates[lo] will be selected (candidates[lo + 1]
                // will be selected in the next round), while candidates[i] ==
                // candidates[lo] while not be selected in this round, so there
                // will be no duplication
                continue;
            }*/
            ivec.push_back(candidates[i]);
            recur(candidates, target - candidates[i], i + 1);
            while (i + 1 < candidates.size() &&
                   candidates[i + 1] == candidates[i]) {
                // candidates[i + 1] has already been handled in the recur()
                // above
                ++i;
            }
            ivec.pop_back();
        }
    }
};

#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
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
        if (!target) {  // 2 <= candidates[i] <= 40, so \sum{candidates[i]} > 0.
                        // As a result, there is no need to recur furtherly to
                        // get elements that sum to 0, which will also cause
                        // infinite loops
            res.push_back(ivec);
        }
        for (int i = lo; i != candidates.size() && candidates[i] <= target;
             ++i) {
            ivec.push_back(candidates[i]);
            recur(candidates, target - candidates[i], i);
            ivec.pop_back();
        }
    }
};


int main()
{
    std::vector<int> candidates{2, 3, 6, 7};
    Solution().combinationSum(candidates, 7);
    return 0;
}

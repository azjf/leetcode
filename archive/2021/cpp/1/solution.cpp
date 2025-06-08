#include <unordered_map>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i], y = target - nums[i];
            if (map.count(y)) return {i, map[y]};
            map[x] = i;
        }
        return {};
    }
};

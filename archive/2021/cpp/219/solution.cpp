#include <unordered_map>
#include <vector>

using namespace std;


class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(nums[i]) && map[nums[i]] >= i - k) return true;
            map[nums[i]] = i;
        }
        return false;
    }
};

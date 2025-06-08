#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        if (numbers.empty()) return {-1, -1};

        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target) {
                --r;
            } else if (sum < target) {
                ++l;
            } else {
                return {l + 1, r + 1};
            }
        }
        return {-1, -1};
    }
};

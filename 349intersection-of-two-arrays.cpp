#include <set>
#include <vector>

class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1,
                                  std::vector<int> &nums2)
    {
        std::set<int> s(nums1.cbegin(), nums1.cend());
        std::vector<int> res;
        for (auto n : nums2) {
            if (s.count(n)) {
                res.push_back(n);
                s.erase(n);
            }
        }
        return res;
    }
};

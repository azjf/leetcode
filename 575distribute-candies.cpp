#include <set>
#include <vector>

class Solution
{
public:
    int distributeCandies(std::vector<int> &candyType)
    {
        std::set<int> s;
        for (auto c : candyType) {
            s.insert(c);
        }
        return std::min(s.size(), candyType.size() / 2);
    }
};

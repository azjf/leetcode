#include <map>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::map<int, int> m;
        int res = 0;
        for (int l = 0, r = 0; r != s.size(); ++r) {
            char c = s[r];
            if (m.count(c) &&
                m[c] >=
                    l) {  // m[c] may be less than l when s[<=l] contains 'c'
                l = m[c] + 1;
            }
            m[c] = r;
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};

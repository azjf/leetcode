#include <map>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string> &strs)
    {
        std::vector<std::vector<std::string>> res;
        std::map<std::vector<short>, int> m;
        std::vector<short> key(26, 0);
        for (const auto &s : strs) {
            std::fill(key.begin(), key.end(), 0);
            for (char c : s) {
                ++key[c - 'a'];
            }
            // key = sort(s);

            if (!m.count(key)) {
                m[key] = res.size();
                res.push_back({});
            }
            res[m[key]].push_back(s);
        }
        return res;
    }
};


int main()
{
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution().groupAnagrams(strs);
    return 0;
}

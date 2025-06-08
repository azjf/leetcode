#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> shortestToChar(std::string s, char c)
    {
        auto sz = s.size();
        std::vector<int> res(sz, 0);
        std::vector<int> pos;
        for (auto i = 0; i != sz; ++i) {
            if (s[i] == c) {
                pos.push_back(i);
            }
        }
        for (auto i = 0; i != sz; ++i) {
            int min = sz;
            for (auto p : pos) {
                min = std::min(min, std::abs(i - p));
            }
            res[i] = min;
        }
        return res;
    }
};

class Solution2
{
public:
    std::vector<int> shortestToChar(std::string s, char c)
    {
        auto sz = s.size();
        std::vector<int> res(sz, 0);
        int l = -sz;
        for (auto i = 0; i != sz; ++i) {
            if (s[i] == c) {
                l = i;
            }
            res[i] = i - l;
        }
        int r = sz * 2;
        for (int i = sz - 1; i != -1; --i) {
            if (s[i] == c) {
                r = i;
            }
            res[i] = std::min(res[i], r - i);
        }
        return res;
    }
};

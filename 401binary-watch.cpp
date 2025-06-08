#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> readBinaryWatch(int turnedOn)
    {
        std::vector<std::string> res;
        for (int h = 0; h != 12; ++h) {
            for (int m = 0; m != 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    res.push_back(std::to_string(h) + ':' +
                                  (m < 10 ? "0" : "") + std::to_string(m));
                }
            }
        }
        return res;
    }
};

class Solution2
{
public:
    std::vector<std::string> readBinaryWatch(int turnedOn)
    {
        std::vector<std::string> res;
        backtrack(res, 0, -1, turnedOn);
        return res;
    }

private:
    /*
     * r(k) = r(k - 1) | (1 << idx), idx[k - 1] < idx < 10 - (unused - 1)
     */
    void backtrack(std::vector<std::string> &ans, int state, int idx,
                   int unused)
    {
        if (!unused) {
            int h = state >> 6;
            int m = state & 63;
            if (h < 12 && m < 60) {
                ans.push_back(std::to_string(h) + ':' + (m < 10 ? "0" : "") +
                              std::to_string(m));
            }
        }
        for (int i = idx + 1; i != 10 - (unused - 1) && unused; ++i) {
            backtrack(ans, state | (1 << i), i, unused - 1);
        }
    }
};

int main()
{
    auto res = Solution().readBinaryWatch(4);
    for (const auto &s : res) {
        std::cout << s << std::endl;
    }

    res = Solution2().readBinaryWatch(4);
    for (const auto &s : res) {
        std::cout << s << std::endl;
    }
    return 0;
}

#include <string>
#include <vector>

/*
 * f(idx) = \sum{{sParlindrome[idx, i) + f(i)}}
 */
class Solution
{
public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        recur(s, 0);
        return res;
    }

private:
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> slist;

    void recur(const std::string &s, int lo)
    {
        if (lo >= s.size()) {
            res.push_back(slist);
            return;
        }
        for (int i = lo + 1; i != s.size() + 1; ++i) {
            if (isParlindrome(s, lo, i)) {
                slist.push_back(s.substr(lo, i - lo));
                recur(s, i);
                slist.pop_back();
            }
        }
    }

    bool isParlindrome(const std::string &s, int lo, int hi)
    {
        while (lo < hi && s[lo] == s[hi - 1]) {
            ++lo;
            --hi;
        }
        return lo >= hi;
    }
};


int main()
{
    Solution().partition("aab");
    return 0;
}

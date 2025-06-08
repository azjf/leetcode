#include <map>
#include <set>
#include <string>
#include <vector>


/*
 * dp[i] = \sum{dp[i - word.size()] && word == s(i - word.size(), i]}
 */
class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::vector<bool> dp(s.size() + 1, false);  // s[i] -> dp[i + 1]
        dp[0] = true;
        for (int i = 1; i != dp.size(); ++i) {
            for (const auto &word : wordDict) {
                dp[i] = i >= word.size() &&
                        (dp[i - word.size()] &&
                         word == s.substr(i - word.size(), word.size()));
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


/*
 * dp[i] = \sum{dp[j] && wordDict.contains(s(j, i])}
 */
class Solution2
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::set<std::string> sset(wordDict.cbegin(), wordDict.cend());
        std::vector<bool> dp(s.size() + 1, false);  // s[i] -> dp[i + 1]
        dp[0] = true;
        for (int i = 1; i != dp.size(); ++i) {
            for (int j = 0; j != i; ++j) {
                dp[i] = dp[j] && sset.count(s.substr(j, i - j));
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};


/*
 * f(idx) = \sum{f(i + word.size()) && word == s[i, i + word.size())}
 */
class Solution3
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        this->wordDict.insert(wordDict.cbegin(), wordDict.cend());
        return recur(s, 0);
    }

private:
    std::set<std::string> wordDict;
    std::map<int, bool> imap;

    bool recur(const std::string &s, int lo)
    {
        if (lo >= s.size()) {
            return true;
        }
        for (const auto &word : wordDict) {
            if (lo + word.size() > s.size() ||
                s.substr(lo, word.size()) != word) {
                continue;
            }
            int newLo = lo + word.size();
            if (!imap.count(newLo)) {
                imap[newLo] = recur(s, newLo);
            }
            if (imap[newLo]) {
                return true;
            }
        }
        return false;
    }
};


/*
 * f(idx) = \sum{wordDict.contains(s[idx, i)) && f(i)}
 */
class Solution4
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        this->wordDict.insert(wordDict.cbegin(), wordDict.cend());
        return recur(s, 0);
    }

private:
    std::set<std::string> wordDict;
    std::map<int, bool> imap;

    bool recur(const std::string &s, int lo)
    {
        if (lo >= s.size()) {
            return true;
        }
        for (int i = lo + 1; i != s.size() + 1; ++i) {
            if (wordDict.count(s.substr(lo, i - lo))) {
                if (!imap.count(i)) {
                    imap[i] = recur(s, i);
                }
                if (imap[i]) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main()
{
    std::vector<std::string> wordDict{"leet", "code"};
    Solution().wordBreak("leetcode", wordDict);
    return 0;
}

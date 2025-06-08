#include <set>
#include <string>
#include <vector>

/*
 * Cartesian product: 17 letter-combinations-of-a-phone-number
 * f(n) = [f(n - 1) + "()"] + ["()" + f(n - 1)] + ['(' + f(n - 1) + ')']
 */
class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        auto res = recur(n);
        return std::vector<std::string>(res.cbegin(), res.cend());
    }

private:
    std::set<std::string> recur(int n)
    {
        if (n == 1) {
            return {"()"};
        }
        std::set<std::string> res;
        for (const auto &s : recur(n - 1)) {
            res.insert(s + "()");
            res.insert("()" + s);
            res.insert('(' + s + ')');
        }
        return res;
    }
};

class Solution2
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::string s;
        recur(n, 0, 0, s);
        return svec;
    }

private:
    std::vector<std::string> svec;
    void recur(int n, int l, int r, std::string &s)
    {
        if (l > n || r > n) {  // l of '('s has already been pushed
            return;
        }
        if (l == r && r == n) {
            svec.push_back(s);
            return;
        }
        if (l < r) {
            return;
        }

        s.push_back('(');  // '(' + s has already been constructed because '('
                           // is the first char been pushed
        recur(n, l + 1, r, s);
        s.pop_back();

        s.push_back(')');  // ')' + s is invalid
        recur(n, l, r + 1, s);
        s.pop_back();
    }
};

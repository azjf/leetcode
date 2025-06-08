#include <algorithm>
#include <string>
#include <vector>

/*
 * the first char is nums[k / (n - 1)!], and so on
 */
class Solution
{
public:
    std::string getPermutation(int n, int k)
    {
        std::vector<char> nums(
            n, 0);  // n <= 9, so the performance loss of erasing nums[i] will
                    // is acceptable compared to that of std::list
        for (int i = 0; i != n; ++i) {
            nums[i] = '1' + i;
        }

        int fact = 1;
        for (int i = 2; i < n; ++i) {
            fact *= i;
        }  // fact == (n - 1)!

        --k;
        std::string res(n, 0);
        int idx = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (k == 0) {
                std::for_each(nums.cbegin(), nums.cend(),
                              [&res, &idx](auto c) { res[idx++] = c; });
                break;
            }

            int j = k / fact;
            res[idx++] = nums[j];
            nums.erase(std::next(nums.begin(), j));

            k %= fact;
            fact /= i;
        }
        return res;
    }
};

int main()
{
    // Solution().getPermutation(3, 3);
    Solution().getPermutation(4, 9);
    return 0;
}

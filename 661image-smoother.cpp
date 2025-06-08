#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> imageSmoother(
        std::vector<std::vector<int>> &img)
    {
        auto m = img.size(), n = img[0].size();
        std::vector<std::vector<int>> res(m, std::vector<int>(n));
        int cnt = 0, sum = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                cnt = 0, sum = 0;
                for (int x = i - 1; x <= i + 1; ++x) {
                    if (x < 0 || x >= m) {
                        continue;
                    }
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (y < 0 || y >= n) {
                            continue;
                        }
                        ++cnt;
                        sum += img[x][y];
                    }
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};

/*
 * prefix sum
 */
class Solution2
{
public:
    std::vector<std::vector<int>> imageSmoother(
        std::vector<std::vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();
        std::vector<std::vector<int>> prefix(
            m + 1,
            std::vector<int>(n + 1, 0));  // preifx[i][j] -> img[i - 1][j - 1]
        for (int i = 1; i != m + 1; ++i) {
            for (int j = 1; j != n + 1; ++j) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                               prefix[i - 1][j - 1] + img[i - 1][j - 1];
            }
        }
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0, cnt = 0, sum = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                x1 = std::max(i - 1, 0), y1 = std::max(j - 1, 0),
                x2 = std::min(i + 1, m - 1), y2 = std::min(j + 1, n - 1);
                cnt = (x2 - x1 + 1) * (y2 - y1 + 1);
                sum = prefix[x2 + 1][y2 + 1] + prefix[x1][y1] -
                      prefix[x1][y2 + 1] - prefix[x2 + 1][y1];
                img[i][j] = sum / cnt;
            }
        }
        return img;
    }
};

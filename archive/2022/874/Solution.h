#pragma once

#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    int robotSim(std::vector<int> &commands,
                 std::vector<std::vector<int>> &obstacles)
    {
        auto pair2str = [](int x, int y) {
            return std::to_string(x) + ' ' + std::to_string(y);
        };
        std::unordered_set<std::string> vset;
        // std::set<std::vector<int>> vset;
        for (const auto &o : obstacles) {
            vset.insert(pair2str(o[0], o[1]));
        }

        int dx[]{0, 1, 0, -1}, dy[]{1, 0, -1, 0};
        int x = 0, y = 0, di = 0, max_dist = 0;
        for (const auto &c : commands) {
            if (c == -2 || c == -1) {
                di = (di + (c == -1 ? 1 : 4 - 1)) % 4;
            } else {
                for (int i = 0; i != c; ++i) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (vset.count(pair2str(nx, ny))) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    max_dist = std::max(max_dist, x * x + y * y);
                }
            }
        }
        return max_dist;
    }
};

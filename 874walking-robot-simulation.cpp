#include <set>
#include <vector>

class Solution
{
public:
    int robotSim(std::vector<int> &commands,
                 std::vector<std::vector<int>> &obstacles)
    {
        auto pair2int = [](unsigned short x, unsigned short y) -> unsigned {
            return ((long) x) << 16 | y;
        };  // -3 * 10^4 <= x, y <= 3 * 10^4 < 2^16 = 65536
        std::set<unsigned> oset;
        for (const auto &o : obstacles) {
            oset.insert(pair2int(o[0], o[1]));
        }

        int x = 0, y = 0, maxDist = 0;
        int dx[]{0, 1, 0, -1},
            dy[]{1, 0, -1,
                 0};  // start in the North direction, rotating clockwise
        int dir = 0;
        for (auto c : commands) {
            if (c == -1 || c == -2) {
                dir = (dir + (c == -1 ? 1 : 4 - 1)) % 4;
            } else {
                for (int i = 0; i != c; ++i) {
                    x += dx[dir];
                    y += dy[dir];
                    if (oset.count(pair2int(x, y))) {
                        x -= dx[dir];
                        y -= dy[dir];
                        break;
                    }
                    maxDist = std::max(maxDist, x * x + y * y);
                }
            }
        }
        return maxDist;
    }
};

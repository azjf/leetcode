#pragma once

#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> readBinaryWatch(int turnedOn)
    {
        std::vector<std::string> ans;
        dfs(ans, turnedOn, 0, 0);
        return ans;
    }

private:
    void dfs(std::vector<std::string> &ans, int unused, int idx, int state)
    {
        if (!unused) {
            std::string s = convert(state);
            if (!s.empty()) {
                ans.push_back(s);
            }
            return;
        }
        if (10 - idx < unused) {
            return;
        }
        dfs(ans, unused, idx + 1, state);
        dfs(ans, unused - 1, idx + 1, state | (1 << idx));
    }

    std::string convert(int state)
    {
        int hour = state >> 6;
        int minute = state & 0b111111;
        if (hour > 11 || minute > 59) {
            return "";
        }
        return std::to_string(hour) + ":" + (minute < 10 ? "0" : "")
            + std::to_string(minute);
    }
};

#include <vector>

using namespace std;


class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int carry = 1;
            for (int i = digits.size() - 1; i >= 0 && carry; --i) {
                carry += digits[i];
                digits[i] = carry % 10;
                carry = carry / 10;
            }
            if (carry) digits.insert(begin(digits), carry);
            return digits;
        }
};

/*
 * if >=2 numbers are diffrent, the last bit of the bitwise 'and' of them must
 * be 0
 */
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int cnt = 0;
        while (left != right) {
            ++cnt;
            left >>= 1;
            right >>= 1;
        }
        return left << cnt;
    }
};

class Solution
{
public:
    int hammingWeight(int n)
    {
        int res = 0;
        while (n) {
            ++res;
            // erase the last 1-bit. XXX(1000) & XXX(1000 - 1) = XXX0(000)
            n &= n - 1;
        }
        return res;
    }
};


class Solution2
{
public:
    int hammingWeight(int n)
    {
        int res = 0;
        while (n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

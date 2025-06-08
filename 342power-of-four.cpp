class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        while (n && !(n & 3)) {
            n >>= 2;
        }
        return n == 1;
    }
};

class Solution2
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};

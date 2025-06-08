class Solution
{
public:
    int getSum(int a, int b)
    {
        if (!b) {
            return a;
        }
        unsigned carry;
        while (a) {
            carry = (a & b) << 1;
            b ^= a;  // adder without carry (digital circuit)
            a = carry;
        }
        return b;
    }
};

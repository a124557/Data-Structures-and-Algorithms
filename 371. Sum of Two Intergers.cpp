class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            // Holding the carry value
            int carry = a & b;
            // Bitwise addition without carry
            a = a ^ b;
            /* Shift carry value to left by 1 digit so we can add it to a in the 
            next iteration */
            b = (unsigned int)carry << 1;
        }
        return a;
    }
};
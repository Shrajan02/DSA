// Bit Manipulation approach
// TC: O(1)
// SC: O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 0) return false;

        // check power of 2 & whether the MSB is set at even bit position
        int mask = n - 1;
        return ((n & mask) == 0) && (mask % 3 == 0);
    }
};
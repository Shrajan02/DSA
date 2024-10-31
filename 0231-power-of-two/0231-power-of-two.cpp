class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        return (1LL * n & (1LL * n -1)) ? false: true;
    }
};
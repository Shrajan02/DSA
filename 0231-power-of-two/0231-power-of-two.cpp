class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (1LL * n & (1LL * n - 1)) == 0;
    }
};
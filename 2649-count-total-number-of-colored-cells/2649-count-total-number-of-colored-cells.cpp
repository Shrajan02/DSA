// Arithmetic Progression
// TC: O(1)
// SC: O(1)
class Solution {
public:
    long long coloredCells(int n) {
        /* 
        => 1 + (4 * 1) + (4 * 2) + ... + (4 * (n - 1))
        => 1 + 4[n * (n - 1) / 2] 
        => 1 + 2[n * (n - 1)]
        */
        long long ap = 1 + (2LL * n * (n - 1));
        return ap;
    }
};
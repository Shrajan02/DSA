// Math approach
// TC: O(1)
// SC: O(1)
class Solution {
public:
    int differenceOfSums(int n, int m) {
        // diffSums = totalSum - 2 * divisibleSum
        int totalSum = (n * (n + 1)) / 2;
        int limit = n / m;
        // m + 2m + 3m + ... + km
        // m × (1 + 2 + ... + k)
        // m × (k × (k + 1)) / 2
        int divisibleSum_twice = m * (limit * (limit + 1));   
        return (totalSum - divisibleSum_twice);
    }
};
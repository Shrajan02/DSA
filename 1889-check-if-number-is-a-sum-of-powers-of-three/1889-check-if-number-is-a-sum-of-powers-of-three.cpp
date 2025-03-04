// Ternary Representation Approach
// TC: O(log\3(n))
// SC: O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 1) {
            /*
            Either it is divisible by 3 directly, so divide by 3
            Or it must be a sum of powers of 3 which includes 3^0, so subtract one and divide by 3
            [3^2 + 3^1 = 3(3^1 + 3^0)]
            */
            if (n % 3 == 0 || (n - 1) % 3 == 0) {
                n /= 3;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
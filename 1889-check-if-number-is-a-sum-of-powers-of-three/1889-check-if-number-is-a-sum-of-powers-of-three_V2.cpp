// TC: O(1)
// SC: O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        // max power to be checked = 3^16
        for (int i = 16; i >= 0; i--) {
            int power = std::pow(3, i);
            if (n - power >= 0) {
                n -= power;
            }
        }
        return (n == 0);
    }
};

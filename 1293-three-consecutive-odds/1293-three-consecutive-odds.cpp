// Brute-Force Counting approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddTriplet = 0;
        for (int num: arr) {
            if (num % 2 == 1) {
                oddTriplet++;
            }
            else {
                oddTriplet = 0;
            }

            if (oddTriplet == 3) {
                return true;
            } 
        }
        return false; 
    }
};
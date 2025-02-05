// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        int n = s1.length();
        int firstIndex = 0, secondIndex = 0;
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            char ch1 = s1[i], ch2 = s2[i];
            if (ch1 != ch2) {
                swaps++;
                if (swaps > 2) {
                    return false;
                }
                else if (swaps == 1) {
                    firstIndex = i;
                }
                else {
                    secondIndex = i;
                }
            }
        }

        // check if swap is possible
        return (s1[firstIndex] == s2[secondIndex] && s2[firstIndex] == s1[secondIndex]);
    }
};
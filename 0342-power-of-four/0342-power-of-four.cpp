// Math approach (inbuilt functions)
// TC: O(1)
// SC: O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        double remainder = std::log10(n) / std::log10(4);
        return (n > 0) && std::fmod(remainder, 1) == 0; 
    }
};
// Math approach
// TC: O(1)
// SC: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        double remainder = std::log10(n) / std::log10(3);
        return (n > 0) && (std::ceil(remainder) == std::floor(remainder));
        // return (n > 0) && std::fmod(remainder, 1) == 0; 
    }
};
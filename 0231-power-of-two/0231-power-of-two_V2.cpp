// Ceil & Floor method
// TC: O(1)
// SC: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
          return false;
        }
      
        return std::floor(std::log2(n)) == std::ceil(std::log2(n));
    }
};

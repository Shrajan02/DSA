class Solution {
public:
    int numberOfSteps(int num) {
        // Bit manipulation
        int count = 0;
        while (num) {
            num = num & 1 ? num - 1 : num >> 1;  // right shift operator
            count++;
        }
        return count;
    }
};
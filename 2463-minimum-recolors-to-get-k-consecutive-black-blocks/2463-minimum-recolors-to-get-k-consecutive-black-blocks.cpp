// Sliding Window approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int left = 0, countW = 0;
        int recolors = INT_MAX;

        for (int right = 0; right < n; right++) {
            // if white block is found
            if (blocks[right] == 'W') {
                countW++;
            }

            // slide the window once 'k' colors are scanned
            if (right - left + 1 == k) {
                recolors = min(countW, recolors);

                // check for initial color 
                if (blocks[left] == 'W') {
                    countW--;
                }
                left++;
            }
        }
        return recolors;
    }
};
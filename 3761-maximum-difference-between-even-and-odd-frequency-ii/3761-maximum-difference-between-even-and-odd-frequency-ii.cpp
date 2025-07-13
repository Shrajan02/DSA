// Sliding Window approach
// TC: O(n)
// SC: O(1)
class Solution {
private:
    int getState(int count_a, int count_b) {
        int parity_a = count_a % 2; // odd parity will be 1
        int parity_b = count_b % 2; // even parity will be 0

        if (parity_a == 0 && parity_b == 0) return 0; // even-even (00)
        if (parity_a == 0 && parity_b == 1) return 1; // even-odd (01)
        if (parity_a == 1 && parity_b == 0) return 2; // odd-even (10)
        return 3;  // odd-odd (11)
    }

public:
    int maxDifference(string s, int k) {
        int n = s.length();
        int result = INT_MIN;

        // Step 1: Try all possible (a, b) pairs from '0' to '4'
        for (int a = 0; a <= 4; a++) {
            for (int b = 0; b <= 4; b++) {
                if (a == b) continue; // cannot have same number with different frequency

                // Step 2: stateMinPrev[state] => stores min value of (count_a - count_b) for 4 states
                vector<int> stateMinPrev(4, INT_MAX);
                int count_a = 0, count_b = 0; // till index 'r'
                int prev_a = 0, prev_b = 0; // till previous index 'l'

                // Step 3: Apply Sliding Window
                int l = -1;
                for (int r = 0; r < n; r++) {
                    count_a += (s[r] == ('0' + a)) ? 1 : 0;
                    count_b += (s[r] == ('0' + b)) ? 1 : 0;

                    // shrink from 'l' & count checks avoid saving invalid states in stateMinPrev 
                    while (r - l >= k && count_b - prev_b >= 2 && count_a - prev_a >= 1) {
                        int leftState = getState(prev_a, prev_b);
                        stateMinPrev[leftState] = std::min(prev_a - prev_b, stateMinPrev[leftState]);

                        l++;
                        prev_a += (s[l] == ('0' + a)) ? 1 : 0;
                        prev_b += (s[l] == ('0' + b)) ? 1 : 0;
                    }

                    int rightState = getState(count_a, count_b);
                    int minLeftState = rightState ^ 2;  // XOR 2 (odd-even state) flips parity of 'a' to find best previous state to maximise difference
                    int minLeftDiffVal = stateMinPrev[minLeftState];

                    if (minLeftDiffVal != INT_MAX) {
                        result = max((count_a - count_b) - minLeftDiffVal, result);
                    }
                }
            }
        }

        return result;
    }
};

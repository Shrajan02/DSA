// Greedy approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int maxMD = 0;
        int x = 0, y = 0; // start at origin

        for (int i = 0; i < n; i++) {
            char dir = s[i];
            if (dir == 'N') y++;
            else if (dir == 'S') y--;
            else if (dir == 'E') x++;
            else if (dir == 'W') x--;
        
            int currMD = abs(x) + abs(y);
            int steps = i + 1; // potential max distance
            int wasted = steps - currMD; // steps are wasted when steps != current MD

            // flipping 1 step gives +2 steps
            // so, flipping k steps give 2*k steps
            int extra = 0;
            if (wasted != 0) {
                extra = min(2 * k, wasted);  // {total possible k flips, distance needed to reach steps}
            }

            int maxCurrMD = currMD + extra;
            maxMD = max(maxCurrMD, maxMD);
        }

        return maxMD;
    }
};

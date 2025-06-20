// Greedy approach
// TC: O(n)
// SC: O(1)
class Solution { 
public:
    int maxDistance(string s, int k) 
    {
        int n = s.length();
        int maxMD = 0;
        int x = 0, y = 0;   // start at origin
        
        for (int i = 0; i < n; i++) 
        {  
            char dir = s[i];
            if (dir == 'N') y++;      
            else if (dir == 'S') y--;
            else if (dir == 'E') x++;
            else if (dir == 'W') x--;

            // calculate potential max distance with up to k changes
            int currMD = abs(x) + abs(y);
            int steps = i + 1;
            int wasted = steps - currMD;

            int extra = 0;
            // when steps != currMD
            if (wasted != 0) {  
                extra = min(2 * k, wasted);
            }

            int maxCurrMD = currMD + extra;
            maxMD = max(maxCurrMD, maxMD);
        }

        return maxMD;  
    }
};


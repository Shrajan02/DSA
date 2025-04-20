// Hash Table + Greedy approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freqMap;
        int minRabbits = 0;
        for (int ans: answers) {
            if (ans == 0) {
                minRabbits++;   // each 0 indicates unique rabbut
                continue;
            }

            freqMap[ans]++;
            // if group complete, add to total & reset
            if (freqMap[ans] == ans + 1) {
                freqMap.erase(ans);
                minRabbits += (ans + 1); 
            }
        }

        // handles incomplete groups
        for (auto& [val, count]: freqMap) {
            minRabbits += (val + 1);
        }

        return minRabbits;
    }
};

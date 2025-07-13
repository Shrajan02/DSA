// Sorting + 2 pointers + Greedy approach
// TC: O(nlogn + mlogm)
// SC: O(logn + logm)
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        int matchings = 0;

        // sorting ensures higher capacity trainers are not wasted on low ability players
        ranges::sort(players); 
        ranges::sort(trainers);

        int i = 0, j = 0; 
        while (i < n && j < m) {
            if (players[i] <= trainers[j]) {
                matchings++;
                i++;
            }            
            j++;
        }

        return matchings;
    }
};
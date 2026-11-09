// greedy approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // invalid case
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i];
            total -= cost[i];
        }
        if (total < 0) return -1;

        // applying kadane's algo on (gas-cost) , use pre-checking
        // observation: if you can't go from stA to stB, then anywhere between it is not a valid point
        int balance = 0, startIndex = 0;
        for (int i = 0; i < n; i++) {
            if (balance < 0) {
                startIndex = i;
                balance = 0;
            }

            balance += (gas[i] - cost[i]);
        }
        
        return startIndex;
    }
};
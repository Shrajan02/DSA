// Hash Table approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxLucky = -1;

        // construct hash map
        unordered_map<int, int> frequency;
        for (int& num: arr) {
            frequency[num]++;
        }

        // check max element equal to frequency
        for (auto& [key, freq]: frequency) {
            if (key == freq && key > maxLucky) {
                maxLucky = key;
            }
        }

        return maxLucky;
    }
};
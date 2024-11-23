class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashTable;
        for (char c: s) {
            hashTable[c]++;
        }

        vector<pair<int, char>> freq;
        for (auto hash: hashTable) {
            freq.push_back({hash.second, hash.first});
        }
        sort(freq.rbegin(), freq.rend());

        string sorted = "";
        for (auto x: freq) {
            int count = x.first;
            while (count > 0) {
                sorted += x.second;
                count--;
            } 
        }
        return sorted;
    }
};
// Hash Table approach
// TC: O(n * k * log(k))
// SC: O(n * k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;

        // group words by lexicographically sorted signature
        std::unordered_map<string, vector<string>> sortedMap;  
        for (const string& word : strs) {
            // sorted string used as a key
            string sortedWord = word; 
            std::sort(sortedWord.begin(), sortedWord.end());

            sortedMap[sortedWord].push_back(word);
        }

        for (const auto& [ _, wordList] : sortedMap) {
            anagrams.push_back(wordList);
        }

        return anagrams;
    }
};
// Hash Map approach
// TC: O(M), M -> total number of letters in all words combined
// SC: O(1)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // build hash map for dictionary 
        vector<int> orderMap(26);
        for (int i = 0; i < 26; i++) {
            orderMap[order[i] - 'a'] = i;
        }

        int n = words.size();
        for (int i = 1; i < n; i++) {
            string& first_word = words[i - 1];
            string& next_word = words[i];
            
            int u = first_word.length(), v = next_word.length();
            int index = 0;
            bool is_sorted = false;

            while (index < u && index < v) {
                int first_index = orderMap[first_word[index] - 'a'];
                int next_index = orderMap[next_word[index] - 'a'];

                if (first_index < next_index) {
                    is_sorted = true;
                    break;
                }
                else if (first_index > next_index) {
                    return false;
                }

                index++;
            }

            if (!is_sorted && u > v) {
                return false;
            }
        }

        return true;
    }
};
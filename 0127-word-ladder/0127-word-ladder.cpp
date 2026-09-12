// BFS approach
// TC: O(n*m^2)
// SC: O(n*m^2)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        // edge case: when endword is not in wordlist
        bool flag = false;
        for (const string& word : wordList) {
            if (endWord == word) {
                flag = true;
                break;
            }
        }

        if (!flag) return 0;

        // first create a map to get unique values of possible variations as keys and check it against all the words
        // TC goes upto O(n*m*26), kinda high
        unordered_map<string, vector<string>> patternMap;
        int m = beginWord.length();

        // all words variations
        for (const string& word : wordList) {
            for (int i = 0; i < m; i++) {
                string temp = word;
                temp[i] = '*';
                patternMap[temp].push_back(word);
            }
        }

        queue<string> neighbors;
        neighbors.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        int level = 0;
        while (!neighbors.empty()) {
            level++;
            int currentSize = neighbors.size();

            for (int i = 0; i < currentSize; i++) {
                string mappedWord = neighbors.front();
                neighbors.pop();

                if (mappedWord == endWord) {
                    return level;
                }

                for (int j = 0; j < m; j++) {
                    string pattern = mappedWord.substr(0, j) + '*' + mappedWord.substr(j + 1);
                    
                    if (patternMap.find(pattern) != patternMap.end()) {
                        for (const string& neighbor : patternMap[pattern]) {
                            if (visited.find(neighbor) == visited.end()) {
                                visited.insert(neighbor);
                                neighbors.push(neighbor);
                            }
                        }
                    }
                }
            } 
        }

        return 0;
    }
};
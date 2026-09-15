// BFS approach (character replacement)
// TC: O(n*m*26)
// SC: O(n*m)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = beginWord.length();
        queue<pair<string, int>> q;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // edge case: when endWord is not present in wordList    
        if (!wordSet.count(endWord)) {
            return 0;
        }

        // run BFS
        q.push({beginWord, 1});
        wordSet.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int seq = q.front().second;
            q.pop();

            if (word == endWord) {
                return seq;
            }

            for (int i = 0; i < m; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // if that word exists
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, seq + 1});
                        wordSet.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};
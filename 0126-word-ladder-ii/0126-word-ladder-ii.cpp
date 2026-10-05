// BFS + Backtracking DFS approach
class Solution {
    vector<vector<string>> ladders;
    unordered_map<string, int> wordMap;
    
private:
    void dfs(vector<string>& ladder, string start, string word) {
        if (word == start) {
            vector<string> correctLadder = ladder;
            std::reverse(correctLadder.begin(), correctLadder.end());
            ladders.push_back(correctLadder);
            return;
        }

        int wordLevel = wordMap[word];
        for (int i = 0; i < word.length(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                // need to exist on the required level
                if (wordMap.find(word) != wordMap.end() && wordMap[word] == wordLevel - 1) {
                    ladder.push_back(word);
                    dfs(ladder, start, word);
                    ladder.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // build level map from src to dest
        unordered_set<string> unvisited(wordList.begin(), wordList.end());
        if (unvisited.find(endWord) == unvisited.end()) {
            return {};
        }
        unvisited.erase(beginWord);

        wordMap[beginWord] = 0;

        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int level = wordMap[word];

            if (word == endWord) {
                break;
            }

            for (int i = 0; i < word.length(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (unvisited.find(word) != unvisited.end()) {
                        q.push(word);
                        unvisited.erase(word);
                        wordMap[word] = level + 1;
                    }
                }
                word[i] = original;
            }
        }

        // backtracking from dest to src
        if (wordMap.find(endWord) != wordMap.end()) {
            vector<string> ladder;
            ladder.push_back(endWord);
            dfs(ladder, beginWord, endWord);
        }

        return ladders;
    } 
};
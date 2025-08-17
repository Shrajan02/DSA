// Priority Queue approach
// TC: O(T*log(k)) = O(T)
// SC: O(k) = O(1)
// where T = number of tasks, k = 26
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // build frequency map
        std::vector<int> freq(26, 0);
        for (char ch: tasks) {
            freq[ch - 'A']++;
        }

        // push the frequencies to heap
        std::priority_queue<int> maxH;
        for (int count: freq) {
            if (count > 0) {
                maxH.push(count);
            }
        }

        int time = 0;
        while (!maxH.empty()) {
            int cycle = n + 1;
            std::vector<int> temp;

            // execution of tasks per cycle
            while (cycle && !maxH.empty()) {
                int max_freq = maxH.top();
                maxH.pop();
                // only 1 task at a time
                if (max_freq > 1) {
                    temp.push_back(--max_freq); 
                }
                time++;
                cycle--;
            }

            for (int count: temp) {
                maxH.push(count);
            }
            
            if (maxH.empty()) {
                break;   // do not include idle time if all tasks are completed
            }
            time += cycle;  // counts idle time
        }

        return time;
    }
};
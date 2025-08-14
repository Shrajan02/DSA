// Priority Queue approach
// TC: O(n*log(n))
// SC: O(n)
using pii = pair<int, int>;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::vector <int> res;
        
        std::unordered_map <int,int> freqMap;  
        for (auto num : nums) {
            freqMap[num]++;
        }

        std::priority_queue <pii, vector<pii>, greater<pii>> minH; // {num, freq}
        for (auto [num, freq] : freqMap) {
            minH.push({freq, -num}); // using -ve to handle descending order for same frequency
        }
        while (!minH.empty()) {
            for (int i = 0; i < minH.top().first; i++) { // freq 
                res.push_back(-minH.top().second); // num 
            }
            minH.pop();
        }

        return res;
    }
};
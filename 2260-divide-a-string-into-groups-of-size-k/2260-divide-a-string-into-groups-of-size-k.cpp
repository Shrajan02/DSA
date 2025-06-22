// Brute-force Substring approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> res;

        for (int i = 0; i < n; i += k) {
            int len = min(n - i, k);
            string temp = s.substr(i, len);

            // for last string 
            while (temp.size() < k) {
                temp += fill;
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};
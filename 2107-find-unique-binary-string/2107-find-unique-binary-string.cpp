// Random Selection approach
// TC: O(n^2)
// SC: O(n)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> allPossibleInt; // base-10 integers
        for (string num : nums) {
         allPossibleInt.insert(stoi(num, 0, 2));  // (value, position, base)
        }
        
        int ans = stoi(nums[0], 0, 2);  // initial candidate
        int n = nums.size();
        
        // using random generation
        while (allPossibleInt.find(ans) != allPossibleInt.end()) {
            ans = rand() % (int) pow(2, n);
        }
        
        // max 16-character binary string
        return bitset<16>(ans).to_string().substr(16 - n);
    }
};
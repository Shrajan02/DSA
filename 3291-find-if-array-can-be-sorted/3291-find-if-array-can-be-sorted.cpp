int countSet(int n) {
    int setBits = 0; 
    while (n > 0) {
        // n = n & (n - 1)
        if (n & 1) {
            setBits++;
        }
        n = n >> 1;
    }
    return setBits;

}

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> copy = nums;
        // Bubble sort approach
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (copy[j] <= copy[j+1]) {
                    continue;   // No swap required
                }
                else {
                    if (countSet(nums[j]) == countSet(nums[j+1])) {
                        swap(copy[j], copy[j+1]);  // Swap the elements
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
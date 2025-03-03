// 2-pointer approach(3 pass)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);

        int left = 0; 
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                res[left] = nums[i];
                left++;
            }
        }    

        int right = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > pivot) {
                res[right] = nums[j];
                right--;
            }
        }    
        
        // equal elements
        while(left <= right) {
            res[left] = pivot;
            left++;
        }

        return res;
    }
};
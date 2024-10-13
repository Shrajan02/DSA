class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Right neighbour greater
            if (mid < n - 1 && nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } 
            // Left neighbour greater
            else if(mid > 0 && nums[mid] < nums[mid - 1]) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};

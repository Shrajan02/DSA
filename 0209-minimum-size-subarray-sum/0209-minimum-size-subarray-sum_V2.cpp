// Sorting + Binary Search approach
// TC: O(n * log(n))
// SC: O(1)
class Solution {
public:
    bool windowFind(int size, vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, maxi = INT_MIN;
      
        while (j < n) {
            sum += nums[j];
            if (j - i + 1 == size) {
                maxi = max(sum, maxi);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if (maxi >= target) {
            return true;
        }   
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 1, high = nums.size();
        int minLen = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            bool possible = windowFind(mid, nums, target);
            if (possible) {
                high = mid - 1;
                minLen = mid;
            } 
            else {
                low = mid + 1;
            }
                
        }
        return minLen;
    }
};

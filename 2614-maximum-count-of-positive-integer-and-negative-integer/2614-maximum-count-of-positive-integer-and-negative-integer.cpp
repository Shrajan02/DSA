// Binary Search approach
// TC: O(log n)
// SC: O(1)
class Solution {
private:
    int lowerBound(vector<int>& nums, int n) {
        int low = 0, high = n - 1; 
        int ind = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < 0) {
                low = mid + 1;
            }
            else if (nums[mid] >= 0) {
                high = mid - 1;
                ind = mid;
            }
        }
        return ind;
    }

    int upperBound(vector<int>& nums, int n) {
        int low = 0, high = n - 1;
        int ind = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= 0) {
                low = mid + 1;
            }
            else if (nums[mid] > 0) {
                high = mid - 1;
                ind = mid;
            }
        }
        return ind;
    }

public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int firstZero = lowerBound(nums, n);
        int lastZero = upperBound(nums, n);
        int neg = firstZero;
        int pos = n - lastZero;
        return max(neg, pos);
    }
};
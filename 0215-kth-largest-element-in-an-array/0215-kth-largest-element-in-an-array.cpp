// QuickSelect approach (Hoare's Partitioning Algo)
// TC: O(n) for best & avg case, O(n^2) for worst case
// SC: O(1)
class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];  
        int i = left, j = right; 

        while (true) {
            while (i <= right && nums[i] < pivot) {
                i++;
            }
            while (j >= left && nums[j] > pivot) {
                j--;
            }
            if (i >= j) {
                return j;  // partition index
            }

            // when nums[i] >= pivot AND nums[j] <= pivot
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int targetIdx = n - k;
        int left = 0, right = n - 1;

        while (left < right) {
            int p = partition(nums, left, right);
            if (p < targetIdx) {
                left = p + 1;  // recurse right half
            }
            else {
                right = p;  // recurse left half
            }
        }

        // left = right = targetIdx
        return nums[targetIdx];
    }
};
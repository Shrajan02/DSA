class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        if (m == 0 && n == 0) return (double)(0);
        vector<int> merge;

        // Merging arrays using 2-pointers
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merge.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                merge.push_back(nums2[j]);
                j++;
            }
            else {
                merge.push_back(nums1[i++]);
                merge.push_back(nums2[j++]);
            }
        }
        while (i < m) {
            merge.push_back(nums1[i++]);
        }
        while (j < n) {
            merge.push_back(nums2[j++]);
        }

        int median = (m + n) >> 1;  
        // Odd length case
        if ((m + n) % 2 == 1) {
            return (double)(merge[median]);
        }
        // Even length case
        else {
            return (merge[median-1] + merge[median]) / 2.0; 
        }
    }
};

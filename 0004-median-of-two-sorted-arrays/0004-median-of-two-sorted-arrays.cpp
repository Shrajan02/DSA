class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // Apply BS on minimum array
        if (m > n)
            return findMedianSortedArrays(nums2, nums1); 

        int total = m + n;
        int left = (total + 1) / 2; // Length of left partition

        int low = 0, high = m;
        while (low <= high) {
            // Partition index for both arrays {mid1 + mid2 == left}
            int mid1 = low + ((high - low) >> 1); // mid for smaller array
            int mid2 = left - mid1;               // mid for larger array

            // Left & right sides of both partitions
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            // Checking for out of bounds 
            if (mid1 < m)
                r1 = nums1[mid1];
            if (mid2 < n)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (max(l1, l2) <= min(r1, r2)) {
                if (total % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0;
    }
};

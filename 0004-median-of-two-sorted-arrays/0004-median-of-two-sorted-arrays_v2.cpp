class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        if (m == 0 && n == 0)
            return (double)(0);

        // Checking for medians using 2-pointers(without merging)
        int total = m + n;
        int mid1 = total / 2 - 1, mid2 = total / 2;
        int median1 = -1, median2 = -1;
        int i = 0, j = 0, count = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (count == mid1)
                    median1 = nums1[i];
                if (count == mid2)
                    median2 = nums1[i];
                count++;
                i++;
            } else {
                if (count == mid1)
                    median1 = nums2[j];
                if (count == mid2)
                    median2 = nums2[j];
                count++;
                j++;
            }
        }

        while (i < m) {
            if (count == mid1)
                median1 = nums1[i];
            if (count == mid2)
                median2 = nums1[i];
            count++;
            i++;
        }

        while (j < n) {
            if (count == mid1)
                median1 = nums2[j];
            if (count == mid2)
                median2 = nums2[j];
            count++;
            j++;
        }

        // Odd length case
        if (total % 2 == 1) {
            return (double)median2;
        }
        // Even length case
        else {
            return (double)((median1 + median2) / 2.0);
        }
    }
};

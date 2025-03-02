// TC: O(n + m)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;  // 2-pointer
        vector<vector<int>> res;
        while (i < n && j < m) {
            if (nums1[i][0] > nums2[j][0]) {
                res.push_back(nums2[j++]);
            }
            else if (nums1[i][0] < nums2[j][0]) {
                res.push_back(nums1[i++]);
            }
            else {
                // equal case
                int val = nums1[i][1] + nums2[j][1];
                res.push_back({nums1[i][0], val});
                i++;
                j++;
            }
        }
        
        while (i < n) {
            res.push_back(nums1[i++]);
        }
        while (j < m) {
            res.push_back(nums2[j++]);
        }

        return res;
    }
};
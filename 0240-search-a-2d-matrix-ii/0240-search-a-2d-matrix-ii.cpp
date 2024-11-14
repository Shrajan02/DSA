// TC: O (m * log(n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                if (matrix[i][mid] < target)
                    low = mid + 1;
                else if (matrix[i][mid] > target) 
                    high = mid - 1;
                else 
                    return true;
            }
        }
        return false;
    }
};
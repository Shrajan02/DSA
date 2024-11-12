class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();    // rows
        int m = matrix[0].size(); // columns
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int row = mid / m, col = mid % m; // flattening 2D array to 1D
            if (matrix[row][col] > target) {
                high = mid - 1;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();  // rows
        int m = matrix[0].size();  // columns
        int low = 0, high = n-1;

        while (low <= high) {
            int midRow = low + ((high - low) >> 1);
            // perform BS within this 1D array 
            if (matrix[midRow][0] <= target && matrix[midRow][m-1] >= target) {  
                int left = 0, right = m-1;
                while(left <= right) {
                    int midCol = left + ((right - left) >> 1);
                    if (matrix[midRow][midCol] > target) {
                        right = midCol - 1;
                    }
                    else if (matrix[midRow][midCol] < target) {
                        left = midCol + 1;
                    }
                    else {
                        return true;
                    }
                }
                return false;
            }
            else if (matrix[midRow][0] > target) {
                high = midRow - 1;
            }
            else {
                low = midRow + 1;
            }

        }
        return false;
    }
};

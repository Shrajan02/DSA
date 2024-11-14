// TC: O(m + n)
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n-1;

        while (row < m && col >= 0) {
            int curr = matrix[row][col];
            if (curr < target)
                row++;
            else if (curr > target)
                col--;
            else 
                return true;
        }
        return false;
    }
};
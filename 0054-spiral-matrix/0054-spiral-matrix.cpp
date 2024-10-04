class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, right = n - 1, bottom = m - 1, left = 0; // Walls of matrix

        while (top <= bottom && left <= right) {
            // Left -> right
            for (int i = left; i <= right; i++) {
                spiral.push_back(matrix[top][i]);
            }
            top++; // Move the wall by 1

            // Top -> Bottom
            for (int i = top; i <= bottom; i++) {
                spiral.push_back(matrix[i][right]);
            }
            right--;

            // Right -> Left
            if (top <= bottom) {  // Since both boundary updates
                for (int i = right; i >= left; i--) {
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    spiral.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return spiral;
    }
};
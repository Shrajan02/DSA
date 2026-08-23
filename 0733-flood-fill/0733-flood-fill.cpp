// DFS approach
// TC: O(m*n)
// SC: O(m*n)
class Solution {
public:
    void floodfill(vector<vector<int>>& image, int row, int col, int color, int value) {
        int m = image.size(), n = image[0].size();
        image[row][col] = color;
        
        // left
        if (row - 1 >= 0 && image[row - 1][col] != color && image[row - 1][col] == value)
            floodfill(image, row - 1, col, color, value);

        // right
        if (row + 1 < m && image[row + 1][col] != color && image[row + 1][col] == value)
            floodfill(image, row + 1, col, color, value);

        // top
        if (col - 1 >= 0 && image[row][col - 1] != color && image[row][col - 1] == value)
            floodfill(image, row, col - 1, color, value);

        // bottom
        if (col + 1 < n && image[row][col + 1] != color && image[row][col + 1] == value)
            floodfill(image, row, col + 1, color, value);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor != color) {
            floodfill(image, sr, sc, color, oldColor);
        }
           
        return image;
    }
};
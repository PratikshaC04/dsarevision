class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Modify the grid in-place to save space (can also use a separate dp array)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue; // Starting point
                else if (i == 0) grid[i][j] += grid[i][j - 1]; // First row
                else if (j == 0) grid[i][j] += grid[i - 1][j]; // First column
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); // Min of top and left
            }
        }

        return grid[m - 1][n - 1]; // Minimum path sum to bottom-right corner
    }
};

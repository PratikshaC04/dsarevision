#include <vector> // Required for std::vector

class Solution {
public:
    // Helper DFS function to explore and mark connected land cells
    void dfs(std::vector<std::vector<char>>& grid, int r, int c) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        // Base cases:
        // 1. If current cell is out of bounds
        // 2. If current cell is water ('0')
        if (r < 0 || r >= numRows || c < 0 || c >= numCols || grid[r][c] == '0') {
            return;
        }

        // Mark the current land cell as visited by changing '1' to '0'
        // This is crucial to prevent revisiting and counting the same island multiple times.
        grid[r][c] = '0';

        // Recursively call DFS for all four cardinal neighbors
        dfs(grid, r + 1, c); // Explore down
        dfs(grid, r - 1, c); // Explore up
        dfs(grid, r, c + 1); // Explore right
        dfs(grid, r, c - 1); // Explore left
    }

    // Main function to count the number of islands
    int numIslands(std::vector<std::vector<char>>& grid) {
        // Handle edge case: empty grid or grid with empty rows
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int numRows = grid.size();
        int numCols = grid[0].size();
        int islandCount = 0; // Initialize counter for islands

        // Iterate through each cell of the grid
        for (int r = 0; r < numRows; ++r) {
            for (int c = 0; c < numCols; ++c) {
                // If we find a '1' (land cell) that hasn't been visited yet
                if (grid[r][c] == '1') {
                    islandCount++;      // Increment island count as we found a new island
                    dfs(grid, r, c);    // Start DFS from this cell to mark all connected land as visited
                }
            }
        }

        return islandCount; // Return the total number of islands
    }
};
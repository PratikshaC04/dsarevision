class Solution {
public:
         int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        int days = 0;         // To track number of minutes passed
        int total = 0;        // Total number of oranges (fresh + rotten)
        int count = 0;        // Number of rotten oranges processed
        queue<pair<int, int>> rotten; // Queue for BFS traversal of rotten oranges

        // Step 1: Count total oranges and push initial rotten oranges into the queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) total++;     // Count fresh and rotten oranges
                if (grid[i][j] == 2) rotten.push({i, j}); // Initial rotten oranges
            }
        }

        // Directions: right, left, down, up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Step 2: BFS traversal
        while (!rotten.empty()) {
            int k = rotten.size(); // Number of rotten oranges at current level
            count += k;            // Increase count of processed oranges

            // Process all current rotten oranges
            while (k--) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                // Spread rot to adjacent fresh oranges
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    // Skip invalid or non-fresh positions
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                        continue;

                    // Rot the fresh orange and add it to the queue
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }

            // Only increment days if new oranges have rotted
            if (!rotten.empty()) days++;
        }

        // Step 3: Final check - if all oranges rotted, return days; else, return -1
        return total == count ? days : -1;   
    }
};

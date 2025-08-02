class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int row = 0; row < m; ++row) {
            int left = 0, right = n - 1, firstNeg = n;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[row][mid] < 0) {
                    firstNeg = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            count += n - firstNeg;
        }

        return count;
    }
};

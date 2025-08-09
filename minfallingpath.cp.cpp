class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(matrix[0]); // First row is the base case

        for (int i = 1; i < n; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + prev[j];
                int leftDiagonal = (j > 0) ? matrix[i][j] + prev[j - 1] : INT_MAX;
                int rightDiagonal = (j < n - 1) ? matrix[i][j] + prev[j + 1] : INT_MAX;

                curr[j] = min({up, leftDiagonal, rightDiagonal});
            }
            prev = curr; // Move to next row
        }

        return *min_element(prev.begin(), prev.end());
    }
};

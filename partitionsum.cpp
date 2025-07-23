class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // Base case: sum 0 is always possible with empty subset
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= target; t++) {
                if (t >= nums[i - 1])
                    dp[i][t] = dp[i - 1][t] || dp[i - 1][t - nums[i - 1]];
                else
                    dp[i][t] = dp[i - 1][t];
            }
        }

        return dp[n][target];
    }
};

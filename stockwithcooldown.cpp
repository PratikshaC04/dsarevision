class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int prev2_not_hold = 0;              // dp[i-2][0]
        int prev_not_hold = 0;               // dp[i-1][0]
        int prev_hold = -prices[0];          // dp[i-1][1]

        for (int i = 1; i < n; i++) {
            int curr_not_hold = max(prev_not_hold, prev_hold + prices[i]);
            int curr_hold = max(prev_hold, prev2_not_hold - prices[i]);

            prev2_not_hold = prev_not_hold;
            prev_not_hold = curr_not_hold;
            prev_hold = curr_hold;
        }

        return prev_not_hold;  // Final answer is in the "not holding" state
    }
};

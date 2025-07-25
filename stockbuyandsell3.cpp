class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // Optimization: If k is very large, use unlimited transactions approach
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            return profit;
        }

        // dp[transactions][holding]
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        for (int i = 0; i <= k; ++i)
            dp[i][1] = INT_MIN;  // impossible to hold without buying

        for (int price : prices) {
            for (int t = 1; t <= k; ++t) {
                dp[t][0] = max(dp[t][0], dp[t][1] + price);        // sell
                dp[t][1] = max(dp[t][1], dp[t - 1][0] - price);    // buy
            }
        }
        return dp[k][0];
    }
};

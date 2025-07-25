class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0];  // Holding stock
        int notHold = 0;        // Not holding

        for (int i = 1; i < n; ++i) {
            int newNotHold = max(notHold, hold + prices[i] - fee);
            int newHold = max(hold, notHold - prices[i]);

            notHold = newNotHold;
            hold = newHold;
        }

        return notHold;  // Final answer is when not holding a stock
    }
};

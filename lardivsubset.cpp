class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);        // dp[i] = length of subset ending at i
        vector<int> prev(n, -1);     // prev[i] = index of previous element in the subset

        int maxIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        // Reconstruct the subset
        vector<int> res;
        int curr = maxIndex;
        while (curr >= 0) {
            res.push_back(nums[curr]);
            curr = prev[curr];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

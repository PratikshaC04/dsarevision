class Solution {
public:
    int prime = 1e9 + 7; 

    int countUtil(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp) {
        // If s2 is exhausted, one valid subsequence found
        if (ind2 < 0) return 1;

        // If s1 is exhausted but s2 is not, can't form subsequence
        if (ind1 < 0) return 0;

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int result = 0;
        if (s1[ind1] == s2[ind2]) {
            int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
            int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);
            result = (leaveOne + stay) % prime;
        } else {
            result = countUtil(s1, s2, ind1 - 1, ind2, dp);
        }

        return dp[ind1][ind2] = result;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countUtil(s, t, n - 1, m - 1, dp);
    }
};

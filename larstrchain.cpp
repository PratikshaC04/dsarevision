class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        int maxLen = 1;

        for (string word : words) {
            dp[word] = 1; // Each word is at least a chain of length 1
            for (int i = 0; i < word.length(); ++i) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end()) {
                    dp[word] = max(dp[word], dp[prev] + 1);
                }
            }
            maxLen = max(maxLen, dp[word]);
        }

        return maxLen;
    }
};

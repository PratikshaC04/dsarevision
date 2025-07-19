class Solution {
public:
    int characterReplacement(string s, int k) {
       
    int maxLen = 0;
    int maxCount = 0;
    vector<int> freq(26, 0);
    int left = 0;

    for (int right = 0; right < s.length(); ++right) {
        freq[s[right] - 'A']++;
        maxCount = max(maxCount, freq[s[right] - 'A']);

        // if more than k chars need to be changed, shrink window
        while ((right - left + 1) - maxCount > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

    
};
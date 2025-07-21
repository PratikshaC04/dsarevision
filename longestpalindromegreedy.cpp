class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        int length = 0;
        bool hasOdd = false;
        
        for (auto& entry : count) {
            if (entry.second % 2 == 0) {
                length += entry.second;
            } else {
                length += entry.second - 1;
                hasOdd = true;
            }
        }
        
        if (hasOdd) length += 1; // one odd character in the center
        
        return length;
    }
};

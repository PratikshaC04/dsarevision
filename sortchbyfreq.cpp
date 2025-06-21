class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Convert map to vector of pairs
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Sort the vector in descending order of frequency
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        // Build result string
        string result;
        for (auto& p : vec) {
            result.append(p.second, p.first);
        }

        return result;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);  // Start with base case

        for (int i = 0; i < n; ++i) {
            int prefix = 1 << i;  // Set the i-th bit
            int size = result.size();
            // Reflect and add prefix
            for (int j = size - 1; j >= 0; --j) {
                result.push_back(prefix | result[j]);
            }
        }
        return result;
    }
};

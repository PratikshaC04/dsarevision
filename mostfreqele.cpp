class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int result = -1;

        for (int num : nums) {
            if (num % 2 == 0) {
                int& f = freq[num];
                f++;
                if (f > maxFreq || (f == maxFreq && num < result)) {
                    maxFreq = f;
                    result = num;
                }
            }
        }

        return result;
    }
};

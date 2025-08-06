class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                // Count total bits turned on
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    // Format time: hour without leading 0, minute with leading 0 if needed
                    result.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }

        return result;
    }
};

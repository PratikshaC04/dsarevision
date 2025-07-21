class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = INT_MIN;

        for (const auto& interval : intervals) {
            if (interval[0] >= prevEnd) {
                // No overlap, keep this interval
                prevEnd = interval[1];
            } else {
                // Overlapping, need to remove
                count++;
            }
        }

        return count;
    }
};

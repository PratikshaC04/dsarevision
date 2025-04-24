class Solution {
public:
    // Helper function to calculate the number of days needed for a given capacity
    int findDays(const vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w > cap) {
                days++;         // new day needed
                load = w;       // start new load
            } else {
                load += w;
            }
        }

        return days;
    }

    // Main function as per LeetCode signature
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (findDays(weights, mid) <= days) {
                answer = mid;
                high = mid - 1; // try to minimize capacity
            } else {
                low = mid + 1;  // increase capacity
            }
        }

        return answer;
    }
};


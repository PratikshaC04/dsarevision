class Solution {
public:
    // Check if it's possible to make m bouquets by 'day'
    bool possible(const vector<int>& bloomDay, int day, int m, int k) {
        int flowers = 0, bouquets = 0;

        for (int b : bloomDay) {
            if (b <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // reset if day condition not met
            }

            // Early exit if enough bouquets made
            if (bouquets >= m) return true;
        }

        return false;
    }

    // Main function
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalNeeded = 1LL * m * k;
        if (totalNeeded > bloomDay.size()) return -1; // Not enough flowers

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                answer = mid;
                high = mid - 1; // try to find smaller valid day
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};


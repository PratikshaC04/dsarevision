class Solution {
public:
    // Helper function to calculate sum of ceil(arr[i] / div)
    int sumByD(const vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + div - 1) / div;  // Integer ceiling
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sumByD(nums, mid) <= threshold) {
                answer = mid;
                high = mid - 1;  // Try smaller divisor
            } else {
                low = mid + 1;   // Increase divisor
            }
        }

        return answer;
    }
};


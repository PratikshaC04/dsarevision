class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If the subarray is already sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                high = mid - 1; // Fixed typo here
            }
        }

        return ans; // Fixed return value
    }
};


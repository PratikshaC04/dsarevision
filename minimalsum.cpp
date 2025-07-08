class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long prev = 0;

        for (int num : nums) {
            if (num == prev) continue; // skip duplicates

            long long gap = num - prev - 1;

            if (gap >= k) {
                // Add k numbers starting from prev + 1
                sum += (long long)(prev + 1 + prev + k) * k / 2;
                return sum;
            } else {
                // Add all gap numbers
                sum += (long long)(prev + 1 + num - 1) * gap / 2;
                k -= gap;
            }

            prev = num;
        }

        // If k numbers are still left after nums
        sum += (long long)(prev + 1 + prev + k) * k / 2;

        return sum;
    }
};

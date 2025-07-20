class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int start = 0, count = 0;

        for (int end = 0; end < n; ++end) {
            if (freq[nums[end]] == 0)
                k--;  // New unique number
            freq[nums[end]]++;

            while (k < 0) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0)
                    k++;  // One unique removed
                start++;
            }

            count += (end - start + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

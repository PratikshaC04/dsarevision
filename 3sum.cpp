class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;  // No point in continuing if the first number is > 0
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate i

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;  // Skip duplicate left
                    while (left < right && nums[right] == nums[right + 1]) --right;  // Skip duplicate right
                }
            }
        }
        return res;
    }
};

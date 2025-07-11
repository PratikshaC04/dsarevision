class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> seen;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int count = 0;
            string sub = "";
            for (int j = i; j < n; ++j) {
                if (nums[j] % p == 0) count++;
                if (count > k) break;

                sub += to_string(nums[j]) + "#"; // use separator to prevent confusion
                seen.insert(sub);
            }
        }

        return seen.size();
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n = nums.size();
        int xorResult = 0;

        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xorResult ^= i;
        }

        // XOR all numbers in the array
        for (int num : nums) {
            xorResult ^= num;
        }

        return xorResult;
    }
};

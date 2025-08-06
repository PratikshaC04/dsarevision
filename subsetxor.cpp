#include <vector>
using namespace std;

class Solution {
public:
    int total = 0;

    void dfs(int index, int currentXor, const vector<int>& nums) {
        if (index == nums.size()) {
            total += currentXor;
            return;
        }
        // Include nums[index]
        dfs(index + 1, currentXor ^ nums[index], nums);
        // Exclude nums[index]
        dfs(index + 1, currentXor, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        dfs(0, 0, nums);
        return total;
    }
};

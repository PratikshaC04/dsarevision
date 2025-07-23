class Solution {
public:
   
      int rob(vector<int>& nums) {
    int prev = nums[0];
    int prev2 = 0;
int n=nums.size();
    for (int i = 1; i < n; ++i) {
        int pick = nums[i] + (i > 1 ? prev2 : 0);
        int nonPick = prev;
        int curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}
  
    
};
class Solution {
public:
    int func(vector<int>& nums, int k){
        if(k<0) return 0;
        long long n = nums.size();
        long long left = 0, right = 0, count = 0, sum = 0;
        while(right<n){
            sum+=nums[right];
            while(left<=right && sum>k){
                sum-=nums[left];
                left++;
            }
            count+=(right-left+1);
            right++;
            
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};
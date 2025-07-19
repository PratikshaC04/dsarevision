class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums, k-1);
    }
    int f(vector<int>&nums, int k){
        int l=0,sum=0,cnt=0;
        for(int r=0; r<nums.size(); r++){
            sum+=(nums[r]%2);
            while(sum>k && l<=r){
                sum-=(nums[l]%2);
                l++;
            }
            cnt=cnt + (r-l+1);
        }
        return cnt;
    }
};
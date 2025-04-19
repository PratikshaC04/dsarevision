class Solution {
public:
    int search(vector<int>& nums, int x) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==x)
            return mid;
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=x && nums[mid]>=x)
                high=mid-1;
                else
                low=mid+1;
            }
            else
            {
               if(nums[high]>=x && nums[mid]<=x)
             low= mid+1;
                else
              high=mid-1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int x) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (nums[mid] == x)
                return true;

            // Handle duplicates at the ends
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= x && x < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Else right half is sorted
            else {
                if (nums[mid] < x && x <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};


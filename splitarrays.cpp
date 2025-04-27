class Solution {
public:
    int countStudents(vector<int>& nums, int maxPagesAllowed) {
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pagesStudent + nums[i] <= maxPagesAllowed) {
                pagesStudent += nums[i];
            }
            else {
                students++;
                pagesStudent = nums[i];
            }
        }
        return students;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int students = countStudents(nums, mid);
            
            if (students > m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};


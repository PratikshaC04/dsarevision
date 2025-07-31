class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // This pointer will keep track of the position for the next non-val element.

        // Iterate through the array with 'i'
        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is not equal to val,
            // place it at the 'k' position and increment 'k'.
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        // 'k' now represents the number of elements not equal to val.
        // The first 'k' elements of nums contain these non-val elements.
        return k;
    }
};
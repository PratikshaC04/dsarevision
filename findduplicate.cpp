int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // First part: detect cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Second part: find the start of the cycle (duplicate)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; // or fast, both point to the duplicate
}

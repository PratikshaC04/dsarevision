class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        return getSum(nums, true) - getSum(nums, false);
    }

private:
    long long getSum(vector<int>& nums, bool isMax) {
        int n = nums.size();
        long long res = 0;
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || (isMax ? nums[st.top()] < nums[i] : nums[st.top()] > nums[i]))) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long count = (mid - left) * 1LL * (right - mid);
                res += count * nums[mid];
            }
            st.push(i);
        }

        return res;
    }
};

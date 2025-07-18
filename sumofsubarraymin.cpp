class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      
const int MOD = 1e9 + 7;

    int n = arr.size();
    vector<int> ple(n), nle(n);
    stack<int> st;

    // Previous Less Element
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        ple[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear stack
    while (!st.empty()) st.pop();

    // Next Less Element (allow equal to handle duplicates)
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nle[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Total contribution
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - ple[i];
        long long right = nle[i] - i;
        sum = (sum + arr[i] * left % MOD * right % MOD) % MOD;
    }

    return sum;  
    }
};
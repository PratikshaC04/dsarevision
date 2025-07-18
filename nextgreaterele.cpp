vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> ngeMap;
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ngeMap[nums2[i]] = st.top();
        } else {
            ngeMap[nums2[i]] = -1;
        }

        st.push(nums2[i]);
    }

    vector<int> result;
    for (int num : nums1) {
        result.push_back(ngeMap[num]);
    }

    return result;
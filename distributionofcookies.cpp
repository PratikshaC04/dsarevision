class Solution {
public:
    int ans = INT_MAX;

    void backtrack(vector<int>& cookies, vector<int>& children, int i, int k) {
        if (i == cookies.size()) {
            int unfairness = *max_element(children.begin(), children.end());
            ans = min(ans, unfairness);
            return;
        }

        for (int j = 0; j < k; j++) {
            children[j] += cookies[i];
            backtrack(cookies, children, i + 1, k);
            children[j] -= cookies[i];
            if (children[j] == 0) break; // optimization: skip duplicate distribution
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        backtrack(cookies, children, 0, k);
        return ans;
    }
};

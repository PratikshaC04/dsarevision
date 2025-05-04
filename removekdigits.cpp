class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }

        // Remove from the end if k still > 0
        while (k-- > 0 && !st.empty()) {
            st.pop_back();
        }

        // Remove leading zeros
        int idx = 0;
        while (idx < st.size() && st[idx] == '0') {
            idx++;
        }

        string result = st.substr(idx);
        return result.empty() ? "0" : result;
    }
};


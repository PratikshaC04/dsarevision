class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);

        if (k == 0)
            return res;

        int step = k > 0 ? 1 : -1;
        int cnt = abs(k);

        for (int i = 0; i < n; i++) {
            int sum = 0;
            int j = i;
            for (int m = 0; m < cnt; m++) {
                j = (j + step + n) % n;
                sum += code[j];
            }
            res[i] = sum;
        }

        return res;
    }
};

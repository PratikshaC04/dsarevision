class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        vector<int> pos, neg;
        int n = A.size();

        // Separate positive and negative numbers
        for (int num : A) {
            if (num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        int i = 0, p = 0, q = 0;
        // Fill alternatively until one list runs out
        while (p < pos.size() && q < neg.size()) {
            A[i++] = pos[p++];
            A[i++] = neg[q++];
        }

        // Append remaining positives
        while (p < pos.size())
            A[i++] = pos[p++];

        // Append remaining negatives
        while (q < neg.size())
            A[i++] = neg[q++];

        return A;
    }
};


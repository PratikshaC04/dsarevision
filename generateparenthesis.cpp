class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // Add open parenthesis if we still can
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }

        // Add close parenthesis if it won't exceed open
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};

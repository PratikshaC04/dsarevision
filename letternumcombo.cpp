class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        function<void(int)> backtrack = [&](int index) {
            if (index == digits.length()) {
                result.push_back(current);
                return;
            }
            string letters = mapping[digits[index] - '0'];
            for (char ch : letters) {
                current.push_back(ch);
                backtrack(index + 1);
                current.pop_back(); // backtrack
            }
        };
        
        backtrack(0);
        return result;
    }
};

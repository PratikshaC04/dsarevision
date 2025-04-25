#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) result += '('; // skip outermost (
                depth++;
            } else {
                depth--;
                if (depth > 0) result += ')'; // skip outermost )
            }
        }

        return result;
    }
};


class Solution {
private:
    void reverse(string& str, int s, int e) {
        while (s < e) {
            swap(str[s], str[e]);
            s++;
            e--;
        }
    } 
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        // first pass
        while (i < s.size()) {
            if (s[i] != ' ' || (s[i] == ' ' && i > 0 && s[i - 1] != ' ')) {
                s[j++] = s[i++];
            } else {
                i++;
            }
        }
        if (s[j - 1] == ' ') {
            s.resize(j - 1);
        } else {
            s.resize(j);
        }
        // second pass, reverse word by word 
        int n = s.size();                                             
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
            continue;
        }
        reverse(s, start, n - 1);
        // third pass, reverse whole string
        reverse(s, 0, n - 1);
        return s;
    }
};

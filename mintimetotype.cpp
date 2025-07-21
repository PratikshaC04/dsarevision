class Solution {
public:
    int minTimeToType(string word) {
        int time = 0;
        char curr = 'a';
        for (char ch : word) {
            int dist = abs(ch - curr);
            time += min(dist, 26 - dist) + 1; // move + press
            curr = ch;
        }
        return time;
    }
};

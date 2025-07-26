class Solution {
public:
    int maximum69Number (int num) {
        std::string s = std::to_string(num);
        for (char& c : s) {
            if (c == '6') {
                c = '9';
                break;  // only change the first 6
            }
        }
        return std::stoi(s);
    }
};

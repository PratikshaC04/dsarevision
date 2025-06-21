class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long result = 0;
        int sign = 1;

        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle sign if present
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Clamp if result goes beyond 32-bit signed int range
            if (sign == 1 && result >= INT_MAX) return INT_MAX;
            if (sign == -1 && -result <= INT_MIN) return INT_MIN;

            i++;
        }

        return static_cast<int>(result * sign);
    }
};

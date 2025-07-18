class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
    int i = digits.length() - 2;

    // Step 1: Find the first decreasing digit from the end
    while (i >= 0 && digits[i] >= digits[i + 1]) {
        i--;
    }

    if (i < 0) return -1; // Already highest permutation

    // Step 2: Find the next greater digit to swap
    int j = digits.length() - 1;
    while (j >= 0 && digits[j] <= digits[i]) {
        j--;
    }

    swap(digits[i], digits[j]);

    // Step 3: Reverse the tail
    reverse(digits.begin() + i + 1, digits.end());

    // Step 4: Convert to integer and check 32-bit
    long long result = stoll(digits);
    return (result <= INT_MAX) ? (int)result : -1;
    }
};
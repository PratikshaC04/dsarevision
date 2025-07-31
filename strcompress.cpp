#include <vector>
#include <string>    // For std::to_string and string iteration (simplifies digit handling)
#include <algorithm> // For std::reverse (if using the mathematical digit extraction method)

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int write_idx = 0; // Pointer to write compressed characters
        int read_idx = 0;  // Pointer to read original characters

        int n = chars.size();

        while (read_idx < n) {
            char current_char = chars[read_idx];
            int count = 0;

            // Count consecutive repeating characters
            while (read_idx < n && chars[read_idx] == current_char) {
                read_idx++;
                count++;
            }

            // Write the character
            chars[write_idx++] = current_char;

            // If count is greater than 1, append the count
            if (count > 1) {
                // Convert count to string and append its digits
                // std::to_string allocates memory, which technically isn't O(1) extra space.
                // For a true O(1) space, we need to extract digits manually.

                // --- True O(1) extra space digit handling ---
                // This approach writes digits in reverse and then reverses them back.
                int start_of_digits = write_idx; // Mark the position where digits will start

                // Write digits in reverse order
                while (count > 0) {
                    chars[write_idx++] = (count % 10) + '0';
                    count /= 10;
                }

                // Reverse the digits in place
                // std::reverse requires iterators.
                // chars.begin() + start_of_digits points to the first digit to reverse.
                // chars.begin() + write_idx points one past the last digit to reverse.
                std::reverse(chars.begin() + start_of_digits, chars.begin() + write_idx);
            }
        }

        return write_idx; // The new length of the compressed array
    }
};
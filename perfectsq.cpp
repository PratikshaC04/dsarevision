class Solution {
public:
    bool isPerfectSquare(int num) {
         if (num < 1) {
            return false; // Perfect squares are non-negative. We are given a positive integer, so this case might not be strictly necessary based on problem constraints.
        }
        if (num == 1) {
            return true; // 1 is a perfect square (1 * 1)
        }

        // Using Binary Search
        long long low = 1;
        long long high = num; // Use long long to avoid potential overflow for mid*mid

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            } else if (square < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
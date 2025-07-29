/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
         int low = 1;
        int high = n;

        while (low <= high) {
            // Calculate mid to avoid potential integer overflow for large low and high values
            int mid = low + (high - low) / 2;

            // Call the predefined guess API
            int result = guess(mid);

            if (result == 0) {
                // We found the number!
                return mid;
            } else if (result == 1) {
                // Our guess was lower, so the picked number is higher.
                // Narrow the search space to the right half.
                low = mid + 1;
            } else { // result == -1
                // Our guess was higher, so the picked number is lower.
                // Narrow the search space to the left half.
                high = mid - 1;
            }
        }
        
        // This line should theoretically not be reached if the problem guarantees
        // a number is always picked within the 1 to n range.
        return -1;
    }
};
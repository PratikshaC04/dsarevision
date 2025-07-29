class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       int n = letters.size();
        int low = 0;
        int high = n - 1;

        // The default result if no character is found that is strictly greater than target
        // (this covers the "wrap-around" case where target is greater than or equal to
        // all characters in letters, e.g., target = 'z', letters = ['a', 'b'])
        char result = letters[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (letters[mid] > target) {
                // If letters[mid] is greater than target, it's a potential answer.
                // We store it and try to find an even smaller one in the left half.
                result = letters[mid];
                high = mid - 1;
            } else {
                // If letters[mid] is less than or equal to target, it's not our answer.
                // We need to look in the right half for a greater character.
                low = mid + 1;
            }
        }

        // After the loop, 'result' will hold the smallest character greater than 'target',
        // or letters[0] if no such character was found (due to the initial assignment).
        return result; 
    }
};
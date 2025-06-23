class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal; // 1 at positions where bits differ
        int count = 0;
        
        while (xorResult > 0) {
            count += xorResult & 1;   // Count the set bits
            xorResult >>= 1;          // Shift right to check next bit
        }
        
        return count;
    }
};

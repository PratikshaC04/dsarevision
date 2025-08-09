// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;  // First bad is at or before mid
            } else {
                left = mid + 1;  // First bad is after mid
            }
        }
        return left;  // or right (they are equal now)
    }
};

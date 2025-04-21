class Solution {
public:
    long long floorSqrt(long long n) {
        long long low = 1, high = n;
        long long ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (mid <= n / mid) { 
                ans = mid;      
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};


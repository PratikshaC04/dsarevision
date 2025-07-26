#include <vector>

class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& arr) {
        int total = 0;
        for (int num : arr) total += num;

        if (total % 3 != 0) return false;

        int target = total / 3;
        int sum = 0, count = 0;

        // We stop at arr.size() - 1 to ensure the last part is non-empty
        for (int i = 0; i < arr.size() - 1; ++i) {
            sum += arr[i];
            if (sum == target) {
                ++count;
                sum = 0;
                if (count == 2) return true; // Two parts found, third must be rest
            }
        }

        return false;
    }
};

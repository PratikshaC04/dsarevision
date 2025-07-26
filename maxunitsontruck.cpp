#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
        // Sort by units per box in descending order
        std::sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] > b[1];
        });

        int totalUnits = 0;
        for (const auto& box : boxTypes) {
            int boxesToTake = std::min(truckSize, box[0]);
            totalUnits += boxesToTake * box[1];
            truckSize -= boxesToTake;
            if (truckSize == 0) break;
        }
        return totalUnits;
    }
};

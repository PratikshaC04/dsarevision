class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // Sort both arrays to enable binary search
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int radius = 0;

        // For each house, find the closest heater
        for (int house : houses) {
            // lower_bound gives the first heater that is not less than the house
            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            // Distance to the right-side heater (if it exists)
            int distRight = (it == heaters.end()) ? INT_MAX : *it - house;

            // Distance to the left-side heater (if it exists)
            int distLeft = (it == heaters.begin()) ? INT_MAX : house - *(it - 1);

            // Minimum of the two distances is the closest heater
            int minDist = min(distLeft, distRight);

            // The result is the maximum of all minimum distances
            radius = max(radius, minDist);
        }

        return radius;
    }
};

#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    // Renamed the function to match what the error message suggests the platform expects.
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long n_squared = n * n;

        long long expected_sum = (n_squared * (n_squared + 1)) / 2;
        long long expected_sum_squares = (n_squared * (n_squared + 1) * (2 * n_squared + 1)) / 6;

        long long actual_sum = 0;
        long long actual_sum_squares = 0;

        for (const auto& row : grid) {
            for (int num : row) {
                actual_sum += num;
                actual_sum_squares += static_cast<long long>(num) * num;
            }
        }

        long long diff_sum = actual_sum - expected_sum;
        long long diff_sum_squares = actual_sum_squares - expected_sum_squares;

        long long sum_ab = diff_sum_squares / diff_sum;

        long long a = (diff_sum + sum_ab) / 2;
        long long b = (sum_ab - diff_sum) / 2;

        return {static_cast<int>(a), static_cast<int>(b)};
    }
};